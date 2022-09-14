int botao = 8;
int carrovermelho = 13;
int carroamarelo = 12;
int carroverde = 11;
int pedestrevermelho = 7;
int pedestreverde = 6;
int som = 10;
int start = 0;

void setup()
{
  pinMode(botao, INPUT);
  pinMode(carrovermelho, OUTPUT);
  pinMode(carroamarelo, OUTPUT);
  pinMode(carroverde, OUTPUT);
  pinMode(pedestrevermelho, OUTPUT);
  pinMode(pedestreverde, OUTPUT);
  pinMode(som, OUTPUT);
}

void loop()
{
  digitalWrite(carroverde, LOW);
  digitalWrite(pedestrevermelho, HIGH);

  start = digitalRead(botao);

  if (start == HIGH)
  {
    digitalWrite(carroverde, LOW);
    digitalWrite(carroamarelo, HIGH);
    delay(1000);
    digitalWrite(carroamarelo, LOW);
    digitalWrite(carrovermelho, HIGH);
    
    delay(2000);

    for (int i = 0; i < 10; i++)
    {
      digitalWrite(pedestrevermelho, LOW);
      digitalWrite(pedestreverde, HIGH);
      tone(som, 440, 500);
      delay(1000);
    }

    for (int y = 0; y < 5; y++)
    {
      digitalWrite(pedestreverde, LOW);
      tone(som, 440, 500);
      digitalWrite(pedestrevermelho, HIGH);
      delay(500);
      digitalWrite(pedestrevermelho, LOW);
      delay(500);
    }

    digitalWrite(pedestrevermelho, HIGH);
    delay(3000);

    digitalWrite(carrovermelho, LOW);
    digitalWrite(carroverde, HIGH);

    delay(15000);
  }
}