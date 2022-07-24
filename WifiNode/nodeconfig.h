#ifndef NODECONFIG_H
#define NODECONFIG_H

#include <ESPmDNS.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <SD.h>
#include <SD_MMC.h>
#include <FS.h>
#include <EEPROM.h>
#include "SPIFFS.h"

#include "cmdfifo.h"
#include "gcodefifo.h"
#include "crc8.h"
#include "FiberPunk_SSD1306.h"

#define VERSION "2022-7-24"
#define DBG_OUTPUT_PORT Serial
#define PRINTER_PORT Serial
#define PC_PORT Serial1
#define RED_LED 26
#define GREEN_LED 25
#define BLUE_LED 27

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

enum OP_STATUS
{
  P_IDEL=0, 
  PRINTING=1,
  PAUSE=2,
  RECOVER=3,
  CANCLE=4,
  HEEATING=5,
};

enum ERROR_CODE
{
  NORMAL=0,
  OPEN_FAILED=1,
};

extern AsyncWebServer server;
extern AsyncEventSource events;
// extern HTTPClient http_client;
extern AsyncClient socket_client;
extern CRC8 gcrc;

extern File uploadFile;

extern String cf_ssid;
extern String cf_password;
extern String cf_node_name;
extern unsigned int cf_filament;
extern String total_layers;
extern String current_layers;
extern String current_temp;
extern String current_bed_temp;
extern String pc_ipaddress;
extern String current_file;
extern OP_STATUS g_status;
extern ERROR_CODE g_error;

extern bool time_out;



extern bool hasSD;
extern bool recv_ok;
extern bool recvl_ok;
extern bool recv2_ok;
extern bool rst_usb;
extern bool paused_for_user;
extern bool paused_for_filament;

extern uint8_t printer_sd_type;
extern uint8_t last_power_status;
extern uint8_t cmd_length;
extern uint8_t reset_sd_559;
extern uint8_t print_start_flag;

extern unsigned char current_usb_status;
extern unsigned char pre_usb_status;

extern void sendCaptureImage(String);
extern void sendHttpMsg(String);
extern void writeLog(String);
extern void saveCurrentPrintStatus(String status_str);
extern String getValue(String data, char separator, int index);
extern void Write_String(int a,int b,String str);
extern uint8_t lastPowerOffPrinting();
class NodeConfig
{
public:
    NodeConfig();
};

#endif // NODECONFIG_H
