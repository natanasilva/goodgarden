# Sistema de Irrigação Automática com Arduino e Módulo RTC

Este projeto implementa um sistema de **irrigação automática** para jardins, utilizando um **Arduino** e um **módulo RTC (Real Time Clock)** para acionar a irrigação em horários programados. Ele foi projetado para operar de forma eficiente, ativando a bomba de água apenas nos momentos desejados e, opcionalmente, levando em conta a umidade do solo.

## Funcionalidades

- **Irrigação Programada**: O sistema ativa a irrigação automaticamente nos horários definidos (ex.: 4:30 da manhã e 16:30 da tarde).
- **Controle de Umidade (Opcional)**: Utiliza um sensor de umidade do solo para verificar a necessidade de irrigação e evitar o uso desnecessário de água.
- **Irrigação Manual (Opcional)**: Um botão físico permite iniciar a irrigação manualmente a qualquer momento.
- **Módulo RTC**: Garante a precisão dos horários, mesmo em casos de reinicialização ou perda de energia.

## Componentes Necessários

- **Arduino Uno** ou qualquer placa compatível
- **Módulo RTC DS3231** para controle de horário
- **Relé** para controlar a bomba de água
- **Bomba de água**
- **Sensor de umidade do solo** (opcional)
- **Botão** para controle manual (opcional)
- Jumpers e cabos de conexão
- Fonte de alimentação para o Arduino e a bomba de água

## Como Funciona

1. O **RTC DS3231** mantém o horário atualizado, mesmo que o sistema seja desligado ou reinicializado.
2. Nos horários programados (4:30 e 16:30), o sistema ativa a bomba de água por um período de **30 minutos**.
3. Se houver um **sensor de umidade** conectado, o sistema verificará o nível de umidade antes de iniciar a irrigação.
4. Um **botão manual** pode ser utilizado para iniciar a irrigação a qualquer momento. A bomba permanecerá ligada por 30 minutos.
5. O sistema utiliza a função `millis()` para controlar o tempo da irrigação, evitando o uso de `delay()` para garantir que outras funcionalidades, como leitura de sensores, continuem funcionando durante a irrigação.

## Esquemático de Conexões

- **RTC DS3231**:
  - SDA → A4 (Arduino Uno)
  - SCL → A5 (Arduino Uno)
  - VCC → 5V
  - GND → GND
- **Relé**:
  - IN → Pino 7 (ou outro pino digital)
  - VCC → 5V
  - GND → GND
  - Relé com a bomba de água em circuito externo
- **Sensor de Umidade** (opcional):
  - VCC → 5V
  - GND → GND
  - Sinal → A0
- **Botão** (opcional):
  - Um pino → Pino 8 (ou outro pino digital)
  - Outro pino → GND

## Código

O código completo pode ser encontrado [aqui](./codigo_arduino.ino). Siga as instruções abaixo para fazer o upload:

1. Conecte o Arduino ao computador via cabo USB.
2. Abra o arquivo `.ino` no Arduino IDE.
3. Selecione a placa correta (por exemplo, Arduino Uno) e a porta serial.
4. Clique em **Upload** para carregar o código na placa.

## Como Usar

1. Configure os horários de irrigação no código. Por padrão, o sistema ativa a irrigação às **4:30** e **16:30**.
2. Ajuste o valor de umidade mínima, caso esteja utilizando o sensor de umidade, para definir quando a irrigação deve ser ativada.
3. Se desejar, conecte o botão para ativação manual da irrigação.
4. Após carregar o código no Arduino, o sistema estará pronto para controlar a irrigação do jardim automaticamente.

## Personalização

- Para alterar os horários de irrigação, modifique as linhas onde os horários são verificados:
  ```cpp
  if ((now.hour() == 4 && now.minute() == 30) || (now.hour() == 16 && now.minute() == 30)) {
      // Lógica de irrigação
  }
