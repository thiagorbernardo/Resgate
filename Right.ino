void Right() {
  off();
  analogWrite(ENA, 120);
  digitalWrite(IN3, HIGH); //Motor B - Lado direito
  digitalWrite(IN4, LOW);
  delay(25);
  analogWrite(ENB, 120);
  digitalWrite(IN1, LOW); //Motor A - Lado esquerdo
  digitalWrite(IN2, HIGH);
}

//96

