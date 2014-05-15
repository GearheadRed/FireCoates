boolean stringComplete = false;  // whether the string is complete
String inputString = "";         // a string to hold incoming data
String res = "NN"; // Variable to return result data post processing
int on = 255;  // Digital pin ON pulse width
int off = 0;   // Digital pin OFF pulse width
int left = 3;  // LED connected to pin D3
int right = 6; // LED connected to pin D6

void setup() {
  pinMode(left, OUTPUT);   // Pin D3 as OUTPUT
  pinMode(right, OUTPUT);  // Pin D6 as OUTPUT
  Serial.begin(9600);      // Start serial communication at 9600bps
  inputString.reserve(10); // Set inputString reserve line length
}

void loop(){
  if (stringComplete) { // If stringComplete is true run indicatorControl
    indicatorControl(); // Calls the indicatorControl routine
    stringComplete = false; // Sets the incoming data status to false
  }
}

void serialEvent() { // If something serial related occurs this routine catches it
  while (Serial.available()) { // If there is serial data available
    char inChar = (char)Serial.read(); // get the new byte:
    if (inChar == '\n') { // Check if the incoming character is a newline
      stringComplete = true; // If yes set stringComplete to true so we know all the data is there
    }
    else {
      inputString += inChar; // If the incoming character is not a newline add it to the inputString
    }
  }
}

void indicatorControl() { // This routine handles actual light control
// Input information is handled left-right
// Using High[H](ON) or Low[L](OFF) statuses
// Eventually should switch to binary to help performance and lessen packet byte size
// Possibly make more sense as a case statement?
  if( inputString == "HH" ) // If Left and Right ON
  {
    analogWrite(left, on);    // Set Left ON
    analogWrite(right, on);   // Set Right ON
    res = "HH";               // Store results
  }
  else if( inputString == "LH" ) // If Left OFF, Right ON
  {
    analogWrite(left, off);   // Set Left OFF
    analogWrite(right, on);   // Set Right ON
    res = "LH";               // Store results
  }
  else  if( inputString == "HL" ) // If Left ON, Right OFF
  {
    analogWrite(left, on);    // Set Left ON
    analogWrite(right, off);  // Set Right OFF
    res = "HL";               // Store results
  }
  else if( inputString == "LL" ) // If Left and Right OFF
  {
    analogWrite(left, off);   // Set Left OFF
    analogWrite(right, off);  // Set Right OFF
    res = "LL";               // Store results
  }
  
  // Uncomment lines below for diagnostic purposes
  // Serial.print("\n");
  // Serial.print("Input: ");
  // Serial.print(inputString);
  // Serial.print("\n");
  // Serial.print("Return: ");
  // Serial.print(res);
  // Serial.print("\n");

  inputString = ""; // Set inputString to an empty value
} 



