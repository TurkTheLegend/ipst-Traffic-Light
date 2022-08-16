#include<ipst.h>
int R = 17 ,Y = 19,G = 20 ,speaker = 16;
int t = 0,tMAX = 198 ,c = 0;
void setup() {
  pinLED8(18);
  setTextSize(3);
}

void loop() {
  if(0 <= t && t < 42){
    if(t<40){
      c++;
      int result = 40 - c ;
      out(R,0);
      out(Y,0);
      out(G,1);
      if(result == 0){c = 0;}
      glcd(0,0,"%d",result);
    }
    else{
      c++;
      int result = 2-c;
      out(R,0);
      out(Y,1);
      out(G,0);
      if(result == 0){c = 0;}
      glcd(0,0,"%d",result);
    }
  }
  else {
    c++;
    int result = 156 - c;
    out(R,1);
    out(Y,0);
    out(G,0);
    if(result == 1){c = 0;}
    glcd(0,0,"%d",result);
  }
  beep(speaker);
  delay(100);
  glcdClear();
  t++;
  if(t == 197){t = 0;}
}
