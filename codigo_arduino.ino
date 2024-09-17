#include <Wire.h>
#include <RTClib.h>  // Biblioteca para RTC (DS3231)

#define sensorPin A0   // Pino do sensor de umidade do solo
#define relePin 7      // Pino do relé que controla a bomba de água
#define botaoPin 8     // Pino do botão
#define umidadeMinima 30  // Limite mínimo de umidade do solo
#define TEMPO_IRRIGACAO 1800000  // 30 minutos em milissegundos (1800 segundos) 1800000

RTC_DS3231 rtc;

bool irrigacaoAtiva = false;
unsigned long tempoInicialIrrigacao = 0;
unsigned long ultimoDebounceBotao = 0;
unsigned long debounceDelay = 50;  // 50 milissegundos para debounce
bool estadoBotaoAnterior = HIGH;   // O estado anterior do botão

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  if (!rtc.begin()) {
    Serial.println("Não foi possível encontrar o RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    // Se o RTC perdeu a alimentação, definir a data e a hora
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  pinMode(sensorPin, INPUT);
  pinMode(relePin, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP);  // Configura o botão com resistor pull-up interno

  digitalWrite(relePin, HIGH);  // Desativa a bomba inicialmente
}

void loop() {
  // Pega o horário atual
  DateTime now = rtc.now();
  
  // Lê o valor do sensor de umidade
  int umidadeSolo = analogRead(sensorPin);
  int porcentagemUmidade = map(umidadeSolo, 1023, 0, 0, 100);  // Converte o valor do sensor para porcentagem


  // Lê o estado atual do botão
  int leituraBotao = digitalRead(botaoPin);

  // Imprime no monitor serial (opcional para verificar)
  Serial.print("Umidade do solo: ");
  Serial.print(porcentagemUmidade);
  Serial.println("%");
  
  Serial.println("Horário do Arduino");
  Serial.println(now.hour());
  Serial.println(":");
  Serial.println(now.minute());


  // Verifica se o botão foi pressionado (lógica de debounce)
  if (leituraBotao != estadoBotaoAnterior) {
    ultimoDebounceBotao = millis();  // Reinicia o contador do debounce
  }

  if ((millis() - ultimoDebounceBotao) > debounceDelay) {
    // Se o botão foi pressionado (mudou de HIGH para LOW)
    if (leituraBotao == LOW && estadoBotaoAnterior == HIGH) {
      Serial.println("Botão pressionado. Ligando a bomba de água manualmente por 30 minutos...");
      iniciarIrrigacao();
    }
  }

  estadoBotaoAnterior = leituraBotao;  // Atualiza o estado anterior do botão

  // Horário para irrigação: 4:30 da manhã e 16:30 da tarde
  if ((now.hour() == 4 && now.minute() == 30) || (now.hour() == 16 && now.minute() == 30)) {
    if (porcentagemUmidade < umidadeMinima) {
      Serial.println("Umidade baixa. Ligando a bomba de água por 30 minutos...");
      iniciarIrrigacao();
    } else {
      Serial.println("Umidade adequada. Não é necessário irrigar.");
    }
  }

  // Controla o tempo de irrigação (desliga após 30 minutos)
  if (irrigacaoAtiva && (millis() - tempoInicialIrrigacao >= TEMPO_IRRIGACAO)) {
    pararIrrigacao();
  }

  delay(1000);  // Pequeno atraso para evitar leituras muito rápidas
}

// Função para iniciar a irrigação
void iniciarIrrigacao() {
  if (!irrigacaoAtiva) {  // Se a irrigação não estiver ativa
    irrigacaoAtiva = true;
    tempoInicialIrrigacao = millis();  // Registra o tempo de início da irrigação
    digitalWrite(relePin, LOW);        // Liga o relé (ativa a bomba)
    Serial.println("Bomba de água ligada.");
  }
}

// Função para parar a irrigação
void pararIrrigacao() {
  irrigacaoAtiva = false;
  digitalWrite(relePin, HIGH);  // Desliga o relé (desativa a bomba)
  Serial.println("Bomba de água desligada após 30 minutos.");
}
