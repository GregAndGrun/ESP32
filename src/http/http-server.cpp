#include <WebServer.h>
#include <services/led-service.h>
#include <helpers/serializers/json-serializer.h>

WebServer server(80);

void onTurnOnLed() {
    turnOnLed();
    server.send(200);
}

void onTurnOffLed() {
    turnOffLed();
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