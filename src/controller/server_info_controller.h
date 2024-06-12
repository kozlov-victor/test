
#include <Arduino.h>
#include <Preferences.h>
#include "../server/v_base_controller/v_base_controller.h"
#include "../server/v_route_registry/v_route_registry.h"
#include "../server/v_request/v_request.h"
#include "../server/v_response/v_response.h"
#include "../server/v_hash_table/v_hash_table.h"

class ServerInfoController: public VBaseController {
public: 
    void initRoutes() {
        VRouteRegistry::registerRoute("/server/info","POST",[](VRequest* req, VResponse* resp){
            VHashTable<String> result;
            result.put("success","1");
            result.put("runtime",String(__DATE__)+ " " + String(__TIME__));
            resp->writeJson(result);
        });
    }
};