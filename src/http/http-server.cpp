#include <WebServer.h>
#include <services/led-service.h>
#include <helpers/serializers/json-serializer.h>

WebServer server(80);

void onTurnOnLed() {
    String arg = server.arg("pinNumber"); 
    uint8_t pinNumber = atoi (arg.c_str ());  
    turnOnLed(pinNumber);
    server.send(200);
}

void onTurnOffLed() {
    String arg = server.arg("pinNumber");
    Serial.println(arg);
    uint8_t pinNumber = atoi(arg.c_str());
    turnOffLed(pinNumber);
}

void setupRouting() {
  server.on("/turnOnLed", onTurnOnLed);
  server.on("/turnOffLed", onTurnOffLed);
  //server.on("/post", HTTP_POST, handlePost);
}

void initHttpServer() {
    setupRouting();
    server.begin();
}

void handleClient() {
    server.handleClient();
}
// void handleGetWithResponse() {
//   server.send(200, "application/json", body);
// }

// void handlePost() {
//   if (server.hasArg("plain") == false) {
//     //handle error here
//   }
//   String body = server.arg("plain");

//   deserializeBody(body);
  
//   server.send(200, "application/json", "{}");
// }
