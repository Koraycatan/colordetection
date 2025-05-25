#define s0 8 //Module pins wiring
#define s1 9
#define s2 10
#define s3 11
#define out 12

int Red=0, Blue=0, Green=0; 

void setup()
{
pinMode(s0,OUTPUT); //pin modes
pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(out,INPUT);

Serial.begin(9600); //intialization of the serial monitor baud rate

digitalWrite(s0,HIGH); //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%
digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is 2%

}

void loop(){

GetColors(); //Execute the GetColors function to get the value of each RGB color

if (Red <=15 && Green <=15 && Blue <=15) //If the values are low it's likely the white color (all the colors are present)
Serial.println("White");

else if (Red<Blue && Red<=Green && Red<23) //if Red value is the lowest one and smaller thant 23 it's likely Red
Serial.println("Red");

else if (Blue<Green && Blue<Red && Blue<20) //Same thing for Blue
Serial.println("Blue");

else if (Green<Red && Green-Blue<= 8)
Serial.println("Green");

else
Serial.println("Unknown"); 


delay(2000); //can be modified



}


void GetColors()
{
digitalWrite(s2, LOW); //S2/S3 levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH is for Blue and HIGH/HIGH is for green
digitalWrite(s3, LOW);
Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
delay(20);
digitalWrite(s3, HIGH); //Here we select the other color (set of photodiodes) and measure the other colors value using the same techinque
Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
delay(20);
digitalWrite(s2, HIGH);
Green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
delay(20);
}
