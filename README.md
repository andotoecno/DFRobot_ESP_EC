# ESP32 Library for DFRobot Gravity Analog Electrical Conductivity Sensor / Meter V2 (K=1)

## Overview

This library provides an interface for the DFRobot Gravity Analog Electrical Conductivity Sensor / Meter V2 (K=1) specifically tailored for the ESP32 platform.

**Important Note:** The original **V1** version of the DFRobot Gravity Analog Electrical Conductivity Sensor / Meter **only supports a 5V power supply and is therefore not directly compatible with the 3.3V operating voltage of the ESP32.** This library is designed for **V2 and later versions** of the sensor, which support a wider voltage input range, including 3.3V. Ensure you are using **V2 or a later version** for compatibility with the ESP32.

**Product Link (V2):** [Gravity: Analog Electrical Conductivity Sensor /Meter V2 (K=1)](https://www.dfrobot.com/product-1123.html)

This library adapts the functionality of the original Gravity Analog EC library, which is designed for pure Arduino, to be compatible with the ESP32 microcontroller. It builds upon the existing ESP32-compatible library developed by GreenPonik.

**Original Arduino Library:** [GitHub - DFRobot/DFRobot_EC](https://github.com/DFRobot/DFRobot_EC)
**Original ESP32 Library:** [GitHub - GreenPonik/DFRobotz_ESP_EC_BY_GREENPONIK: Read EC on ESP by using Gravity: Analog EC Sensor / Meter Kit V2, SKU:DFR0300](https://github.com/GreenPonik/DFRobot_ESP_EC_BY_GREENPONIK)


## Features
- EC Sensing Range: 1.0 ~ 12.8 mS/cm
- Measurement Accuracy: ±5% F.S.
- Probe Life: 7*24hours >0.5 years (depending on the water quality)
  - **Note:** The actual readings may vary slightly depending on the calibration values used. 
  - **Note:** While the recommended detection range is 1 to 15 mS/cm, the library's performance with EC values higher than the 12.8 mS/cm standard solution has not been fully verified.

## ESP32 ADC Considerations

Understanding the characteristics of the ESP32's Analog-to-Digital Converter (ADC) is crucial for accurate readings.

**References:**

- [ESP32 ADC characteristics (Japanese)](https://lang-ship.com/blog/work/esp32-adc/)
- [Analog to Digital Converter (ADC) Calibration Driver - ESP32 - — ESP-IDF Programming Guide v5.2.1 documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/adc_calibration.html)

**Key Points:**

- The ESP32 ADC has a nominal reference voltage of 1100mV, but individual units can vary by ±100mV, necessitating calibration for precise measurements.
- Attenuation is used to extend the measurement range beyond 1100mV.
- While the 11dB attenuation setting allows measurements up to 3.9V, the accurate measurement range is typically between 150mV and 2450mV (as indicated in previous documentation).

## Future Work

- Improve and expand the examples provided with the library.