#ifndef V_ROUTE_REGISTRY_H
#define V_ROUTE_REGISTRY_H

#include <Arduino.h>
#include "../v_array_list/v_array_list.h"
#include "../v_request/v_request.h"
#include "../v_response/v_response.h"
#include "../v_response/v_response.h"
#include "../v_base_controller/v_base_controller.h"

struct VRouteInfo {
    String url;
    String method;
    void (*handler)(VRequest*,VResponse*);
};

class VRouteRegistry {
private:
    static VArrayList<VRouteInfo> routes;
public:
    static void registerRoute(const String url, String method, void (*handler)(VRequest*,VResponse*));
    static void registerController(VBaseController &ctrl);
    static boolean handleRequest(String url, String method, VRequest* req, VResponse* resp);
};

#endif