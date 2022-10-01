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

class AparelhoSonoro {
 int Piezo;
  
  public: AparelhoSonoro(int piezo) {
    Piezo = piezo;
    pinMode(Piezo, OUTPUT);
  }
  
  void soarAlarme() {
    tone(Piezo, 400, 500);
  }
  
  void soarSinal() {
    tone(Piezo, 440, 500);
  }

  void desligar() {
    noTone(Piezo);
  }
};

int botao = 8;
int start = 0;
SemaforoPino MotoristaVermelho(13);
SemaforoPino MotoristaAmarelo(12);
SemaforoPino MotoristaVerde(11);
SemaforoPino PedestreVermelho(7);
SemaforoPino PedestreVerde(6);
AparelhoSonoro Som(10);

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
      Som.soarSinal();
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
    Som.soarAlarme();
  } else {
    Som.desligar();
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