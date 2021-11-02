int bright[6] = {0, 40, 80, 120, 100, 60};
int brightness = 0;
int leds[6] = {3,5,6,9,10,11};
int fadeAmount[6] = {10,10,10,10,10,10};
int j=0;
int delayTime = 50;
long randNumber =0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);pinMode(11,OUTPUT);
}

void loop() {
  randNumber = floor(random(0,6));
  //map(randNumber,0,1000,0,5);
  int i = randNumber;  
  Serial.println(i);
  
  //for(int i=0;i<6;i++){
    brightness = bright[i];
    analogWrite(leds[i],brightness);
    brightness += fadeAmount[i];
    if (brightness <= 0 || brightness >= 160) {
      fadeAmount[i] = -fadeAmount[i];
    }
    bright[i] = brightness;
  //}
  
  delay(delayTime);  
}
