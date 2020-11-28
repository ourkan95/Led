int Vpwm = A2;
int PWM_out = 4;
float voltage;
float percent;
float PWM;
float brightness;

int ind_1 = 12 ;
int ind_2 = 13 ;
int ind_3 = 14 ;
int ind_4 = 15 ;
int ind_5 = 3 ;

int dim_brt_main = 20;
int dim_brt_com1 = A6;
int dim_brt_com2 = A7;
int dim_brt_vor = 23;
int dim_brt_MB = 22;
int dim_brt_tacan = 21;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  
  pinMode(A6,INPUT_PULLUP);
  pinMode(20,INPUT_PULLUP);
  pinMode(21,INPUT_PULLUP);
  pinMode(22,INPUT_PULLUP);
  pinMode(23,INPUT_PULLUP);
  pinMode(A7,INPUT_PULLUP);  
  pinMode(A2, INPUT);
}

void loop() {
  int dim_brt_main = digitalRead(20);
  int dim_brt_com1 = digitalRead(A6);
  int dim_brt_com2 = digitalRead(A7);
  int dim_brt_vor = digitalRead(23);
  int dim_brt_MB = digitalRead(22);
  int dim_brt_tacan = digitalRead(21);
  voltage = analogRead(Vpwm);
  percent = voltage / 10.23;
  if(0 < percent && percent < 80) {
    brightness = (pow(percent, 4) / 240000) - (23 * (pow(percent, 3)) / 48000) + (47 * (pow(percent, 2)) / 2400) - (percent / 12);

  } else if((percent >= 80) && (100 > percent))  {
    brightness = ((0.07) * percent * percent) - (9.8 * percent) + 380.41;

  }
  PWM = (brightness * 2.55);
  analogWrite(4, PWM);

 
  if (dim_brt_com1 == 0)
 {
   if(dim_brt_main == 0)
  {
    analogWrite(12,255);
  }
  else
  {
    analogWrite(12,25);
  }
 }
 else
 {
  digitalWrite(12,LOW);
 }
 //////////////////ind_control_com2//////////////////////
  if (dim_brt_com2 == 0)
 {
    if(dim_brt_main == 0)
    {
    analogWrite(13,255);
    }
    else
    {
    analogWrite(13,25);
     }
 }
 else
 {
  digitalWrite(13,LOW);
 }
 //////////////////ind_control_vor////////////////////////////
  if (dim_brt_vor == 0)
 {
  if(dim_brt_main == 0)
  {
    analogWrite(14,255);
  }
  else
  {
    analogWrite(14,25);
  }
 }
 else
 {
  digitalWrite(14,LOW);
 }
 /////////////////////ind_control_MB//////////////////////////
  if (dim_brt_MB == 0)
 {
  if(dim_brt_main == 0)
  {
    analogWrite(15,255);
  }
  else
  {
    analogWrite(15,25);
  }
 }
 else
 {
  digitalWrite(15,LOW);
 }
 /////////////////////ind_control_tacan////////////////////
  if (dim_brt_tacan == 0)
 {
  if(dim_brt_main == 0)
  {
    analogWrite(3,255);
  }
  else
  {
    analogWrite(3,25);
  }
 }
 else
 {
  digitalWrite(3,LOW);
 }


}
