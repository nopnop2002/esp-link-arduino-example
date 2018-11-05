# esp-link-arduino-example

esp-link�̂��߂�Arduino�X�P�b�`   
�ڍׂ͂�����ŏЉ�Ă��܂��B   

http://nopnop2002.webcrow.jp/esp-link/esp-link-1.html   

�I���W�i���͂�����ł��B   

https://github.com/jeelabs/el-client   

�I���W�i���̊���̃T���v���́ASC16IS750(SPI-to-UART�ϊ��`�b�v)���g����UART�ʐM���s���Ă��܂��B   
���̃o�[�W�����̓n�[�h�E�F�AUART���g����esp-link�ƒʐM���܂��B

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

