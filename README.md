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

