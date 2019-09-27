#include <Servo.h>

Servo myservo; //Variável da biblioteca que declara o Servo Motor

int distanciamaxima = 0; //Variável que receberá a posição em que o motor funcionará

int posicaocm = 0; //Variável que receberá o valor lido pelo sensor em cm

//OS COMANDOS ABAIXO SÃO EXCLUSIVOS DA BIBLIOTECA E DISPONÍVEIS PARA PESQUISA
//PODEM HAVER DECLARAÇÕES SEMELHANTES A UM CÓDIGO COMUM DO ARDUINO MAS NA BIBLIOTECA SÃO ADAPTADOS
//E TRANSFORMADAS EM FUNÇÕES MODIFICADAS PARA LEITURA DO SENSOR

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  //Define inicialmente o pino do trigger como LOW para 2ms
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  //Define o pino do trigger como HIGH para 10ms
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  //Após obter a leitura ativa o pino echo
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600); //Velocidade de leitura e escrita (default) do monitor serial
  pinMode(4, OUTPUT); //Define o pino 4 como saída
  pinMode(2, INPUT); //Define o pino 2 como entrada
}

void loop()
{
  
  distanciamaxima = 40;//Configura a distância máxima que ativará o motor

  posicaocm = 0.01723 * readUltrasonicDistance(7, 6); //Converte o valor lido pelo sensor em cm

  Serial.print(posicaocm); //Escreve a posição em cm
  Serial.println("cm"); //Informa a unidade de medida cm
  
  if (posicaocm >= distanciamaxima){ //Se a posição da mão for maior ou igual a distância máxima configurada
    delay(850); //Esperará 750ms
    myservo.attach (2); //No servo motor do pino 2
    myservo.write (0); //Escreverá 0°
  }
      
  if (posicaocm <= distanciamaxima){ //Se a posição da mão for menor ou igual a distância máxima configurada
    delay(175); //Esperará 175ms
    myservo.attach (2);  //No servo motor do pino 2
    myservo.write (90); //Escreverá 90°
  }


  delay(100); //Espera 100ms para o próximo loop
}
