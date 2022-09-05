#include<ipst.h>
const int R = 17 ,Y = 19,G = 20 ,speaker = 16;
int t = 0,c = 1 ,result;
int pattern[] = {0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001,0b00000000};
bool Day = true;
void setup() {
  pinLED8(18);
  setTextSize(5);
}

void loop() {
  if(sw_1() && Day == true){Day = false; t = 0; c = 1;}
  if(sw_OK() && Day == false){Day = true; t = 0; c = 1;}
  if((t >= 198 && Day == true)){t = 0; c = 1;}
  if((t >= 103 && Day == false)){t = 0; c = 1;}
  if(0 <= t && t <= 197 && Day == true){
    if(t < 196 && t >= 146){
      if (t == 146){c = 1;}
      if(c == 1){beep(speaker);}
      result = 50 - c ;
      c++;  
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 6) {
        LED8(pattern[7]);}
      else if (result < 13){
        LED8(pattern[6]);}
      else if (result < 19){
        LED8(pattern[5]);}
      else if (result < 25){
        LED8(pattern[4]);}
      else if (result < 31){
        LED8(pattern[3]);}
      else if (result < 38){
        LED8(pattern[2]);}
      else if (result < 44){
        LED8(pattern[1]);}
      else if (result < 50){
        LED8(pattern[0]);}
    }
    else if (t < 198 && t >= 196){
      if(t == 196){c = 1;}
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
    else {
      //if(t == 42){c = 1;}
      if(c == 1){beep(speaker);}
      result = 146 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 18){
        LED8(pattern[7]);}
      else if (result < 37){
        LED8(pattern[6]);}
      else if (result < 55){
        LED8(pattern[5]);}
      else if (result < 73){
        LED8(pattern[4]);}
      else if (result < 91){
        LED8(pattern[3]);}
      else if (result < 110){
        LED8(pattern[2]);}
      else if (result < 128){
        LED8(pattern[1]);}
      else if (result < 146){
        LED8(pattern[0]);}
    }
  }
  else if(0 <= t && t <= 102 && Day == false){
    if(t < 101 && t >= 76){
      if (t == 76){c = 1;}
      if(c == 1){beep(speaker);}
      result = 25 - c ;
      c++;  
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 3) {
        LED8(pattern[7]);}
      else if (result < 6){
        LED8(pattern[6]);}
      else if (result < 9){
        LED8(pattern[5]);}
      else if (result < 13){
        LED8(pattern[4]);}
      else if (result < 16){
        LED8(pattern[3]);}
      else if (result < 19){
        LED8(pattern[2]);}
      else if (result < 22){
        LED8(pattern[1]);}
      else if (result < 25){
        LED8(pattern[0]);}
    }
    else if (t < 103 && t >= 101){
      if(t == 101){c = 1;}
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
    else {
      if(c == 1){beep(speaker);}
      result = 76 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result == 0){
        LED8(pattern[8]);}
      else if(result < 10){
        LED8(pattern[7]);}
      else if (result < 19){
        LED8(pattern[6]);}
      else if (result < 29){
        LED8(pattern[5]);}
      else if (result < 38){
        LED8(pattern[4]);}
      else if (result < 48){
        LED8(pattern[3]);}
      else if (result < 57){
        LED8(pattern[2]);}
      else if (result < 67){
        LED8(pattern[1]);}
      else if (result < 76){
        LED8(pattern[0]);}
    }
  }
  t++;
  delay(1000);
  glcdClear();
}
