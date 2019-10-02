

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

