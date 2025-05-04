# DFRobotのECセンサ

## DFRobotのECセンサ

[Gravity: Analog Electrical Conductivity Sensor /Meter V2 (K=1)](https://www.dfrobot.com/product-1123.html)

これ使ってみた

ESP32で使う場合の注意点

ライブラリ

- 本家のライブラリは純Arduino用なので、ESP32用のカスタムライブラリをベースに使用
    
    [GitHub - GreenPonik/DFRobot_ESP_EC_BY_GREENPONIK: Read EC on ESP by using Gravity: Analog EC Sensor / Meter Kit V2, SKU:DFR0300](https://github.com/GreenPonik/DFRobot_ESP_EC_BY_GREENPONIK/tree/master)
    

ADCの範囲と使用可能なECの範囲

[ESP32のADC特性測定](https://lang-ship.com/blog/work/esp32-adc/)

[Analog to Digital Converter (ADC) Calibration Driver - ESP32 -  — ESP-IDF Programming Guide v5.2.1 documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/adc_calibration.html)

- ESP32のADCのリファレンス電圧は1100mVだけど、±100mvの個体差があるので補正が必要
- アッテネータによって、1100mVレンジを広げて使っている
- 11dBのアッテネータが最大レンジで3.9Vまで測定できるが、精度が悪く、正確に測定できるのは150mV~2450mVの範囲だけ(今は削除されているが以前のドキュメントに書いてある)
- そこで、これをECセンサのレンジに反映すると、1.0ms/cm~となる
    - upperは少なくとも12.8ms/cmの標準溶液で1700mV程度だったので、よっぽど濃い溶液でなければ大丈夫そう
