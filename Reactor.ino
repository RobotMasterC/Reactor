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

  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);
  pinMode(BUT4, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED3, HIGH);
  delay(1000);
  digitalWrite(LED4, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  delay(500);



}

void loop() {

  if (r < 8) {
    int ACT = random(1, 5);
    if (ACT == 1) {
      unsigned long start = millis();
      digitalWrite(LED1, HIGH);
      while (millis() - start < 200) {
        if (digitalRead(BUT1) == HIGH) {
          s++;
        }
      }
      digitalWrite(LED1, LOW);
    }
    if (ACT == 2) {
      unsigned long start = millis();
      digitalWrite(LED2, HIGH);
      while (millis() - start < 200) {
        if (digitalRead(BUT2) == HIGH) {
          s++;
        }
      }
      digitalWrite(LED2, LOW);
    }
    if (ACT == 3) {
      unsigned long start = millis();
      digitalWrite(LED3, HIGH);
      while (millis() - start < 200) {
        if (digitalRead(BUT3) == HIGH) {
          s++;
        }
      }
      digitalWrite(LED3, LOW);
    }
    if (ACT == 4) {
      unsigned long start = millis();
      digitalWrite(LED4, HIGH);
      while (millis() - start < 200) {
        if (digitalRead(BUT4) == HIGH) {
          s++;
        }
      }
      digitalWrite(LED4, LOW);
    }
    delay(random(1000, 3000));
    r++;
       
  }
  if (s == 2 || s == 3) {
    digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    delay(100);
    s = 0;
  }
  if (s == 4 || s== 5) {
    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
    delay(100);
    s = 0;

  }
  if (s == 6 || s == 7) {
    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED3, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(100);
    s = 0;

  }
  if (s == 8) {
    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED4, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(100);
    s = 0;
    

  }
  if (r >= 8 && digitalRead(BUT1) == HIGH) {
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED4, HIGH);
    delay(1000);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(500);
    r = 0;
    s = 0;
  }



}
