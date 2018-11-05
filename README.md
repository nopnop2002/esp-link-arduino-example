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

Upload esp-link firmware to ESP8266.   
esp-link firmware is here.   
https://github.com/jeelabs/esp-link   

Upload example sketch to Arduino.   

Connect ESP8266 to Arduino via standard UART.   
|ESP8266||Arduino|
|:-:|:-:|:-:|
|TXd|--|RXd|
|RXd|--|TXd|
|GND|--|GND|

Connect ESP8266 using telnet.   

