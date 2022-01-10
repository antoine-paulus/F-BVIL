/*
Banc d'essai du simulateur F-BVIL
PINS UTILISÉS
- Ecran LCD : 
7   -> RS
8   -> E
9   -> D4
10  -> D5
11  -> D6
12  -> D7
- Sensor de température/humidité
13  <- DATA

DESCRIPTION
Affichage sur l'écran LCD de la température, de l'humidité et du temps de fonctionnement. 
*/

#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
static const int DHT_SENSOR_PIN = 13;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

byte avionHaut[] = {
  B11111,
  B11011,
  B11011,
  B10001,
  B01010,
  B11011,
  B10001,
  B11111
};

byte avionDroite[] = {
  B00000,
  B00100,
  B10010,
  B11111,
  B10010,
  B00100,
  B00000,
  B00000
};

byte plein[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte degre[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BANC ESSAI SIMU");
  Serial.begin(9600);
  lcd.createChar(3, avionHaut);
  lcd.createChar(2, avionDroite);
  lcd.createChar(1, plein);
  lcd.createChar(4,degre);
}

void loop() {
  float temperature;
  float humidity;
  measure_environment(&temperature, &humidity );
  if((millis()%9000)/100 == 0){
    lcd.setCursor(0,1);
    lcd.write(2);
    for (int i=1;i<16;i++){
      lcd.write(1);
    }
    for (int i=0;i<15;i++){
      lcd.setCursor(i,1);
      lcd.write(1);
      lcd.write(2);
      delay(100);
    }
    lcd.setCursor(0,1);
    lcd.print("                 ");
  }
  else if ((millis()%18000)/100 < 90){
    lcd.setCursor(6, 1);
    lcd.write(1);
    lcd.setCursor(7, 1);
    lcd.write(3);
    lcd.setCursor(8, 1);
    lcd.write(1);
    lcd.setCursor(9,1);
    if(millis()/3600000 > 9)
      lcd.setCursor(8,1);
    lcd.print(millis()/3600000);
    lcd.print(":");
    if((millis()/60000)%60 < 10)
      lcd.print("0");
    lcd.print((millis()/60000)%60);
    lcd.print(":");
    if((millis()/1000)%60<10)
      lcd.print("0");
    lcd.print((millis()/1000)%60);
  }
  else if((millis()%18000)/100 > 90){
    lcd.setCursor(0,1);
    lcd.print((int)temperature, 1 );
    lcd.write(4);
    lcd.print("C");
    lcd.setCursor(6, 1);
    lcd.write(1);
    lcd.setCursor(7, 1);
    lcd.write(3);
    lcd.setCursor(8, 1);
    lcd.write(1);
    lcd.setCursor(13,1);
    lcd.print((int)humidity, 1 );
    lcd.println( "%" );
  }
}
