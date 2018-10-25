// --- Commande d'un StepStick/Driver A4988 ----------------------
// DRV8825_Test.ino
//
// Commande d'un moteur pas-à-pas à l'aide d'un pilote DRV8825 avec
//     Arduino.
//
// Un projet www.mchobby.be (vente de kit et composant)
// Meurisse D. - Licence CC-SA-BY
//
// Un tutoriel http://wiki.mchobby.be/index.php?title=DRV8825
// Ou Acheter un StepStick DRV8825
//    http://shop.mchobby.be/product.php?id_product=454
//

#include <DRV8835MotorShield.h>

#define pinEnable 13 // Activation du driver/pilote
#define pinStep    9 // Signal de PAS (avancement)
#define pinDir     8 // Direction 





void setup(){
  Serial.begin(9600);
  Serial.println("Test DRV8825");
  
  pinMode( pinEnable, OUTPUT );
  pinMode( pinDir   , OUTPUT );
  pinMode( pinStep  , OUTPUT );
}






void loop(){
  int i = 0;

  digitalWrite(pinEnable, LOW);
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  
  // Avance de 200 pas
  for( i=0; i<200; i++){
    Serial.println( i );
    digitalWrite( pinStep, HIGH );
    delay( 10 );
    digitalWrite( pinStep, LOW );
    delay( 10 );
  } 
  
  // Changer de direction
  digitalWrite( pinDir   , LOW); // Direction avant
  
  // Refaire 200 pas dans l'autre sens
  for( i=0; i<200; i++){
    Serial.println( i );
    digitalWrite( pinStep, HIGH );
    delay( 1 );
    digitalWrite( pinStep, LOW );
    delay( 1 );
  } 
  
  // Pas de step et pas d'ordre... 
  //   l'axe du moteur est donc bloqué 
  Serial.println("Axe bloqué + attendre 5 sec");
  delay( 5000 );
  
  // déblocage de l'axe moteur
  Serial.println("Deblocage axe");
  digitalWrite( pinEnable, HIGH ); // logique inversée
  
  // Fin et blocage du programme
  // Presser reset pour recommander
  Serial.println("Fin de programme");
  Serial.println("Non je ne pense pas");
  
  //while( true );
}
