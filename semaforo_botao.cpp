// C++ code com POO e botão liga/desliga 

class Semaforo {
private:
  int pinoVermelho;
  int pinoAmarelo;
  int pinoVerde;
  int pinoBotao;
  int tempoVermelho;
  int tempoAmarelo;
  int tempoVerde;
  bool sistemaLigado;
  bool estadoBotaoAnterior;
  unsigned long tempoInicio;
  int estadoAtual; // 0=vermelho, 1=verde, 2=amarelo

public:
  // Construtor
  Semaforo(int pVermelho, int pAmarelo, int pVerde, int pBotao) {
    pinoVermelho = pVermelho;
    pinoAmarelo = pAmarelo;
    pinoVerde = pVerde;
    pinoBotao = pBotao;
    tempoVermelho = 6000; // 6 segundos
    tempoAmarelo = 2000;  // 2 segundos
    tempoVerde = 4000;    // 4 segundos
    sistemaLigado = false;
    estadoBotaoAnterior = HIGH;
    tempoInicio = 0;
    estadoAtual = 0;
  }

  // Método para inicializar os pinos
  void inicializar() {
    pinMode(pinoVermelho, OUTPUT);
    pinMode(pinoAmarelo, OUTPUT);
    pinMode(pinoVerde, OUTPUT);
    pinMode(pinoBotao, INPUT_PULLUP);
    desligarTodasLuzes();
  }

  // Método para verificar o botão (detecta pressionamento)
  void verificarBotao() {
    bool estadoBotaoAtual = digitalRead(pinoBotao);
    
    // Detecta quando o botão é pressionado (transição de HIGH para LOW)
    if (estadoBotaoAnterior == HIGH && estadoBotaoAtual == LOW) {
      delay(50); // Debounce
      sistemaLigado = !sistemaLigado; // Inverte o estado
      
      if (!sistemaLigado) {
        desligarTodasLuzes();
      } else {
        // Reinicia o ciclo quando liga
        tempoInicio = millis();
        estadoAtual = 0;
      }
    }
    
    estadoBotaoAnterior = estadoBotaoAtual;
  }

  // Método para desligar todas as luzes
  void desligarTodasLuzes() {
    digitalWrite(pinoVermelho, LOW);
    digitalWrite(pinoAmarelo, LOW);
    digitalWrite(pinoVerde, LOW);
  }

  // Método para executar o ciclo completo do semáforo SEM delay()
  void executarCiclo() {
    if (!sistemaLigado) return;
    
    unsigned long tempoDecorrido = millis() - tempoInicio;
    
    // Estado 0: Vermelho (6 segundos)
    if (estadoAtual == 0) {
      digitalWrite(pinoVermelho, HIGH);
      digitalWrite(pinoVerde, LOW);
      digitalWrite(pinoAmarelo, LOW);
      
      if (tempoDecorrido >= tempoVermelho) {
        estadoAtual = 1;
        tempoInicio = millis();
      }
    }
    // Estado 1: Verde (4 segundos)
    else if (estadoAtual == 1) {
      digitalWrite(pinoVermelho, LOW);
      digitalWrite(pinoVerde, HIGH);
      digitalWrite(pinoAmarelo, LOW);
      
      if (tempoDecorrido >= tempoVerde) {
        estadoAtual = 2;
        tempoInicio = millis();
      }
    }
    // Estado 2: Amarelo (2 segundos)
    else if (estadoAtual == 2) {
      digitalWrite(pinoVermelho, LOW);
      digitalWrite(pinoVerde, LOW);
      digitalWrite(pinoAmarelo, HIGH);
      
      if (tempoDecorrido >= tempoAmarelo) {
        estadoAtual = 0; // Volta para o vermelho
        tempoInicio = millis();
      }
    }
  }

  // Método para verificar se o sistema está ligado
  bool estaLigado() {
    return sistemaLigado;
  }
};

// Criação do objeto semáforo (pinos: vermelho=2, amarelo=4, verde=7, botão=8)
Semaforo semaforo(2, 4, 7, 8);

void setup() {
  semaforo.inicializar();
}

void loop() {
  semaforo.verificarBotao();
  semaforo.executarCiclo();
}