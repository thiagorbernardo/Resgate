void off() {
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW); //Motor B - Lado direito
  digitalWrite(IN4, LOW);
  delay(25);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
  digitalWrite(IN2, LOW);

}

