const int motorPin = 13;

const unsigned long initialSleepTimeInSeconds = 12600;
const unsigned long minimumSteadyStateDelayInSeconds = 1800;
const unsigned long maximumSteadyStateDelayInSeconds = 3000;
const unsigned long vibrationTimeInSeconds = 1;
const unsigned long initializationSignalVibrationTimeInSeconds = 1;

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  // Vibrate to signal it is on
  InitializationSignal(initializationSignalVibrationTimeInSeconds);
  // Initial sleep
  delay(1000 * initialSleepTimeInSeconds);
  
  // Enter steady state
  while(true) // forever
  {
    Vibrate();
    unsigned long waitTimeInSeconds = random(minimumSteadyStateDelayInSeconds,
       maximumSteadyStateDelayInSeconds);
    delay(1000 * waitTimeInSeconds);
  }
}

void Vibrate()
{
  digitalWrite(motorPin, HIGH);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, LOW);
}

void InitializationSignal(unsigned long vibrationTimeInSeconds)
{
  digitalWrite(motorPin, HIGH);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, LOW);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, HIGH);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, LOW);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, HIGH);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, LOW);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, HIGH);
  delay(1000 * vibrationTimeInSeconds);
  digitalWrite(motorPin, LOW);
}
