// Horario        IN1 5V        IN2  GND
//                   HIGH           LOW
// Anti Horario   IN1 GND       IN2 5V
//                   LOW           HIGH
// Freio             IN1 5V        IN2  5V
//                   HIGH           HIGH
#define LDR_ONE A2
#define LDR_TWO A1
#include <Ultrasonic.h>
#define PIN_TRIG 31
#define PIN_ECHO 30
//Variaveis dos voids
int Error;
int Error_Anterior;
float Motor_A;
float Motor_B;
int Kp;
int Kd;
float PD;
int PWM;
int Leitura;
//PWM
int ENA = 2 ; int ENB = 7;
//Motores DC na ponte H

int IN1 = 3; int IN2 = 4; int IN3 = 5; int IN4 = 6;

//Sensores TCRT5000, suas portas digitais

int tcrtD0 = 12; int tcrtD1 = 11; int tcrtD2 = 10; int tcrtD3 = 9; int tcrtD4 = 8;
//Extras
Ultrasonic Desvio(PIN_TRIG, PIN_ECHO);
void setup()
{
  Serial.begin(9600);
  //Define os pinos da Ponte H
  pinMode(ENA, OUTPUT);  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);  pinMode(IN2, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(LDR_ONE, INPUT); pinMode(LDR_TWO, INPUT);
  //Define as entradas digitais
  pinMode(tcrtD0, INPUT); pinMode(tcrtD1, INPUT); pinMode(tcrtD2, INPUT); pinMode(tcrtD3, INPUT); pinMode(tcrtD4, INPUT);
}

void loop()
{
  long Dist_1 = Desvio.Ranging(CM);
  delay(1);
  long Dist_2 = Desvio.Ranging(CM);
  delay(1);
  long Dist_3 = Desvio.Ranging(CM);
  delay(1);
  long Dist_T = (((Dist_1) + (Dist_2) + (Dist_3)) / 3 );
  delay(1);
  Serial.println(Dist_1);
  if (Dist_T > 5) {
    // 63  PARA 8 E 5
    // 80 PARA 11 E 7
    leitura_cor();
    //Read_sensores();
    PWM = 80;
    int P = Error;
    int D = Error - Error_Anterior;
    //--------------------------------------------
    Kp = 16; // Ganho Proporcional //8
    Kd = 12; // Ganho Derivativo  //5
    PD = (Kp * P) + (Kd * D); // Calculo PD
    Error_Anterior = Error;
    Motor_A = (PWM) + PD;
    Motor_B = (PWM) - PD;
    //--------------------------------------------
    if ((Leitura == 1 ||  Leitura == 2)) { // Leitura == 3
      Read_sensores();
      if ( Leitura == 1 ) {
        off();
        delay(300);
        analogWrite(ENA, 120);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 120);
        digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
        digitalWrite(IN2, HIGH);
        delay(300);
        Serial.println("Lendo Verde na esquerda e girando");
        Read_sensores();
      } else {
        off();
        delay(300);
        analogWrite(ENA, 120);
        digitalWrite(IN3, LOW); //Motor B - Lado direito
        digitalWrite(IN4, HIGH);
        delay(25);
        analogWrite(ENB, 120);
        digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
        delay(300);
        Serial.println("Lendo Verde na direita e girando");
        Read_sensores();
      }
    } else {
      Read_sensores();
      if (Error  == 0 || Error  == 1 || Error  == -1 || Error == 2 || Error == -2) {
        analogWrite(ENA, Motor_B);
        digitalWrite(IN3, LOW); //Motor B - Lado direito
        digitalWrite(IN4, HIGH);
        delay(25);
        analogWrite(ENB, Motor_A);
        digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
        digitalWrite(IN2, HIGH);
        Serial.println("frente");
      } else if ( Error == 5 || Error == 4 || Error == 3) {
        Serial.println("Apenas girando para a direita");
        analogWrite(ENA, 120);
        digitalWrite(IN3, LOW); //Motor B - Lado direito
        digitalWrite(IN4, HIGH);
        delay(25);
        analogWrite(ENB, 120);
        digitalWrite(IN1, HIGH); //Motor A - Lado esquerdo
        digitalWrite(IN2, LOW);
      } else if ( Error == -5 || Error == -4 || Error == -3) {
        Serial.println("Apenas girando para a esquerda");
        analogWrite(ENA, 120);
        digitalWrite(IN3, HIGH); //Motor B - Lado direito
        digitalWrite(IN4, LOW);
        delay(25);
        analogWrite(ENB, 120);
        digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
        digitalWrite(IN2, HIGH);
      }
    }
  } else {
    Right();
    delay(2000);
    Front();
    delay(3000);
    Left();
    delay(2000);
    Front();
    delay(4000);
    Left();
    delay(2000);
    Front();
    delay(3000);
    Right();
    delay(1000);
  }
}
