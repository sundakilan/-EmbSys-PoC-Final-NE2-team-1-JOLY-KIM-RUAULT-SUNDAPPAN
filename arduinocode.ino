/* Utilisation du capteur Ultrason HC-SR04 
 int trig = 7;            12
int echo = 6;              11
 
 
Branchement capteur rfid

RST:9
MISO:12
MOSI:11
SCK:13
NSS:10


branchement Servomoteur
port 2


*/

#include <SPI.h> // La Bibliotheque necessaire pour le RFID (Serial Peripheral Interface) #include <RFID.h> // La Bibliotheque RFID
#include <RFID.h> // La Bibliotheque RFID
#include <Servo.h>// Bibliotheque pour le servomoteur
/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;


int trig = 3; 
int echo = 2; 
long lecture_echo; 
long cm;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

RFID rfid(10,9);





void setup() 
{ 
  // Ultrason
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 

 

  //RFID
  SPI.begin(); 
  rfid.init();

  //Servomoteur
 monServomoteur.attach(7); 

 //LED
 pinMode(5,OUTPUT);//Led verte
 pinMode(4,OUTPUT);//Led rouge


}
 
void loop() 
{ 



  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); // envoi d'une impulsion sur trig de 10 microsecondes
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; // lecture_echo*340/(2*10000)
  //Serial.print("Distance en cm : "); 
  //Serial.println(cm); 
  delay(1000); 


  if (cm < 20)
  {
  
   digitalWrite(4, HIGH);
   
 
  
   if (rfid.isCard()) //Test si une carte est presente
      {
        
       
        if(rfid.readCardSerial()) // Pour lire la carte 
        {
          for(int i = 0; i < sizeof(rfid.serNum); i++ ) // Parcours tous les nombres de la carte 
              {
                Serial.print(rfid.serNum[i]); // Affiche le numero de la carte
                Serial.print("."); 
              }

                digitalWrite(4, LOW);
                digitalWrite(5, HIGH);
                Serial.println(""); // Retour a la ligne }
                rfid.halt(); // Cloture la prise d'information }
                delay(500); 
         }

      
        
         
         // Fait bouger le bras de 0° à 180°
        for (int position = 0; position <= 180; position++) 
          {
          monServomoteur.write(position);
          delay(1);
           }


  

     
          delay (5000);
          digitalWrite(4, LOW);
         // Fait bouger le bras de 180° à 10°
        for (int position = 180; position >= 0; position--)
            {
              monServomoteur.write(position);
              delay(1);

            }

           digitalWrite(5, LOW);





  

  
}
  }
  
else { digitalWrite(4, LOW);}
      }
