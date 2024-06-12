#include "src/server/v_server/v_server.h"
#include "src/server/v_route_registry/v_route_registry.h"
#include "src/controller/static_controller.h"
#include "src/controller/counter_controller.h"
#include "src/controller/server_info_controller.h"

VServer vServer("Lanet_200","Oracle_db12",80,false);

StaticController staticController;
CounterController counterController;
ServerInfoController serverInfoController;

void setup() {
    Serial.begin(115200);
    vServer.setup();
    VRouteRegistry::registerController(staticController);
    VRouteRegistry::registerController(serverInfoController);
    VRouteRegistry::registerController(counterController);
}

void loop(){
    vServer.listenToNextClient();
}