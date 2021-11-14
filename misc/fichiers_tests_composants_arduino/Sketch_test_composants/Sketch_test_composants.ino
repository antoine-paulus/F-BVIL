#include <Servo.h>
#include <Stepper.h>
Servo mp; // crée l’objet pour contrôler le
Servo ff;
Servo tl;
Servo tr;
Servo bl;
Servo br;
Servo cluDT;
Servo cluDB;
Stepper RPM(2048, 22, 23, 24, 25);


void setup()
{
  mp.attach(3); // utilise la broche 9 pour le
  ff.attach(2);
  pinMode(4, OUTPUT); //VERT (Jeune/Orange)
  pinMode(5, OUTPUT); //ROUGE (Rouge/Marron)
  pinMode(6, OUTPUT); //Eclairage Tableau de bord
  pinMode(22, OUTPUT); 
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  tl.attach(10); //Cluster Gauche, TL
  tr.attach(7); //Cluster Gauche, TR
  bl.attach(8); //Cluster Gauche, BL
  br.attach(9); //Cluster Gauche, BR
  cluDB.attach(11);
  cluDT.attach(12);
  Serial.begin(9600);
  mp.write(0); ff.write(0); tl.write(0); tr.write(0); bl.write(0); br.write(0); cluDB.write(0); cluDT.write(0); 
}
void loop()
{
  RPM.setSpeed(10);
  int val;
  int valclu;
  RPM.step(50);
  for (int i = 0; i<180; i++){
    mp.write(i);
    val = 180*i/255;
    analogWrite(4,val);
    analogWrite(6,val);
    valclu = 66-0.37*i;
    tl.write(valclu);
    br.write(valclu);
    cluDB.write(valclu);
    delay(10);
  }
  for (int i = 180; i>0; i--){
    mp.write(i);
    val = 180*i/255;
    analogWrite(4,val);
    analogWrite(6,val);
    valclu = 66-0.37*i;
    tl.write(valclu);
    br.write(valclu);
    cluDB.write(valclu);
    delay(10);
  }
  for (int i = 0; i<180; i++){
    ff.write(180-i);
    val = 180*i/255;
    analogWrite(5,val);
    analogWrite(6,val);
    valclu = 66-0.37*i;
    tr.write(valclu);
    bl.write(valclu);
    cluDT.write(valclu);
    delay(10);
  }
  for (int i = 180; i>0; i--){
    ff.write(180-i);
    val = 180*i/255;
    analogWrite(5,val);
    analogWrite(6,val);
    valclu = 66-0.37*i;
    tr.write(valclu);
    bl.write(valclu);
    cluDT.write(valclu);
    delay(10);
  }
  //delay(1000);
} 
