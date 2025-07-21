#include <WiFi.h>

const char* ssid = "Galaxy A51 7729"; // Name of the WiFi network
const char* password = "ukcb9557"; // Password for the network

WiFiServer server(80); // Server on port 80

#define LED_BUILTIN 2 // Most ESP32 boards have built-in LED on GPIO2

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  // Create Access Point
  Serial.println("Setting up Access Point...");
  WiFi.softAP(ssid, password);
  
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Send HTTP response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            // HTML web page
            client.print("<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.print("<style>body { font-family: Arial; text-align: center; margin: 0px auto; padding-top: 30px; }");
            client.print(".button { background-color: #4CAF50; border: none; color: white; padding: 15px 32px; text-align: center;");
            client.print("text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; }");
            client.print(".button2 {background-color: #f44336;}</style></head>");
            client.print("<body><h1>ESP32 LED Control</h1>");
            client.print("<p><a href=\"/H\"><button class=\"button\">LED ON</button></a></p>");
            client.print("<p><a href=\"/L\"><button class=\"button button2\">LED OFF</button></a></p>");
            client.print("</body></html>");
            
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        
        // Check client request
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);
        }
      }
    }
    
    client.stop();
    Serial.println("Client disconnected.");
  }
}