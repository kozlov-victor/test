#ifndef V_ROUTE_REGISTRY_H
#define V_ROUTE_REGISTRY_H

#include <Arduino.h>
#include "../v_array_list/v_array_list.h"
#include "../v_response/v_response.h"

struct VRouteInfo {
    String url;
    String method;
    void (*handler)(VResponse*);
};

class VRouteRegistry {
private:
    static VArrayList<VRouteInfo> routes;
public:
    static void registerRoute(const String url, String method, void (*handler)(VResponse*));
    static boolean handleRequest(String url, String method, VResponse* resp);
};

#endif