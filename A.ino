#include<ipst.h>
const int R = 17 ,Y = 19,G = 20 ,speaker = 16;
int t = 0,c = 1 ,result;
int pattern[] = {0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001};
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
    if(t<40){  
      if(c == 1){beep(speaker);}
      result = 40 - c ;
      c++;  
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if(result < 5) {
        LED8(pattern[7]);}
      else if (result < 10){
        LED8(pattern[6]);}
      else if (result < 15){
        LED8(pattern[5]);}
      else if (result < 20){
        LED8(pattern[4]);}
      else if (result < 25){
        LED8(pattern[3]);}
      else if (result < 30){
        LED8(pattern[2]);}
      else if (result < 35){
        LED8(pattern[1]);}
      else if (result < 40){
        LED8(pattern[0]);}
    }
    else if (t<42){
      if(t == 40){c = 1;}
      if(c == 1){beep(speaker);}
      result = 2-c;
      c++;
      out(R,0);
      out(Y,1);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result < 1){
        LED8(pattern[4]);}
      else if (result < 2) {
        LED8(pattern[0]);}
    }
    else {
      if(t == 42){c = 1;}
      if(c == 1){beep(speaker);}
      result = 156 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if(result < 20){
        LED8(pattern[7]);}
      else if (result < 39){
        LED8(pattern[6]);}
      else if (result < 59){
        LED8(pattern[5]);}
      else if (result < 78){
        LED8(pattern[4]);}
      else if (result < 98){
        LED8(pattern[3]);}
      else if (result < 117){
        LED8(pattern[2]);}
      else if (result < 137){
        LED8(pattern[1]);}
      else if (result < 156){
        LED8(pattern[0]);}
    }
  }
  else if (0 <= t && t <= 102 && Day == false){
    if (t < 20){
    if(c == 1){beep(speaker);}
      result = 20 - c;
      c++;
      out(R,0);
      out(Y,0);
      out(G,1);
      glcd(0,0,"%d",result);
      if(result < 3) {
        LED8(pattern[7]);}
      else if (result < 5){
        LED8(pattern[6]);}
      else if (result < 8){
        LED8(pattern[5]);}
      else if (result < 10){
        LED8(pattern[4]);}
      else if (result < 13){
        LED8(pattern[3]);}
      else if (result < 15){
        LED8(pattern[2]);}
      else if (result < 18){
        LED8(pattern[1]);}
      else if (result < 20){
        LED8(pattern[0]);}
    }
    else if (t < 22){
      if(t == 20){c = 1;}
      if(c == 1){beep(speaker);}
      result = 2-c;
      c++;
      out(R,0);
      out(Y,1);
      out(G,0);
      glcd(0,0,"%d",result);
      if (result < 1){
        LED8(pattern[4]);}
      else if (result < 2) {
        LED8(pattern[0]);}
    }    
    else {
      if(t == 22){c = 1;}
      if(c == 1){beep(speaker);}
      result = 81 - c;
      c++;
      out(R,1);
      out(Y,0);
      out(G,0);
      glcd(0,0,"%d",result);
      if(result < 10){
        LED8(pattern[7]);}
      else if (result < 20){
        LED8(pattern[6]);}
      else if (result < 30){
        LED8(pattern[5]);}
      else if (result < 41){
        LED8(pattern[4]);}
      else if (result < 51){
        LED8(pattern[3]);}
      else if (result < 61){
        LED8(pattern[2]);}
      else if (result < 71){
        LED8(pattern[1]);}
      else if (result < 81){
        LED8(pattern[0]);}
    }
  }
  t++;
  delay(1000);
  glcdClear();
}
