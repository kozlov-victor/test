#include "src/server/v_server/v_server.h"
#include "src/server/v_route_registry/v_route_registry.h"
#include "src/server/v_request/v_request.h"
#include "src/server/v_response/v_response.h"
#include "src/server/static/static.h"
#include <Preferences.h>
#include "src/server/v_hash_table/v_hash_table.h"

VServer vServer("Lanet_200","Oracle_db12",80,true);

void setup() {
    Serial.begin(115200);
    vServer.setup();
    VRouteRegistry::registerRoute("/","GET",[](VRequest* req, VResponse* resp){
        resp->writeText(static_index_html.mime,static_index_html.content);
    });
    VRouteRegistry::registerRoute("/out/index.js","GET",[](VRequest* req, VResponse* resp){
        resp->writeText(static_index_js.mime,static_index_js.content);
    });
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

void loop(){
    vServer.listenToNextClient();
}