#include <Arduino.h>
#include "../server/v_base_controller/v_base_controller.h"
#include "../server/v_route_registry/v_route_registry.h"
#include "../server/v_request/v_request.h"
#include "../server/v_response/v_response.h"
#include "../server/static/static.h"

class StaticController: public VBaseController {
public: 
    void initRoutes() {
        VRouteRegistry::registerRoute("/","GET",[](VRequest* req, VResponse* resp){
            resp->writeBuffer(assets_index_html.mime,assets_index_html.buff,assets_index_html.size);
        });
        VRouteRegistry::registerRoute("/out/index.js","GET",[](VRequest* req, VResponse* resp){
            resp->writeBuffer(assets_index_js.mime,assets_index_js.buff,assets_index_js.size);
        });
        VRouteRegistry::registerRoute("/assets/icon.png","GET",[](VRequest* req, VResponse* resp){
            resp->writeBuffer(assets_icon_png.mime,assets_icon_png.buff,assets_icon_png.size);
        });
    }
};