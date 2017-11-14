//HC-06 AT COMMAND
//AT               // OK
//AT+NAMEJOY2      // Name=JOY2
//AT+VERSION       // panfpunr
//AT+BAUD4         // Baud=9600
//AT+ROLE          // not support
//AT+ADDR          // not support
//AT+PSWD          // not support
//AT+UART          // not support
// Bluetooth AT Command 傳送 kah 接收。
//愛考慮,試用! 序列視窗下腳 e (沒有行結尾) 選項。
//配對密碼:1234
//CTRL+SHIFT+M : 啟動序列窗
//CTRL+M : 上傳

#ifndef SS_SOFTWARE_SERIAL
#define SS_SOFTWARE_SERIAL
#include <SoftwareSerial.h>
#endif

enum { UnoBoard_Rx = 8, UnoBoard_Tx = 9, Baud = 9600 };

// UnoBoardRx <===> Bluetooth_Tx
SoftwareSerial BtObject(UnoBoard_Rx, UnoBoard_Tx);

void setup() {

  Serial.begin(Baud);
  BtObject.begin(Baud);

  /*
  delay(1000);
  Serial.println(
    String("Baud=") +
    String(Baud) +
    String(",OnBoard-RX=") +
    String(UnoBoard_Rx) +
    String(",OnBoard-TX=") +
    String(UnoBoard_Tx)
  ); // MAXIMUM SerialBuffer 64 bytes!
  */
  
}


//-----------------------------
void loop() {

  int SerialCount = Serial.available();
  if ( SerialCount > 0 ) {
    for ( int sx = 0 ; sx < SerialCount; sx++ ) {
      char c=Serial.peek();
      if (  '+' == c || isUpperCase(c) || '\n' == c || '\r' == c ){ //AT+ Validation
        BtObject.write( Serial.read() ); // ReadFromSerial WriteToBluetooth
      }
      else {
        char ic=Serial.read(); //read whatever
        Serial.println( String("Invalid character:")+String(ic) );  
      }
    }
    
    return;
  }

  // ReadFromBluetooth WriteToSerial
  while ( BtObject.available() ) {
    Serial.write( BtObject.read() );
    Serial.flush();
  }

}


