## 🚦 Projeto Semáforo com Arduino

&nbsp; Este projeto apresenta a montagem e programação de um semáforo com Arduino, utilizando três LEDs (vermelho, amarelo e verde) e um botão físico conectado a uma protoboard.  

&nbsp; O sistema simula o funcionamento real de um semáforo de trânsito, controlando o acendimento das luzes de forma sequencial, temporizada e interativa.

---

## Demonstração em Vídeo

**Semáforo funcionando (modo simples):**  
[Vídeo do semáforo funcionando](./assets/semaforo.mp4)

**Semáforo com botão liga/desliga:**  
[Vídeo do semáforo funcionando com o botão](./assets/semaforo_botao.mp4)

---

## Descrição Geral

&nbsp; O Semáforo com Botão Liga/Desliga é uma evolução do projeto de semáforo simples, desenvolvido com o microcontrolador Arduino UNO.  

&nbsp; O sistema utiliza três LEDs — vermelho, amarelo e verde — conectados a uma protoboard para simular o funcionamento real de um semáforo de trânsito.  

&nbsp; A principal diferença deste projeto é a adição de um botão físico que permite ligar e desligar o sistema. Quando pressionado, o botão pausa completamente o funcionamento (todas as luzes se apagam). Ao pressionar novamente, o semáforo reinicia o ciclo a partir do sinal vermelho, retomando o funcionamento normal.  

&nbsp; O código foi desenvolvido em C++ utilizando Programação Orientada a Objetos (POO), o que facilita a leitura, manutenção e expansão do projeto.  

&nbsp; A temporização das luzes é feita com a função `millis()`, substituindo o uso de `delay()` para evitar bloqueios e permitir a leitura contínua do botão.  

&nbsp; Essa abordagem torna o sistema mais eficiente e realista, permitindo futuras melhorias como sensores de presença, controle por pedestres ou integração com sistemas IoT.


## Estrutura do Repositório

```
semaforo_simples
├── README.md
├── documentacao.md
├── semaforo_botao.cpp
├── assets/
│   ├── semaforo_tinkercad.png
│   ├── semaforo.mp4
│   ├── semaforo_botao.mp4
└── avaliacoes.md
```

---

## Autor

**Nome:** Isabel Montenegro  
**Curso:** Engenharia de Software  
**Instituição:** Instituto de Tecnologia e Liderança  
**Ano:** 2025  
