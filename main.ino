class SemaforoPino {
  int Luz;
  
  public:
 SemaforoPino(int luz)
 {
  Luz = luz;
  pinMode(Luz, OUTPUT);     
 }
  
 void LIGAR()
 {
  digitalWrite(Luz, HIGH);
 }   
  
 void DESLIGAR()
 {
  digitalWrite(Luz, LOW);
 } 
};

int botao = 8;
int som = 10;
int start = 0;
SemaforoPino MotoristaVermelho(13);
SemaforoPino MotoristaAmarelo(12);
SemaforoPino MotoristaVerde(11);
SemaforoPino PedestreVermelho(7);
SemaforoPino PedestreVerde(6);

void setup()
{
  pinMode(botao, INPUT);
  pinMode(som, OUTPUT);
}

void loop()
{
  
  start = digitalRead(botao);

  if (start == HIGH)
  {
    MotoristaVerde.DESLIGAR();
    MotoristaAmarelo.LIGAR();
    delay(1000);
    MotoristaAmarelo.DESLIGAR();
    MotoristaVermelho.LIGAR();
    
    delay(2000);

    for (int i = 0; i < 10; i++)
    {
      MotoristaVermelho.DESLIGAR();
      PedestreVerde.LIGAR();
      tone(som, 440, 500);
      delay(1000);
    }

    for (int y = 0; y < 5; y++)
    {
      PedestreVerde.DESLIGAR();
      tone(som, 440, 500);
      PedestreVermelho.LIGAR();
      delay(500);
      PedestreVermelho.DESLIGAR();
      delay(500);
    }

    PedestreVermelho.DESLIGAR();
    delay(3000);

    MotoristaVermelho.DESLIGAR();
    MotoristaVerde.LIGAR();

    delay(15000);
  } else {
    MotoristaVerde.DESLIGAR();
    MotoristaVermelho.LIGAR();
  }
}