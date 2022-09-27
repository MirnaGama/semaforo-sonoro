class SemaforoPino {
  int Luz;

  public:
 SemaforoPino(int luz)
 {
  Luz = luz;
  pinMode(Luz, OUTPUT);
 }

 void ligar()
 {
  digitalWrite(Luz, HIGH);
 }

 void desligar()
 {
  digitalWrite(Luz, LOW);
 }
 
  boolean estaLigado() {
    return (digitalRead(Luz) == HIGH);
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
    MotoristaVerde.desligar();
    MotoristaAmarelo.ligar();
    delay(1000);
    MotoristaAmarelo.desligar();
    MotoristaVermelho.ligar();
}

void abrirParaPedestre() {
  PedestreVermelho.desligar();
  for (int i = 0; i < 10; i++)
    {
      PedestreVerde.ligar();
      tone(som, 440, 500);
      delay(1000);
    }
}

void abrirParaMotorista() {
   MotoristaVermelho.desligar();
   MotoristaVerde.ligar();
}

void fecharParaPedestre() {
   PedestreVerde.desligar();
   PedestreVermelho.ligar();
}

void loop()
{

   MotoristaVermelho.desligar();
   MotoristaVerde.ligar();
   PedestreVermelho.ligar();

  int presenca = analogRead(A0);

  if (presenca > 0 && MotoristaVerde.estaLigado() == true) {
    tone(som, 400, 500);
  }
  
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