#include <Arduino.h>
#include "../v_array_list/v_array_list.h"
#include "../v_request/v_request.h"
#include "../v_response/v_response.h"
#include "./v_route_registry.h"

// Визначення статичного члена класу
VArrayList<VRouteInfo> VRouteRegistry::routes;

void VRouteRegistry::registerRoute(String url, String method, void (*handler)(VRequest*,VResponse*)) {
    VRouteRegistry::routes.add({url, method, handler});
}

boolean VRouteRegistry::handleRequest(String url, String method, VRequest* req, VResponse* resp) {
    Serial.println("handling request: " + url + " (" + method + ")");
    for (size_t i=0;i<VRouteRegistry::routes.size();i++) {
        VRouteInfo route = VRouteRegistry::routes.getAt(i);
        if (url==route.url && method==route.method) {
            route.handler(req,resp);
            return true;
        }
    }
    return false;
}