 #include "setting.h"
 #include"function.h"

void setup() {
  Serial.begin(9600);
  //serial speed
  WiFi.mode(WIFI_STA);
  //WiFi.disconnect();
  //Initialize ESP-NOW:
  if (esp_now_init() != 0) {
    while (1) {
      Serial.println("Error initializing ESP-NOW");
    }
    return;
  }
  //if esp now now not connect print ans while
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  esp_now_register_recv_cb(OnDataRecv);
  //esp now setting
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

void loop() {
  if (Read_Fan() <= 0.1 && EN1 == HIGH) {
    //Serial.println("fan is off");
    digitalWrite(relay, HIGH);
    digitalWrite(buzzer, HIGH);
    sendMesh(126, 4578);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    EN1 = LOW;
    EN2 = HIGH;
  }
  else if (Read_Fan() >= 0.8 && EN2 == HIGH) {
    //Serial.println("fan is on");
    digitalWrite(relay, LOW);
    digitalWrite(buzzer, LOW);
    sendMesh(278, 651);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    EN2 = LOW;
    EN1 = HIGH;
  }
  delay(100);
}