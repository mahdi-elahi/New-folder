
typedef struct struct_message {
  int value1;
  int value2;
} struct_message;

struct_message Send;
struct_message Read;
// make struct for send and recive data

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&Read, incomingData, sizeof(Read));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.println(Read.value1);
  Serial.println(Read.value2);
  if (Read.value1 == 4875) {
    digitalWrite(5, HIGH);
  }
  else if (Read.value1 == 451) {
    digitalWrite(5, LOW);
  }
}
//recive function

float Read_Fan() {
  float voltage = 0;
  float value = analogRead(A0);
  voltage = (value * 1) / 1024;
  return voltage;
}
void sendMesh(int Value1, int Value2) {
  Send.value1 = Value1;
  Send.value2 = Value2;
  esp_now_send(broadcastAddress, (uint8_t *) &Send, sizeof(Send));
  delay(10);
}