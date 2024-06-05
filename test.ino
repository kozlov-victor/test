#include "src/v_server/v_server.h"
#include "src/v_route_registry/v_route_registry.h"
#include "src/v_response/v_response.h"
#include "src/static/static.h"

VServer vServer("Lanet_200","Oracle_db12",80,false);

void setup() {
    Serial.begin(115200);
    vServer.setup();
    VRouteRegistry::registerRoute("/","GET",[](VResponse* resp){
        resp->writeText(static_index_html.mime,static_index_html.content);
    });
    VRouteRegistry::registerRoute("/out/index.js","GET",[](VResponse* resp){
        resp->writeText(static_index_js.mime,static_index_js.content);
    });
}

void loop(){
    vServer.listenToNextClient();
}