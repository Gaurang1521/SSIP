#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

#define buzz 6
#define ledG 2
#define ledR 3
#define relay1 4
#define relay2 5


RF24 radio(7,8);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 02;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format


void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
pinMode(ledG,INPUT);
pinMode(ledR,INPUT);

}

void loop() {
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    char taxt[32] = " ";
    network.read(header, &taxt, sizeof(taxt)); 
    Serial.println(taxt);

  if(taxt == "tank 1 ia full "){

    if (digitalRead(ledG) == HIGH){

               digitalWrite(relay1,HIGH);
               char taxt[32] = "Tank 2 is Full";
               RF24NetworkHeader header5(master00);
               char ok2 = network.write(header5, taxt, sizeof(taxt));

               
      
    }
    if (digitalRead(ledR) == LOW){

               digitalWrite(relay1,LOW);
      
    }

          
    
  }
    
    // if (header.from_node == 0) {    
    //   myservo.write(incomingData); 
    // }
    // if (header.from_node == 10) {    // If data comes from Node 012
    //   digitalWrite(led, !incomingData);  // Turn on or off the LED 02
    // }
  }
}
