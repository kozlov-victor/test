#include <Arduino.h>
#include <Preferences.h>
#include "../server/v_base_controller/v_base_controller.h"
#include "../server/v_route_registry/v_route_registry.h"
#include "../server/v_request/v_request.h"
#include "../server/v_response/v_response.h"
#include "../server/v_hash_table/v_hash_table.h"

class CounterController: public VBaseController {
public: 
    void initRoutes() {
        VRouteRegistry::registerRoute("/preferences/cnt","GET",[](VRequest* req, VResponse* resp){
            VHashTable<String> result;
            Preferences preferences;
            preferences.begin("app", false); 
            String cnt = preferences.getString("cnt","0");
            preferences.end();
            result.put("success","1");
            result.put("cnt",cnt);
            resp->writeJson(result);
        });
        VRouteRegistry::registerRoute("/preferences/cnt","POST",[](VRequest* req, VResponse* resp){
            VHashTable<String> result;
            Preferences preferences;
            preferences.begin("app", false);
            String cnt = req->params->get("cnt");
            preferences.putString("cnt",cnt);
            preferences.end();
            result.put("success","1");
            resp->writeJson(result);
        });
    }
};