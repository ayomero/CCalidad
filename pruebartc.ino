#include <LiquidCrystal.h>
// Librería para la comunicación I2C y la RTClib
#include <Wire.h>
#include <RTClib.h>

 
// Declaramos un RTC DS3231
RTC_DS3231 rtc;
LiquidCrystal lcd (7,6,5,4,3,2);
void setup () {
 Serial.begin(9600);
 lcd.begin(16,2);
 delay(1000);
 
 // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }
 
 // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 //rtc.adjust(DateTime(__DATE__, __TIME__));
}
 
void loop () {
 DateTime now = rtc.now();
 

 lcd.setCursor(0, 1); //Se ubica el cursor en la segunda línea del display
    lcd.print("Hora:  "); //Se indica que se mostrará el parámetro de la Hora
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    delay(1000);
}
