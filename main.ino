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

void fecharParaMotorista() {
    MotoristaVerde.DESLIGAR();
    MotoristaAmarelo.LIGAR();
    delay(1000);
    MotoristaAmarelo.DESLIGAR();
    MotoristaVermelho.LIGAR();
}

void abrirParaPedestre() {
  for (int i = 0; i < 10; i++)
    {
      PedestreVerde.LIGAR();
      tone(som, 440, 500);
      delay(1000);
    }
}

void abrirParaMotorista() {
   MotoristaVermelho.DESLIGAR();
   MotoristaVerde.LIGAR();
}

void fecharParaPedestre() {
   PedestreVerde.DESLIGAR();
   PedestreVermelho.LIGAR();
}

void loop()
{
 
   MotoristaVermelho.DESLIGAR();
   MotoristaVerde.LIGAR();
  
  start = digitalRead(botao);

  if (start == HIGH)
  {
    fecharParaMotorista();
    
    delay(2000);

    abrirParaPedestre();

    fecharParaPedestre();
  
    delay(1000);

    abrirParaMotorista();

    delay(15000);
  }
}