#include<ipst.h>
int R = 17 ,Y = 19,G = 20 ,speaker = 16,result;
int t = 0,c = 0;
int pattern[] = {0b11111111,0b01111111,0b00111111,0b00011111,0b00001111,0b00000111,0b00000011,0b00000001};
bool Day = true;
void setup() {
  pinLED8(18);
  setTextSize(5);
}

void loop() {
  if(0 <= t && t <= 198 && Day == true){
    if(t<=40){
      if(c == 0){beep(speaker);}
      c++;
      result = 40 - c ;
      out(R,0);
      out(Y,0);
      out(G,1);
      if(40 == c){c = 0;}
      glcd(0,0,"%d",result);
      if(t <= 5) {
        LED8(pattern[0]);}
      else if (t <= 10){
        LED8(pattern[1]);}
      else if (t <= 15){
        LED8(pattern[2]);}
      else if (t <= 20){
        LED8(pattern[3]);}
      else if (t <= 25){
        LED8(pattern[4]);}
      else if (t <= 30){
        LED8(pattern[5]);}
      else if (t <= 35){
        LED8(pattern[6]);}
      else if (t <= 40){
        LED8(pattern[7]);}
    }
    else if (t<=42){
      if(c == 0){beep(speaker);}
      c++;
      result = 2-c;
      out(R,0);
      out(Y,1);
      out(G,0);
      if(2 <= c){c = 0;}
      glcd(0,0,"%d",result);
      if (t <= 41){
        LED8(pattern[0]);}
      else if (t <= 42) {
        LED8(pattern[4]);}
    }
    else {
      if(c == 0){beep(speaker);}
      c++;
      result = 156 - c;
      out(R,1);
      out(Y,0);
      out(G,0);
      if(156 <= c){c = 0;}
      glcd(0,0,"%d",result);
      if(t <= 62){
        LED8(pattern[0]);}
      else if (t <= 81){
        LED8(pattern[1]);}
      else if (t <= 101){
        LED8(pattern[2]);}
      else if (t <= 120){
        LED8(pattern[3]);}
      else if (t <= 140){
        LED8(pattern[4]);}
      else if (t <= 159){
        LED8(pattern[5]);}
      else if (t <= 179){
        LED8(pattern[6]);}
      else if (t <= 198){
        LED8(pattern[7]);}
    }
  }
  else if (0 <= t && t <= 103 && Day == false){
    if (t <= 20){
    if(c == 0){beep(speaker);}
    c++;
    result = 20 - c;
    out(R,0);
    out(Y,0);
    out(G,1);
    if(20 <= c){c = 0;}
    glcd(0,0,"%d",result);
    if(t <= 3) {
        LED8(pattern[0]);}
      else if (t <= 5){
        LED8(pattern[1]);}
      else if (t <= 8){
        LED8(pattern[2]);}
      else if (t <= 10){
        LED8(pattern[3]);}
      else if (t <= 13){
        LED8(pattern[4]);}
      else if (t <= 15){
        LED8(pattern[5]);}
      else if (t <= 18){
        LED8(pattern[6]);}
      else if (t <= 20){
        LED8(pattern[7]);}
    }
    else if (t <= 22){
      if(c == 0){beep(speaker);}
      c++;
      result = 2-c;
      out(R,0);
      out(Y,1);
      out(G,0);
      if(2 <= c){c = 0;}
      glcd(0,0,"%d",result);
      if (t <= 21){
        LED8(pattern[0]);}
      else if (t <= 22) {
        LED8(pattern[4]);}
    }    
    else {
      if(c == 0){beep(speaker);}
      c++;
      result = 81 - c;
      out(R,1);
      out(Y,0);
      out(G,0);
      if(81 <= c){c = 0;}
      glcd(0,0,"%d",result);
      if(t <= 32){
        LED8(pattern[0]);}
      else if (t <= 42){
        LED8(pattern[1]);}
      else if (t <= 52){
        LED8(pattern[2]);}
      else if (t <= 63){
        LED8(pattern[3]);}
      else if (t <= 73){
        LED8(pattern[4]);}
      else if (t <= 83){
        LED8(pattern[5]);}
      else if (t <= 93){
        LED8(pattern[6]);}
      else if (t <= 103){
        LED8(pattern[7]);}
    }
  }
  if(sw_1() && Day == true){Day = false; t = 0; c = 0;}
  if(sw_OK() && Day == false){Day = true; t = 0; c = 0;}
  if((t >= 198 && Day == true)){t = 0; c = 0;}
  if((t >= 103 && Day == false)){t = 0; c = 0;}
  t++;
  delay(1000);
  glcdClear();
}
