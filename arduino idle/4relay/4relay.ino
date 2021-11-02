//---------------------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#define NUM_RELAY   4   // Jumlah Relay
//================================================================================================
const char ssid[]       = "wifigueee";
const char password[]   = "alhamdulillah2021";
const char web_host[]   = "172.20.10.3";
//================================================================================================
int RLY[] = {D1, D2, D3, D4};     //delralasi pin relay dalam array

StaticJsonDocument<100> doc;      //batasan pembacaan json file
WiFiClient client;
//WiFiClientSecure client;        // gunakan kalo menggunakan HTTPS

//================================================================================================
void setup() {
  delay(1000);
  Serial.begin(9600);                             //monitoring serial
  WiFi.begin(ssid, password);                     //mulai koneksi wifi

  while (WiFi.status() != WL_CONNECTED) {         //cek jika belum konek wifi maka akan menampilkan * terus menerus
    delay(500);
    Serial.print("*");
  }
  Serial.println();                               //keluar dari while karena nodemcu telah terhubung
  Serial.println("> WIFI TERHUBUNG!");            //cetak keterangan wifi terhubung pada serial monitor

  for (int i = 0; i < NUM_RELAY; i++) {           //jadikan masing-masing pin relay menjadi OUTPUT
    pinMode(RLY[i], OUTPUT);
  }
}

//================================================================================================
void loop() {
  //client.setInsecure();                         // Kalau pakek HTTPS gunakan ini
  String payload = "";                            //deklarasikan variabel penampung karakter string
  bool parse_json = false;                        
  String data[NUM_RELAY + 1];                     //data reyay ada 4 di tambahkan 1 biar aman
  if (client.connect(web_host, 80)) {             //kalau menggunakan https 80 diganti 443
    Serial.println("> CONNECT SERVER");           //konek ke server
    
    String url = "erik/api.php";                  // sesuaikan foldernya di localhost atau hosting

    client.print(String("GET /") + url + " HTTP/1.1\r\n" +
                 "Host: " + web_host + "\r\n" +
                 "Content-Type: application/json\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );
                
    while (client.connected() || client.available()) {
      if (client.available()) {
        char c = client.read();
        if (c == '[') {
          parse_json = true;
        }
        if (parse_json) {
          payload += c;
        }
      }
    }
    client.stop();
  } else {
    client.stop();
  }
  if (payload != "") {
    Serial.println(payload);
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      doc.clear();
      Serial.println("> ERROR JSON");
    } else {
      for (int i = 0; i < NUM_RELAY; i++) {
        int logika = doc[i];
        int urutan = i + 1;
        digitalWrite(RLY[i], logika);
        Serial.println("> DATA RELAY " + String(urutan) + " = " + String(logika));
      }
    }
    doc.clear();
  }
  delay(2000);
}
//================================================================================================
