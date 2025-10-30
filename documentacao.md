# Documentação Técnica — Projeto Semáforo com Arduino

---

## Objetivo

&nbsp; Este documento descreve em detalhes a montagem física, o funcionamento do código e a avaliação conforme o barema do projeto **Semáforo com Arduino**.  

&nbsp; O objetivo é demonstrar o controle de saídas digitais e o uso de temporizações simples para representar o ciclo de um semáforo real.

---

## Descrição do Projeto

&nbsp; O projeto consiste em um sistema eletrônico de sinalização baseado em três LEDs controlados por um Arduino UNO.  

&nbsp; Cada LED representa uma luz do semáforo (vermelha, amarela e verde), com tempos ajustados para imitar o comportamento de um cruzamento urbano.

&nbsp; A lógica segue a seguinte ordem:


| Fase | LED | Cor | Tempo | Função |
|------|------|------|--------|----------|
| 1 | 2 | 🔴 Vermelho | 6 segundos | Indica “pare” |
| 2 | 7 | 🟢 Verde | 4 segundos | Indica “siga” |
| 3 | 4 | 🟡 Amarelo | 2 segundos | Indica “atenção” |

&nbsp; Após a última fase, o ciclo é repetido continuamente.

---

## Componentes Utilizados

| Componente | Quantidade | Especificação | Função |
|-------------|-------------|----------------|----------|
| Arduino Uno | 1 | ATmega328P | Microcontrolador do sistema |
| LED Vermelho | 1 | 5mm | Representa o sinal de parada |
| LED Amarelo | 1 | 5mm | Representa o sinal de atenção |
| LED Verde | 1 | 5mm | Representa o sinal de passagem |
| Resistores | 3 | 220 Ω | Limitar a corrente dos LEDs |
| Protoboard | 1 | - | Montagem sem solda |
| Jumpers | Vários | Macho–macho | Conexões entre os componentes |

---

## Esquema de Ligação

&nbsp; A montagem foi realizada em protoboard, de forma a facilitar testes e ajustes.

&nbsp; Cada LED é ligado a uma porta digital do Arduino, com resistores conectados em série para limitar a corrente elétrica.

**Conexões principais:**
- LED Vermelho → pino **2**
- LED Amarelo → pino **4**
- LED Verde → pino **7**
- Cátodos (perna curta) → **GND** (via resistores de 220 Ω)

<div align="center">
<sub> Semáforo Tinkercad</sub>
<img src="./assets/semaforo_tinkercad.png" width="100%">
<sup>Fonte: Material produzido pelos autores (2025)</sup>
</div>

---

## Código do Projeto

[semaforo_simples.cpp](./semaforo_simples.cpp)


## Explicação do Código

- pinMode() define os pinos digitais como saídas para controlar os LEDs.

- digitalWrite() liga (HIGH) e desliga (LOW) cada LED.

- delay() controla o tempo de duração de cada fase do semáforo em milissegundos.

O loop principal mantém o ciclo se repetindo indefinidamente.


## Conclusão

&nbsp; O projeto demonstrou o funcionamento básico de um sistema sequencial utilizando saídas digitais do Arduino.

&nbsp; Foi possível compreender conceitos de temporização, controle de LEDs e lógica sequencial, além de aplicar boas práticas de organização de circuito.

&nbsp; Esse experimento serve como base para projetos futuros mais complexos, como semáforos inteligentes com sensores ou controle de pedestres.