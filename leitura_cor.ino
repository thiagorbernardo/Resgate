void leitura_cor() {
  int RLDR_Left = analogRead(LDR_ONE);
  int RLDR_Right = analogRead(LDR_TWO);
  int RLDR_Mode_Left;
  int RLDR_Mode_Right;
//  Serial.print("LDR1  ");
//  Serial.print(RLDR_Left);
//  Serial.print(" LDR2  ");
//  Serial.println(RLDR_Right);
//  Serial.print("");
//  delay(200);
    if (RLDR_Left > 385 && RLDR_Left < 420) {
      RLDR_Mode_Left = 1;
    } else {
      RLDR_Mode_Left = 0;
    }
    if (RLDR_Right > 440 && RLDR_Right < 465) {
      RLDR_Mode_Right = 1;
    } else {
      RLDR_Mode_Right = 0;
    }
  
    if ((RLDR_Mode_Left == 1) && (RLDR_Mode_Right == 0)) { // Caso o LDR da ESQUERDA esteja no verde e o da DIREITA nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o
      Leitura = 1;
      Serial.println("Esquerda");
    }
    else if ((RLDR_Mode_Left == 0) && (RLDR_Mode_Right == 1)) { // Caso o LDR da DIREITA esteja no verde e o da ESQUERDA nÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o
      Leitura = 2;
      Serial.println("Direita");
    }
    else if ((RLDR_Mode_Left == 0) && (RLDR_Mode_Right == 0)) { // Caso AMBOS estejam no verde
      Leitura = 3;
      Serial.println("NENHUM");
    }

}
//Esquerda:
// Preto: < 300
// Branco: > 560
// Verde escuro: 350   400
// Verde claro: 410  440
//Direita:
//Preto: < 400
//Branco: > 600
// Verde escuro:  410  460
//Verde  claro:  450 500




