#include<ipst.h>
const int R = 17 ,Y = 19,G = 20 ,speaker = 16;
int t = 0,c = 1 ,result;
int pattern[] = {0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001,0b00000000};
bool Day = true ,ft = true;
void setup() {
  pinLED8(18);
  setTextSize(5);
}

void loop() {
  if(sw_1() && Day == true){Day = false; t = 0; c = 1,ft = true;}
  if(sw_OK() && Day == false){Day = true; t = 0; c = 1,ft = true;}
  if((t >= 198 && Day == true)){t = 0;}
  if((t >= 103 && Day == false)){t = 0;}
  if(0 <= t && t <= 197 && Day == true){
    if(t < 144 && t >= 114){
      if (t == 114){c = 1;}
      if(c == 1){beep(speaker);}
      result = 30 - c ;
      ft = false;
      c++;  
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 4) {
        LED8(pattern[7]);}
      else if (result < 8){
        LED8(pattern[6]);}
      else if (result < 11){
        LED8(pattern[5]);}
      else if (result < 15){
        LED8(pattern[4]);}
      else if (result < 19){
        LED8(pattern[3]);}
      else if (result < 23){
        LED8(pattern[2]);}
      else if (result < 26){
        LED8(pattern[1]);}
      else if (result < 30){
        LED8(pattern[0]);}
    }
    else if (t < 116 && t >= 114){
      if(t == 114){c = 1;}
      if(c == 1){beep(speaker);}
      result = 2-c;
      c++;
      out(R,0);
      out(Y,1);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result < 1){
        LED8(pattern[8]);}
      else if (result < 2) {
        LED8(pattern[0]);}
    }
    else if (t >= 0 && t < 114 && ft == true) {
      if(t == 0){c = 1;}
      if(c == 1){beep(speaker);}
      result = 114 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 14){
        LED8(pattern[7]);}
      else if (result < 29){
        LED8(pattern[6]);}
      else if (result < 43){
        LED8(pattern[5]);}
      else if (result < 57){
        LED8(pattern[4]);}
      else if (result < 71){
        LED8(pattern[3]);}
      else if (result < 86){
        LED8(pattern[2]);}
      else if (result < 100){
        LED8(pattern[1]);}
      else if (result < 114){
        LED8(pattern[0]);}
    }
    else {
      if(t == 144){c = 1;}
      if(c == 1){beep(speaker);}
      result = 166 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 21){
        LED8(pattern[7]);}
      else if (result < 42){
        LED8(pattern[6]);}
      else if (result < 62){
        LED8(pattern[5]);}
      else if (result < 83){
        LED8(pattern[4]);}
      else if (result < 104){
        LED8(pattern[3]);}
      else if (result < 125){
        LED8(pattern[2]);}
      else if (result < 147){
        LED8(pattern[1]);}
      else if (result < 166){
        LED8(pattern[0]);}
    }
  }
  else if(0 <= t && t <= 197 && Day == false){ //Night
    if(t < 74 && t >= 59){
      if (t == 59){c = 1;}
      if(c == 1){beep(speaker);}
      result = 15 - c ;
      ft = false;
      c++;  
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 2) {
        LED8(pattern[7]);}
      else if (result < 4){
        LED8(pattern[6]);}
      else if (result < 6){
        LED8(pattern[5]);}
      else if (result < 8){
        LED8(pattern[4]);}
      else if (result < 9){
        LED8(pattern[3]);}
      else if (result < 11){
        LED8(pattern[2]);}
      else if (result < 13){
        LED8(pattern[1]);}
      else if (result < 15){
        LED8(pattern[0]);}
    }
    else if (t < 76 && t >= 74){
      if(t == 74){c = 1;}
      if(c == 1){beep(speaker);}
      result = 2-c;
      c++;
      out(R,0);
      out(Y,1);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result < 1){
        LED8(pattern[8]);}
      else if (result < 2) {
        LED8(pattern[0]);}
    }
    else if (t >= 0 && t < 59 && ft == true) {
      if(t == 0){c = 1;}
      if(c == 1){beep(speaker);}
      result = 59 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 3){
        LED8(pattern[7]);}
      else if (result < 6){
        LED8(pattern[6]);}
      else if (result < 8){
        LED8(pattern[5]);}
      else if (result < 11){
        LED8(pattern[4]);}
      else if (result < 14){
        LED8(pattern[3]);}
      else if (result < 17){
        LED8(pattern[2]);}
      else if (result < 19){
        LED8(pattern[1]);}
      else if (result < 22){
        LED8(pattern[0]);}
    }
    else {
      if(t == 76){c = 1;}
      if(c == 1){beep(speaker);}
      result = 86 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 11){
        LED8(pattern[7]);}
      else if (result < 22){
        LED8(pattern[6]);}
      else if (result < 32){
        LED8(pattern[5]);}
      else if (result < 43){
        LED8(pattern[4]);}
      else if (result < 54){
        LED8(pattern[3]);}
      else if (result < 65){
        LED8(pattern[2]);}
      else if (result < 75){
        LED8(pattern[1]);}
      else if (result < 86){
        LED8(pattern[0]);}
    }
  }
  t++;
  delay(100);
  glcdClear();
}
