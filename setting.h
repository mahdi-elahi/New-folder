 String Version = "V2.3.5";

#include <ESP8266WiFi.h>
#include <espnow.h>
//libs
#define relay 5
#define buzzer 4
#define green 13
#define red 13
#define blue 14
//const

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//spesial mac addres

const long interval = 2000;
unsigned long previousMillis = 0;
//for timer

bool EN1 = HIGH, EN2 = HIGH;