// Ligar lampada e ventilador com aplicativo + botões 
// App desenvolvido por Michael Moraes Sabino
// Trillobit3sIndieGames
// Lógica HIGH e LOW corretas tanto no código quanto no aplicativo.

//'a' para ligar a lâmpada.
//'b' para desligar a lâmpada.
//'c' para ligar o ventilador.
//'d' para desligar o ventilador.
//'e' para desligar tudo.
//'f' para ligar tudo.

int LeituraBluetooth;
int lampadaVermelha = 8; // Porta para a lâmpada
int ventilador = 11; // Porta para o ventilador
int botaolampadaVermelha = 2; // Botão para a lâmpada
int botaoventilador = 4; // Botão para o ventilador

bool estadoLampada = false; // Estado da lâmpada
bool estadoVentilador = false; // Estado do ventilador

void setup() 
{
  pinMode(lampadaVermelha, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(botaolampadaVermelha, INPUT_PULLUP); // Botão com pull-up interno
  pinMode(botaoventilador, INPUT_PULLUP); // Botão com pull-up interno
  Serial.begin(9600);
}

void loop() 
{
  // Verifica se o botão da lâmpada foi pressionado
  if (digitalRead(botaolampadaVermelha) == LOW) // Botão pressionado
  {
    estadoLampada = !estadoLampada; // Alterna o estado
    digitalWrite(lampadaVermelha, estadoLampada ? HIGH : LOW); // Altera a lógica
    delay(300); // Debounce
  }

  // Verifica se o botão do ventilador foi pressionado
  if (digitalRead(botaoventilador) == LOW) // Botão pressionado
  {
    estadoVentilador = !estadoVentilador; // Alterna o estado
    digitalWrite(ventilador, estadoVentilador ? HIGH : LOW); // Altera a lógica
    delay(300); // Debounce
  }

  // Lógica Bluetooth
  if (Serial.available() > 0)
  {
    LeituraBluetooth = Serial.read();

    // Função para alternar o estado da lâmpada vermelha via Bluetooth
    if (LeituraBluetooth == 'a') // Liga a lâmpada
    {
      estadoLampada = true;
      digitalWrite(lampadaVermelha, HIGH); // Lógica de ligação
    }
    else if (LeituraBluetooth == 'b') // Desliga a lâmpada
    {
      estadoLampada = false;
      digitalWrite(lampadaVermelha, LOW); // Lógica de desligamento
    }

    // Função para alternar o estado do ventilador via Bluetooth
    if (LeituraBluetooth == 'c') // Liga o ventilador
    {
      estadoVentilador = true;
      digitalWrite(ventilador, HIGH); // Lógica de ligação
    }
    else if (LeituraBluetooth == 'd') // Desliga o ventilador
    {
      estadoVentilador = false;
      digitalWrite(ventilador, LOW); // Lógica de desligamento
    }

    // Função para desligar tudo via Bluetooth
    if (LeituraBluetooth == 'e')
    {
      estadoLampada = true;
      estadoVentilador = true;
      digitalWrite(lampadaVermelha, HIGH); // Liga a lâmpada
      digitalWrite(ventilador, HIGH); // Liga o ventilador
    }
    // Função para ligar tudo via Bluetooth
    else if (LeituraBluetooth == 'f')
    {
      estadoLampada = false;
      estadoVentilador = false;
      digitalWrite(lampadaVermelha, LOW); // Desliga a lâmpada
      digitalWrite(ventilador, LOW); // Desliga o ventilador
    }
  }
}


/*
//usar este com alunos
//ligar lampada e ventilador apenas com aplicativo
//lógica invertida no HIGH e LOW
//App desenvolvido por Michael Moraes Sabino
// Trillobit3sIndieGames

int LeituraBluetooth;
int lampadaVermelha = 8;
int ventilador = 11;

void setup() 
{
  pinMode(lampadaVermelha, OUTPUT);
  pinMode(ventilador, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    LeituraBluetooth = Serial.read();


    //funcao para ligar e desligar a lampada vermelha
    if(LeituraBluetooth == 'a')
    {
      digitalWrite(lampadaVermelha, LOW);
    }
    else if(LeituraBluetooth == 'b')
    {
      digitalWrite(lampadaVermelha, HIGH);
    }

    //funcao para ligar e desligar a lampada verde
    if(LeituraBluetooth == 'c')
    {
      digitalWrite(ventilador, LOW);
    }
    else if(LeituraBluetooth == 'd')
    {
      digitalWrite(ventilador, HIGH);
    }

    //funcao para ligar e desligar tudo
    if(LeituraBluetooth == 'e')
    {
      digitalWrite(lampadaVermelha, LOW);
      digitalWrite(ventilador, LOW);  
    }
    else if(LeituraBluetooth == 'f')
    {
      digitalWrite(lampadaVermelha, HIGH);
      digitalWrite(ventilador, HIGH);
    }
  }
}*/


/*
//ligar lampada e ventilador com aplicativo + botões
// App desenvolvido por Michael Moraes Sabino
// Trillobit3sGamesIndie
//lógica invertida no HIGH e LOW

//'a' para ligar a lâmpada.
//'b' para desligar a lâmpada.
//'c' para ligar o ventilador.
//'d' para desligar o ventilador.
//'e' para desligar tudo.
//'f' para ligar tudo.

int LeituraBluetooth;
int lampadaVermelha = 8; // Porta para a lâmpada
int ventilador = 11; // Porta para o ventilador
int botaolampadaVermelha = 2; // Botão para a lâmpada
int botaoventilador = 4; // Botão para o ventilador

bool estadoLampada = false; // Estado da lâmpada
bool estadoVentilador = false; // Estado do ventilador

void setup() 
{
  pinMode(lampadaVermelha, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(botaolampadaVermelha, INPUT_PULLUP); // Botão com pull-up interno
  pinMode(botaoventilador, INPUT_PULLUP); // Botão com pull-up interno
  Serial.begin(9600);
}

void loop() 
{
  // Verifica se o botão da lâmpada foi pressionado
  if (digitalRead(botaolampadaVermelha) == LOW) // Botão pressionado
  {
    estadoLampada = !estadoLampada; // Alterna o estado
    digitalWrite(lampadaVermelha, estadoLampada ? LOW : HIGH);
    delay(300); // Debounce
  }

  // Verifica se o botão do ventilador foi pressionado
  if (digitalRead(botaoventilador) == LOW) // Botão pressionado
  {
    estadoVentilador = !estadoVentilador; // Alterna o estado
    digitalWrite(ventilador, estadoVentilador ? LOW : HIGH);
    delay(300); // Debounce
  }

  // Lógica Bluetooth
  if (Serial.available() > 0)
  {
    LeituraBluetooth = Serial.read();

    // Função para alternar o estado da lâmpada vermelha via Bluetooth
    if (LeituraBluetooth == 'a') // Liga a lâmpada
    {
      estadoLampada = true;
      digitalWrite(lampadaVermelha, LOW);
    }
    else if (LeituraBluetooth == 'b') // Desliga a lâmpada
    {
      estadoLampada = false;
      digitalWrite(lampadaVermelha, HIGH);
    }

    // Função para alternar o estado do ventilador via Bluetooth
    if (LeituraBluetooth == 'c') // Liga o ventilador
    {
      estadoVentilador = true;
      digitalWrite(ventilador, LOW);
    }
    else if (LeituraBluetooth == 'd') // Desliga o ventilador
    {
      estadoVentilador = false;
      digitalWrite(ventilador, HIGH);
    }

    // Função para desligar tudo via Bluetooth
    if (LeituraBluetooth == 'e')
    {
      estadoLampada = true;
      estadoVentilador = true;
      digitalWrite(lampadaVermelha, LOW); // Liga a lâmpada
      digitalWrite(ventilador, LOW); // Liga o ventilador
    }
    // Função para ligar tudo via Bluetooth
    else if (LeituraBluetooth == 'f')
    {
      estadoLampada = false;
      estadoVentilador = false;
      digitalWrite(lampadaVermelha, HIGH); // Desliga a lâmpada
      digitalWrite(ventilador, HIGH); // Desliga o ventilador
    }
  }
}*/