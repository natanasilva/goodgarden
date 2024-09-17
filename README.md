# goodgarden
Este projeto consiste na criação de um sistema de irrigação automática para um jardim, utilizando um Arduino e um módulo RTC (Real Time Clock) para realizar a ativação da irrigação em horários programados. A proposta visa garantir que a irrigação ocorra de forma precisa e eficiente, evitando o desperdício de água e mantendo o solo úmido de acordo com a necessidade das plantas.

Componentes Utilizados:
Arduino Uno: Microcontrolador que gerencia todo o sistema.
Módulo RTC DS3231: Responsável por manter o relógio em tempo real, permitindo que o sistema saiba exatamente o horário, mesmo após ser desligado.
Relé: Controla a ativação e desativação da bomba de água.
Bomba de água: Executa a irrigação propriamente dita.
Sensor de Umidade do Solo (opcional): Monitora a umidade do solo, interrompendo a irrigação caso o solo já esteja suficientemente úmido.
Botão (opcional): Permite ativar manualmente a irrigação a qualquer momento.
Funcionalidades do Sistema:
Horários Programados: A irrigação é ativada automaticamente em horários fixos, como 4:30 da manhã e 16:30 da tarde. Esses horários podem ser ajustados conforme a necessidade do jardim.

Controle com Sensor de Umidade (opcional): O sensor monitora continuamente a umidade do solo. Se o solo já estiver suficientemente úmido, o sistema evita a irrigação, economizando água e evitando o encharcamento.

Irrigação Manual (opcional): Um botão físico pode ser utilizado para acionar a irrigação manualmente, a qualquer hora do dia, independentemente do horário programado.

Precisão com o Módulo RTC: O módulo RTC mantém a precisão do horário de irrigação, mesmo após uma queda de energia ou reinicialização do sistema, garantindo que o jardim seja regado no momento correto.

Benefícios do Projeto:
Automatização Total: O sistema permite uma automação completa do processo de irrigação, sem necessidade de intervenção humana.
Eficiência no Consumo de Água: A irrigação ocorre apenas nos horários programados, e o uso de sensores de umidade evita desperdícios.
Facilidade de Personalização: Horários e parâmetros podem ser ajustados facilmente de acordo com o tipo de planta ou as condições climáticas.
Este projeto é ideal para pessoas que desejam automatizar a irrigação de seus jardins, garantindo que as plantas recebam água regularmente, mesmo quando o responsável estiver ausente. Além disso, o uso de componentes como o módulo RTC proporciona precisão e confiabilidade ao sistema.
