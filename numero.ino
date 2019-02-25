#define IN1  7
#define IN2  6
#define IN3  5
#define IN4  4
 
int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};
 
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  reset();
}


void step_acw(int pasos){
for (int j = 0; j < pasos; j++)
  for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(2);
    }
  }

void step_cw(int pasos){
for (int j = 0; j < pasos; j++)
  for (int i = 0; i < 4; i++)
    {
      digitalWrite(IN4, paso[i][0]);
      digitalWrite(IN3, paso[i][1]);
      digitalWrite(IN2, paso[i][2]);
      digitalWrite(IN1, paso[i][3]);
      delay(2);
    }
  }


void reset(){
  step_acw(2000);
  step_cw(33);
  }


void loop() {

while (Serial.available() > 0) {

    int p = Serial.parseInt();
    if (Serial.read() == '\n') {
      if (p==0){reset(); Serial.println("Reset");}
      if (p==2){
        step_cw(1892);
        step_acw(1232);
        step_cw(968);
        step_acw(616);
        step_cw(352);
        }
        
        if (p==3){
        step_acw(880);
        step_cw(1144);
        step_acw(616);
        step_cw(352);
        }
        
      
      if (p<-10){
          step_cw(-p);
        }
        
        if (p>10){
          step_acw(p);
          }
      
      Serial.println(p);
    }
    
  }
                
                
}



