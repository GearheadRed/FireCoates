int leftin = 1;  // Left signal wire connected to pin A1
int rightin = 3; // Right signal wire connected to pin A3
int brakein = 5; // Brake signal wire connected to pin A5
boolean brake = false;   // Brake ON initialized as false
int signalSensitivity = 128; // Sensitivity to line being energized or not(lower number more sensitive)
String lastSent = "LL"; // Last value sent(initialized as lights ON)
String leftout = "L";  // Left blinker check results(initialized as light OFF)
String rightout = "L"; // Right blinker check results(initialized as light OFF)

void setup() {
  pinMode(leftin, INPUT);   // Pin A1 as INPUT
  pinMode(rightin, INPUT);  // Pin A3 as INPUT
  pinMode(brakein, INPUT);  // Pin A5 as INPUT
  Serial.begin(9600);       // Start serial communication at 9600bps
}

void loop() {
  // Determine if brake light is ON or OFF
  if ( analogRead(brakein) > signalSensitivity )
  {
    leftout = "H"; // Setting left as High
    rightout = "H"; // Setting right as High
    brake = true; // Setting Brake ON as true
  }
  else
  {
    leftout = "L"; // Setting  left as Low
    rightout = "L"; //Setting left as low
    brake = false; // Setting Brake ON as false
  }
  // Determine if left blinker is ON or OFF
  if ( analogRead(leftin) > signalSensitivity ) // If leftin meets our signalSensitivity threshold
  {
    if ( brake ) // If brake is true(ON)
    {
      leftout = "L"; // Set left as Low
    }
    else // If brake is false(OFF) but signalSensitivity threshold met(Left ON)
    {
      leftout = "H"; // Set left as High
    }
  }
  else if ( !brake ) // If leftin does not meet the signalSensitivity threshold and brake is false(OFF)
  {
    leftout = "L"; // Set left as Low
  }
  // Determine if right binker is ON or OFF
  if ( analogRead(rightin) > signalSensitivity ) // If rightin meets our signalSensitivity threshold
  {
    if ( brake ) // If brake is true(ON)
    {
      rightout = "L"; // Set right as Low
    }
    else // If brake is false(OFF) but signalSensitivity threshold met(Right ON)
    {
      rightout = "H"; // Set right as High
    }
  }
  else if ( !brake ) // If rightin does not meet the signalSensitivity threshold and brake is false(OFF)
  {
    rightout = "L"; // Set right as Low
  }
  
  if ( lastSent != leftout + rightout ) // If current signals do not match what was last sent, send updated signals
  {
    Serial.print(leftout + rightout + '\n');  // Send signal to receiving unit
    lastSent = leftout + rightout; // Update lastSent with what we just sent to the receiving unit
  }
  delay(10); // Wait 10 nanoseconds before looping
} 

