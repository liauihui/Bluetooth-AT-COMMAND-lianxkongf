/*
 Bluetooth AT Command 傳送 kah 接收。 
序列視窗下腳 e (沒有行結尾) 選項，愛考慮,試用 zitlex!
配對密碼:1234

...
 */

//HC-06 AT COMMAND:
//AT               // OK
//AT+NAMEJOY2      // Name=JOY2
//AT+VERSION       // panfpunr
//AT+BAUD4         // Baud=9600
//AT+ROLE          // not support
//AT+ADDR          // not support 
//AT+PSWD          // not support
//AT+UART          // not support

#ifndef SS_SOFTWARE_SERIAL
#define SS_SOFTWARE_SERIAL
#include <SoftwareSerial.h>
#endif

enum { UnoBoard_Rx=10, UnoBoard_Tx=11, Baud=9600 };
SoftwareSerial BT(UnoBoard_Rx, UnoBoard_Tx);  // Bluetooth_Tx===UnoBoard_Rx
void setup() {

  Serial.begin(Baud);
  BT.begin(Baud);

  Serial.println(
     String("Serial begin Baud=")+
     String(Baud)+
     String(" OnBoard Rx=")+
     String(UnoBoard_Rx)+
     String(" OnBoard Tx=")+
     String(UnoBoard_Tx)
     );
}

//-----------------------------
void loop() {

  while( BT.available() ){ 
    Serial.write( BT.read() );
  }

  while( Serial.available() ){
    BT.write( Serial.read() );
  }
  
}
