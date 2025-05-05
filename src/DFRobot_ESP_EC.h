/*
 * file DFRobot_ESP_EC.h * @ https://github.com/GreenPonik/DFRobot_ESP_EC_BY_GREENPONIK
 *
 * Arduino library for Gravity: Analog EC Sensor / Meter Kit V2, SKU: DFR0300
 *
 * Based on the @ https://github.com/DFRobot/DFRobot_EC
 * Copyright   [DFRobot](http://www.dfrobot.com), 2018
 * Copyright   GNU Lesser General Public License
 *
 * ##################################################
 * ##################################################
 * ########## Fork on github by GreenPonik ##########
 * ############# ONLY ESP COMPATIBLE ################
 * ##################################################
 * ##################################################
 *
 * version  V1.1.2
 * date  2019-06
 */

 #ifndef _DFROBOT_ESP_EC_H_
 #define _DFROBOT_ESP_EC_H_
 
 #include "Arduino.h"
 
 #define RAWEC_1413_LOW 0.70
 #define RAWEC_1413_HIGH 1.80
 #define RAWEC_276_LOW 1.95
 #define RAWEC_276_HIGH 3.2
 #define RAWEC_1288_LOW 8
 #define RAWEC_1288_HIGH 16.8
 #define EC_SENSOR_MAX_CELL_CONST 15 // Usable products are k=1 or k=10
 #define EC_SENSOR_MAX_RANGE_mscm 15 // 15ms/cm is the maximum range of the EC sensor

 #define ReceivedBufferLength_EC 10 // length of the Serial CMD buffer
 
 enum 
 {
     EC_CALIBRATION_MODE_ERROR,
     EC_CALIBRATION_MODE_READY,
     EC_CALIBRATION_MODE_RUNNING,
     EC_CALIBRATION_MODE_SAVE_AND_EXIT,
 };

 class DFRobot_ESP_EC
 {
 public:
     DFRobot_ESP_EC();
     ~DFRobot_ESP_EC();
     boolean calibration(float voltage, float temperature, int mode);
     boolean calibration_by_serial_CMD(float voltage, float temperature, char *cmd);
     boolean calibration_by_serial_CMD(float voltage, float temperature);
     float readEC(float voltage, float temperature);  // voltage to EC value, with temperature compensation
     void begin(uint16_t eeprom_start_addr); // initialization using EEPROM
     void begin(float k_low, float k_high); // initialization with direct k values
     float kvalueLow;
     float kvalueHigh;
 
 private:
     float _ecvalue;
     float _kvalue;
     float _voltage;
     float _temperature;
     float _rawEC;
 
     char _cmdReceivedBuffer[ReceivedBufferLength_EC]; // store the Serial CMD
     byte _cmdReceivedBufferIndex;
     uint16_t _eepromStartAddress;
 private:
     boolean cmdSerialDataAvailable();
     boolean ecCalibration(byte mode); // calibration process, wirte key parameters to EEPROM
     byte cmdParse(const char *cmd);
     byte cmdParse();
 };
 
 #endif
 