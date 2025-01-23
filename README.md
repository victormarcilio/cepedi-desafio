 # **Projeto com Raspberry Pi Pico W: Controle de Pinos por Teclado Matricial**

## **Descrição do Projeto**
**Objetivo do projeto:** Como forma de comunicação entre o usuário e o sistema embarcado, deve-se escrever comandos (conjuntos de caracteres) para serem interpretados pelo microcontrolador de modo a realizar o controle dos periféricos trabalhados. 
## **Funcionalidades**
O projeto contém um teclado matricial 4x4 que controla, ao pressionar suas teclas, um LED RGB e um Buzzer na placa Raspberry Pi Pico W. Segue a função de cada tecla:
- "r": Liga o LED vermelho
- "g": Liga o LED verde
- "b": Liga o LED azul
- "0": Desliga todos os LEDs
- "z": Ativa o buzzer por 2 segundos
- "1": Entra no modo de gravação

  ## Componentes Utilizados

### Hardware
- **Microcontrolador RP 2040**
- **Raspberry Pi Pico W**
- **LED RGB**
- **Buzzer**

### Software
- **Linguagem C**
- **IDE Visual Studio Code**
- **PuTTY**
- **Extensões do Visual Studio Code**:
  - Raspberry Pi Pico
  - CMake Tools
  - C/C++
- **Bibliotecas**:
  - `pico/stdlib`
  - `stdio`
  - `hardware/pwm`
  - `hardware/clocks`
  - `pico/bootrom"`
 
  ## **Como utilizar**
  - Clonar repositório em uma pasta separada.
  - Abrir o projeto no Visual Studio Code atráves da extensão "Raspeberry Pi Pico Project".
  - Compilar e executar o projeto.
  - Configurar e acionar o Putty.
  - Escolher uma das opções do menu, e iserir no serial.

  ## **Vídeo**
  - Link de acesso ao vídeo de funcionamento da placa: https://youtube.com/shorts/fSysB7cJeP0
