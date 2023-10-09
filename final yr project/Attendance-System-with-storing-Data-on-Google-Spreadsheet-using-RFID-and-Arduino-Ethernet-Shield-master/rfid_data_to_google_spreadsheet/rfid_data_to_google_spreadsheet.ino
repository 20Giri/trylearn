
/* Arduino Code which sends data to google spreadsheet */

#include<SPI.h>
#include<MFRC522.h>
#include <Ethernet.h>

#include <LiquidCrystal.h>
#define SS_PIN 4 //FOR RFID SS PIN BECASUSE WE ARE USING BOTH ETHERNET SHIELD AND RS-522
#define RST_PIN 9
#define No_Of_Card 3
const int rs =19 , en =18 , d4 = 17, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };   //00:AA:BB:CC:DE:02
char server[] = "api.pushingbox.com";   //YOUR SERVER
IPAddress ip(192, 168, 43, 87);
EthernetClient client;     
MFRC522 rfid(SS_PIN,RST_PIN);
MFRC522::MIFARE_Key key; 
byte id[No_Of_Card][4]={
  {253,89,83,67},            //RFID NO-1
  {114,82,205,46},             //RFID NO-2
  {114,180,43,46}              //RFID NO-3
};
byte id_temp[3][3];
byte i;
int j=0;
int buzzer=7;


// the setup function runs once when you press reset or power the board
void setup(){
    Serial.begin(9600);
    lcd.begin(16, 2);
    pinMode(buzzer,OUTPUT);
    SPI.begin();
    rfid.PCD_Init();
    for(byte i=0;i<6;i++)
    {
      key.keyByte[i]=0xFF;
    }
    if (Ethernet.begin(mac) == 0) {
      Serial.println("Failed to configure Ethernet using DHCP");
      Ethernet.begin(mac, ip);
    }
    delay(1000);
    Serial.println("connecting...");
     }

// the loop function runs over and over again forever
void loop(){
  digitalWrite(buzzer,HIGH);
  lcd.setCursor(0, 0);
    int m=0;
    if(!rfid.PICC_IsNewCardPresent())
    return;
    if(!rfid.PICC_ReadCardSerial())
    return;
    for(i=0;i<4;i++)
    {
     id_temp[0][i]=rfid.uid.uidByte[i]; 
               delay(50);
    }
    digitalWrite(buzzer,LOW);
    delay(10);
     for(i=0;i<No_Of_Card;i++)
    {
            if(id[i][0]==id_temp[0][0])
            {
              if(id[i][1]==id_temp[0][1])
              {
                if(id[i][2]==id_temp[0][2])
                {
                  if(id[i][3]==id_temp[0][3])
                  {
                    Serial.print("your card no :");
                    lcd.write(1);
          
                    for(int s=0;s<4;s++)
                    {
                     
                     Serial.print(rfid.uid.uidByte[s]);
                     lcd.print(rfid.uid.uidByte[s]);
                      Serial.print(" ");
                      lcd.print(" ");
                     
                    }
                    Serial.println("\nValid Person");
                    lcd.setCursor(0, 1);
                                      lcd.print("\nValid Person");
                    
                    Sending_To_spreadsheet();
                    j=0;
                              
                              rfid.PICC_HaltA(); rfid.PCD_StopCrypto1();   return; 
                  }
                }
              }
            }
     else
     {j++;
      if(j==No_Of_Card)
      {
        Serial.println("Invalid Person");
        lcd.clear();
      lcd.print("InValid Person");
                    
        Sending_To_spreadsheet();
        j=0;
      }
     }
    }
    
       // Halt PICC
    rfid.PICC_HaltA();
  
    // Stop encryption on PCD
    rfid.PCD_StopCrypto1();
    
 }

 void Sending_To_spreadsheet()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client.print("GET /pushingbox?devid=v37EE162D7B974EA&allowed_members=");     //YOUR URL
    if(j!=No_Of_Card)
    {
      client.print('1');
//      Serial.print('1');
    }
    else
    {
      client.print('0');
    }
    
    client.print("&Member_ID=");
    for(int s=0;s<4;s++)
                  {
                    client.print(rfid.uid.uidByte[s]);
                                  }
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: api.pushingbox.com");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }

 
