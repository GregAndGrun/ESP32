#include <ArduinoJson.h>

StaticJsonDocument<250> jsonDocument;
char buffer[250];

void createJson(char *tag, float value, char *unit) { 
  jsonDocument.clear(); 
  jsonDocument["type"] = tag;
  jsonDocument["value"] = value;
  jsonDocument["unit"] = unit;
  serializeJson(jsonDocument, buffer);
}
 
void addJsonObject(char *tag, float value, char *unit) {
  JsonObject obj = jsonDocument.createNestedObject();
  obj["type"] = tag;
  obj["value"] = value;
  obj["unit"] = unit; 
}
 
void deserializeBody(String body){
     deserializeJson(jsonDocument, body);
}

