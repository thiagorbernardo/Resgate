// CÃƒÆ’Ã‚Â³digo para leitura dos sensores e quantificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o do erro.
// 0 0 1 1 1 --> Error = 5
// 0 0 0 0 1 --> Error = 4
// 0 0 0 1 1 --> Error = 3
// 0 0 0 1 0 --> Error = 2
// 0 0 1 1 0 --> Error = 1
// 0 0 1 0 0 --> Error = 0
// 0 1 1 0 0 --> Error = -1
// 0 1 0 0 0 --> Error = -2
// 1 1 0 0 0 --> Error = -3
// 1 0 0 0 0 --> Error = -4
// 1 1 1 0 0 --> Error = -5
//---------------------------------------------------------
void Read_sensores()
{
  int Sensor_1 = digitalRead(tcrtD0); int Sensor_2 = digitalRead(tcrtD1);
  int Sensor_3 = digitalRead(tcrtD2); int Sensor_4 = digitalRead(tcrtD3);
  int Sensor_5 = digitalRead(tcrtD4);
//  Serial.print(Sensor_1); Serial.print("  "); Serial.print(Sensor_2); Serial.print("  ");
//  Serial.print(Sensor_3); Serial.print("  "); Serial.print(Sensor_4); Serial.print("  ");
//  Serial.print(Sensor_5); Serial.println("  ");
//   delay(300);

  if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 1) && (Sensor_4 == 1) && (Sensor_5 == 1)) {
    Error = 5;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 0) && (Sensor_4 == 0) && (Sensor_5 == 1)) {
    Error = 4;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 0) && (Sensor_4 == 1) && (Sensor_5 == 1)) {
    Error = 3;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 0) && (Sensor_4 == 1) && (Sensor_5 == 0)) {
    Error = 2;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 1) && (Sensor_4 == 1) && (Sensor_5 == 0)) {
    Error = 1;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 0) && (Sensor_3 == 1) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = 0;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 1) && (Sensor_3 == 1) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = -1;
  }
  else if ((Sensor_1 == 0) && (Sensor_2 == 1) && (Sensor_3 == 0) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = -2;
  }
  else if ((Sensor_1 == 1) && (Sensor_2 == 1) && (Sensor_3 == 0) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = -3;
  }
  else if ((Sensor_1 == 1) && (Sensor_2 == 0) && (Sensor_3 == 0) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = -4;
  }
  else if ((Sensor_1 == 1) && (Sensor_2 == 1) && (Sensor_3 == 1) && (Sensor_4 == 0) && (Sensor_5 == 0)) {
    Error = -5;
  }

  else if ((Sensor_1 == 1) && (Sensor_2 == 1) && (Sensor_3 == 1) && (Sensor_4 == 1) && (Sensor_5 == 1)) { // FIM DA LINHA
    Error = 4;
  }
  else if ((Sensor_1 == 1) && (Sensor_2 == 0) && (Sensor_3 == 1) && (Sensor_4 == 0) && (Sensor_5 == 0)) { // erros
    Error = 0;
  }
}





