int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int BUT4 = D3;

int LED1 = D10;
int LED2 = D9;
int LED3 = D8;
int LED4 = D7;

int r = 0;
int s = 0;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  randomSeed(analogRead(A0));

  digitalWrite(LED1, HIGH); delay(1000);
  digitalWrite(LED2, HIGH); delay(1000);
  digitalWrite(LED3, HIGH); delay(1000);
  digitalWrite(LED4, HIGH); delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(500);
}

void loop() {
  if (r < 8) {
    int ACT = random(1, 5);
    unsigned long start = millis();
    bool counted = false;

    switch (ACT) {
      case 1:
        digitalWrite(LED1, HIGH);
        while (millis() - start < 200) {
          if (digitalRead(BUT1) == LOW && !counted) {
            s++;
            counted = true;
          }
        }
        digitalWrite(LED1, LOW);
        break;
      case 2:
        digitalWrite(LED2, HIGH);
        while (millis() - start < 200) {
          if (digitalRead(BUT2) == LOW && !counted) {
            s++;
            counted = true;
          }
        }
        digitalWrite(LED2, LOW);
        break;
      case 3:
        digitalWrite(LED3, HIGH);
        while (millis() - start < 200) {
          if (digitalRead(BUT3) == LOW && !counted) {
            s++;
            counted = true;
          }
        }
        digitalWrite(LED3, LOW);
        break;
      case 4:
        digitalWrite(LED4, HIGH);
        while (millis() - start < 200) {
          if (digitalRead(BUT4) == LOW && !counted) {
            s++;
            counted = true;
          }
        }
        digitalWrite(LED4, LOW);
        break;
    }

    delay(random(1000, 3000));
    r++;
  }

  if (r >= 8) {
    if (s == 2 || s == 3) {
      digitalWrite(LED1, HIGH); delay(500);
      digitalWrite(LED1, LOW); delay(100);
    } else if (s == 4 || s == 5) {
      digitalWrite(LED1, HIGH); delay(100);
      digitalWrite(LED2, HIGH); delay(500);
      digitalWrite(LED2, LOW);
      digitalWrite(LED1, LOW); delay(100);
    } else if (s == 6 || s == 7) {
      digitalWrite(LED1, HIGH); delay(100);
      digitalWrite(LED2, HIGH); delay(100);
      digitalWrite(LED3, HIGH); delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW); delay(100);
    } else if (s == 8) {
      digitalWrite(LED1, HIGH); delay(100);
      digitalWrite(LED2, HIGH); delay(100);
      digitalWrite(LED3, HIGH); delay(100);
      digitalWrite(LED4, HIGH); delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW); delay(100);
    }
  }
}  
