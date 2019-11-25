void Front() {
  analogWrite(ENA, 100);
  digitalWrite(IN3, LOW); //Motor B - Lado direito
  digitalWrite(IN4, HIGH);
  delay(25);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
  digitalWrite(IN2, HIGH);
}
