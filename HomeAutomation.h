/*
 * HomeAutomation.h
 *
 *  Created on: 02.05.2016
 *      Author: admin
 */
#ifndef SRC_HOMEAUTOMATION_H_
#define SRC_HOMEAUTOMATION_H_


#include <stdbool.h>
#include <string.h>
#include <msp430.h>
#include <stdbool.h>
#include "ESP8266.h"
#include "messagetype.h"
#include "System.h"
#include "uart.h"
#include "general.h"


//#define SSID	"Verizon-SM-G900V-FA09"
//#define PASSWORD "4wordsalluppercase"

//WLAN Accesspoint setup
//#define SSID	"Steps"
//#define PASSWORD "4wordsalluppercase"

////bei Jan
//#define SSID "EasyBox-50AC42"
//#define PASSWORD "Fr9hd6Vd3"

//#define SSID "HTC-Manuel"
//#define PASSWORD "matterhorn25"

//#define SSID "pi3_AP"
//#define PASSWORD "12345678"

//#define SSID "DELL-WIFI"
//#define PASSWORD "12345678"

//#define SSID "Link_WLAN"
//#define PASSWORD "cisco10102"

#define SSID "FRITZ!Box 7430 XA"
#define PASSWORD "12127221480285609194"


//TCP Server SETUP
//#define SERVER_IP "192.168.1.11"
#define SERVER_IP "192.168.178.2"
#define SERVER_PORT	3000


#define MAC 			"FF:FF:FF:FF:FF:FF"
#define DEFAULT_ALIAS 	"Spot Gallerie"
#define TYPE			"Proto-1"

void homeAutomation_init(ESP8266_t* esp_ptr);

void disconnectedTcp();

bool isRegisteredAtServer();

void sendMessage(ESP8266_t* esp_ptr, MessageType type, char* payload);

void sendIdentMessage(ESP8266_t* esp_ptr, char alias[], char mac[], char type[]);


void sendStateChangeNotification();

void parseReceivedData(char* received);

MessageType parseProtokollHeader(char* received, char returnPayload[]);

void parseMessage(MessageType type, char payload[]);

void homeAutomation_update();

void switchState(bool state);

bool getSwitchState();

void esp_update(ESP8266_t* esp_ptr);

extern char identMessagePayload[50];

#endif /* SRC_HOMEAUTOMATION_H_ */