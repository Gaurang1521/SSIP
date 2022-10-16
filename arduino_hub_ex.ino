#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
unsigned long button = 2;
#define led 3
#define buzz 4
RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node02 = 02;


void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(button, INPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  network.update();
//===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
 unsigned long buttonState = digitalRead(button);
  RF24NetworkHeader header2(node01);
  bool ok = network.write(header2, &buttonState, sizeof(buttonState)); 
   if (incomingData = "Tank 1 is Full"){
    RF24NetworkHeader header3(node02);
   char ok1 = network.write(header2, incomingData, sizeof(incomingData));
   }
   else if(incomingData == "Tank 2 is Full"){

          tone(buzz,1000);
          delay(5000);
          
    
   }
   } 
  }
  
  
// char taxt1[32]="gaurang";
//  RF24NetworkHeader header2(node01);     // (Address where the data is going)
//  bool ok = network.write(header2, &taxt1, sizeof(taxt1));
//  char taxt[32] ="Parth"; // Send the data
//  RF24NetworkHeader header3(node02);     // (Address where the data is going)
//  bool ok1 = network.write(header3, &taxt, sizeof(taxt));
//   // LED Control at Node 012
//   unsigned long buttonState = digitalRead(button);
//   RF24NetworkHeader header4(node012);    // (Address where the data is going)
//   bool ok3 = network.write(header4, &buttonState, sizeof(buttonState)); // Send the data

//   // LEDs control at Node 022
//   unsigned long pot2Value = analogRead(A1);
//   RF24NetworkHeader header3(node022);    // (Address where the data is going)
//   bool ok2 = network.write(header3, &pot2Value, sizeof(pot2Value)); // Send the data
// }
