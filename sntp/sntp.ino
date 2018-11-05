/**
 * Simple example to get time from esp-link
 */

#include <ELClient.h>
#include <ELClientCmd.h>
#include <TimeLib.h>      // https://github.com/PaulStoffregen/Time

// Initialize a connection to esp-link using the normal hardware serial port both for
// SLIP and for debug messages. Esp-link will show the debug messages in the uC console
// because they are not SLIP framed.
//ELClient esp(&Serial, &Serial); // for DEBUG
ELClient esp(&Serial);


// Initialize CMD client (for GetTime)
ELClientCmd cmd(&esp);

// Timer value to last print 
uint32_t last;
// Flag for wifi connection
boolean wifiConnected = false;

// Callback made from esp-link to notify of wifi status changes
// Here we just print something out for grins
void wifiCb(void* response) {
  ELClientResponse *res = (ELClientResponse*)response;
  if (res->argc() == 1) {
    uint8_t status;
    res->popArg(&status, 1);

    if(status == STATION_GOT_IP) {
      Serial.println("WIFI CONNECTED");
      wifiConnected = true;
    } else {
      Serial.print("WIFI NOT READY: ");
      Serial.println(status);
      wifiConnected = false;
    }
  }
}

// dow_char() 曜日文字を戻す [Sun,Mon....]
char * dow_char_EN(byte days) {
  char *you[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  return you[days];
}

 // dow_char() 曜日文字を戻す [日曜,火曜....]
char * dow_char_JP(byte days) {
  char *you[] = {"日曜","月曜","火曜","水曜","木曜","金曜","土曜"};
  return you[days];
}

// dow() 曜日を示す数値を戻す[0-Sunday, 1-Monday etc.]
uint8_t dow(unsigned long t) {
    return ((t / 86400) + 4) % 7;
}

void showTime(char * title, time_t timet, char * dow) {
   Serial.print(title);
   Serial.print(year(timet));
   Serial.print("/");
   Serial.print(month(timet));
   Serial.print("/");
   Serial.print(day(timet));
   Serial.print(" ");
   Serial.print(hour(timet));
   Serial.print(":");
   Serial.print(minute(timet));
   Serial.print(":");
   Serial.print(second(timet));
   Serial.print(" [");
   Serial.print(dow);
   Serial.println("]");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Start Setup");
  
  // Sync-up with esp-link, this is required at the start of any sketch and initializes the
  // callbacks to the wifi status change callback. The callback gets called with the initial
  // status right after Sync() below completes.
  esp.wifiCb.attach(wifiCb); // wifi status change callback, optional (delete if not desired)
  bool ok;
  do {
    ok = esp.Sync();      // sync up with esp-link, blocks for up to 2 seconds
    if (!ok) Serial.println("EL-Client sync failed!");
  } while(!ok);
  Serial.println("EL-Client synced!");

  // Wait for WiFi to be connected. 
  esp.GetWifiStatus();
  ELClientPacket *packet;
  Serial.print(F("Waiting for WiFi "));
  if ((packet=esp.WaitReturn()) != NULL) {
    Serial.print(F("."));
    Serial.println(packet->value);
  }
  Serial.println("");
  
  last = millis();
}


void loop() {
  esp.Process();

  // if we're connected, get UNIX time from esp-link
  if(wifiConnected) {
    if ((millis()-last) > 5000) {
      Serial.println("requesting time");
      uint32_t epoch = cmd.GetTime();
      Serial.print("Unix time : "); Serial.println(epoch);
  
      // 日本標準時間
      uint8_t DayOfWeek = dow(epoch); 
      showTime("Current time is ", epoch, dow_char_JP(DayOfWeek));
      last = millis();
    }
  } else {
    // This is just for demo, you can as well just try to reconnect
    // and setup the connection to esp-link again 
    Serial.println(F("Lost WiFi connection, try to reboot"));
    delay(10000);
    asm volatile ("  jmp 0");
  }
}
