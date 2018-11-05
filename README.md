# esp-link-arduino-example

esp-linkのためのArduinoスケッチ   
詳細はこちらで紹介しています。   

http://nopnop2002.webcrow.jp/esp-link/esp-link-1.html   

オリジナルはこちらです。   

https://github.com/jeelabs/el-client   

オリジナルの幾つかのサンプルは、SC16IS750(SPI-to-UART変換チップ)を使ってUART通信を行っています。   
このバージョンはハードウェアUARTを使ってesp-linkと通信します。

---

Arduino example sketch for esp-link.   

The original is here.   

https://github.com/jeelabs/el-client   

Several original examples are doing UART communication using SC16IS750 (SPI-to-UART exchange chip).   
This version communicates with esp-link using hardware UART.   

---

Upload esp-link firmware to ESP8266.   
esp-link firmware is here.   
https://github.com/jeelabs/esp-link   

Connect soft_access_point of ESP8266.   
SSID is ESP_AABBCC.   
AABBCC is part of ESP8266 MAC address.

Connect WEB setting page.   
http://192.168.4.1   
Configure your real_access_point setting using web interface.   

Restart ESP8266.   

Upload example sketch to Arduino.   
If you connect to ESP8266 via UART,disconnect UART wire.   

Connect ESP8266 to Arduino via standard UART.   

|ESP8266||Arduino|
|:-:|:-:|:-:|
|TXd|--|RXd|
|RXd|--|TXd|
|GND|--|GND|

Connect IP of ESP8266 using telnet.   

Restart Arduino.   

