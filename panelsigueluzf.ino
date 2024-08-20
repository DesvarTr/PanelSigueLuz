#include <Stepper.h>

int pasosporvuelta = 2048;
Stepper motor(pasosporvuelta, 8, 10, 9, 11);

//int ft = 1;
int valorft = 0;
//int ft2 = 1;
int valorft2 = 0;
int limite = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(10);
  //pinMode(ft, INPUT);
  //pinMode(ft2, INPUT);
  Serial.begin(9600);

}

void loop() {

  if(Serial.available()){

    int grados = Serial.parseInt();
    int pasos = map(grados, 0, 360, 0, pasosporvuelta);
    motor.step(pasos);
    Serial.println(String(grados) + " → " + String(pasos));

  }

  valorft=analogRead(A1);
  valorft2=analogRead(A2);
  Serial.println("Fotoresistencia 1: "+String(valorft));
  Serial.println("Fotoresistencia 2: "+String(valorft2));
  delay(2000);

  if (valorft > valorft2)
  {
    if(limite < 2){
      Serial.println("Motor moviendose +");
      motor.step(200);
      limite = limite+1;
    }

    else{
      Serial.println("No ha pasado nada");
    }
  }

  else{
    if(limite > -2){
      Serial.println("Motor moviendose -");
      motor.step(-200);
      limite = limite-1;
    }
    
    else{
      Serial.println("No ha pasado nada");
    }

  }
}
