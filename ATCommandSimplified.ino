//HC-06 AT COMMAND
//AT               // OK
//AT+NAMEJOY2      // Name=JOY2
//AT+VERSION       // panfpunr
//AT+BAUD4         // Baud=9600
//AT+ROLE          // not support
//AT+ADDR          // not support
//AT+PSWD          // not support
//AT+UART          // not support
//Bluetooth AT Command 傳送 kah 接收。
//愛考慮! 序列視窗下腳 e (沒有行結尾) 選項。
//配對密碼:1234
//CTRL+SHIFT+M : 啟動序列窗
//CTRL+M : 上傳

#include <SoftwareSerial.h>
int Baud = 9600;
SoftwareSerial BtObject(8, 9); // UnoBoard_Rx <===> Bluetooth_Tx

void setup() {

  Serial.begin(Baud);
  BtObject.begin(Baud);

  /*
  Serial.println(
    String("Baud=") +
    String(Baud) +
    String(",OnBoard-RX=") +
    String(UnoBoard_Rx) +
    String(",OnBoard-TX=") +
    String(UnoBoard_Tx)
  );
  delay(1000);
  */
}


//-----------------------------
void loop() {

  while( Serial.available() ) { 
    BtObject.write( Serial.read() ); // ReadFromSerial WriteToBluetooth
  }

  while ( BtObject.available() ) {
    Serial.write( BtObject.read() ); // ReadFromBluetooth WriteToSerial
  }
  
}


