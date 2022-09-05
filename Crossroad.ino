#include<ipst.h>

//นับเวลาไฟทั้งสองสี
int red_count = 0;
int green_count = 0;

//เวลาที่ไฟสองสีนี้จะแสดง
int green_lim = 19;
int red_lim = 59;

//กำหนดเลขสวิตซ์
int green = 16;
int red = 17;

//กำหนดตัวแปรเงื่อนไขการแสดงไฟของ LED8
int r = 0;
int g = 0;
int pattern = 0b11111111;
int pattern_r = pattern;
int pattern_g = pattern;

//กดแล้วเปลี่ยนเป็นเขียว
bool sw_green;

const int speaker = 19 ;
int musicTick = 1 ;

void setup(){

pinLED8(18);//เสียบLED8ช่องที่18
setTextSize(4);

}

void loop(){
    //แสดงเวลา

    //ไฟตามปกติ
    if(red_count <= red_lim){//แสดงไฟสีแดง
        glcd(0,0,"%d",red_count);
        out(red,1);//ไฟแดงเปิด
        out(green,0);//ไฟเขียวปิด
        //เงื่อนไขคือ LED8 จะดับ 1 ดวง ถ้าหากเลขบนจอหารด้วย 8 แล้วเหลือเศษหนึ่ง ไปเรื่อยๆ จนถึง 60 โดยที่เลขไม่เป็น 1
        if((red_count % 8 == 1 || red_count == 60) && red_count != 1){//เงื่อนไขการลดไฟLED8 สีแดง
            r++;//เป็นค่าที่ใช้ right shift
            pattern_r = pattern >> r; //ผลจากการ right shift จะเก็บที่ตัวแปร pattern_r
        }
        red_count++;
        LED8(pattern_r); //แสดงผล pattern_
        musicTick = 1;
    }
    else if(green_count <= green_lim){//ถ้าเงื่อนไขแสดงไฟสีแดงไม่ตรงก็มาทำสีเขียวต่อ
       if(green_count == 0) 
            glcdClear();//เคลียร์จอเพื่อเอาเลขหลักที่สองจากอันก่อนออกไปแล้วเริ่มนับจาก 0 ใหม่
       
        glcd(0,0,"%d",green_count);
        out(green,1);//ไฟเขียวติด
        out(red,0);//ไฟแดงดับ

        //เงื่อนไขแรกคือ LED8 จะดับ 1 ดวง ถ้าหาก เลขบนจอหารด้วย 3 ลงตัว ไปเรื่อยๆ จนถึง 12 โดยที่เลขไม่เป็น0 กับ 1
        if((green_count % 3 == 0 && green_count <= 12) && green_count != 1 && green_count != 0){
            g++;//เป็นค่าที่ใช้ right shift
            pattern_g = pattern >> g; //ผลจากการ right shift จะเก็บที่ตัวแปร pattern_g
        }

        //เงื่อนไขสองคือ LED8 จะดับ 1 ดวง ถ้าหาก เลขบนจอหารด้วย 2 ลงตัว ไปเรื่อยๆ จนถึง 20
        if((green_count % 2 == 0 && green_count >= 14) && green_count != 1 && green_count != 0){
            g++;//เป็นค่าที่ใช้ right shift
            pattern_g = pattern >> g; //ผลจากการ right shift จะเก็บที่ตัวแปร pattern_g
        }
        green_count++;
        LED8(pattern_g);//แสดงผล pattern_g
        if (musicTick == 1){sound(speaker,712,50);}
        else if (musicTick == 2){sound(speaker,660,50);}
        else if (musicTick == 3){sound(speaker,600,50);}
        else if (musicTick == 4){sound(speaker,600,50);}
        else if (musicTick == 5){sound(speaker,520,50);}
        else if (musicTick == 6){sound(speaker,1200,50);}
        else if (musicTick == 7){sound(speaker,1200,50);}
        else if (musicTick == 8){sound(speaker,1200,50);}
        musicTick++;
        if (musicTick >= 9) {musicTick = 1;}
    } 
    else{//รีเซ็ตทุกอย่างสู่ค่าเริ่มต้น
        red_count = 0;
        green_count = 0;
        pattern_g = pattern;
        pattern_r = pattern;
        r = 0;
        g = 0;
        musicTick = 1;
        glcdClear();
    }

    //เปลี่ยนสีเขียวทันที
    if(sw1())
        sw_green = true;

    while(sw_green){
      if(green_count == 0)
      glcdClear();
      if(green_count == 20){//ตอนจบรีเซ็ตทุกอย่างสู่ค่าเริ่มต้น
        LED8(0b00000000);
            out(green,0);
            out(red,1);
            green_count = 0;
            red_count = 0;
            r = 0;
            g = 0;
            musicTick = 1;
            pattern_r = pattern;
            pattern_g = pattern;
            sw_green = false;
            glcdClear();
            break;
        }
        //copy code การแสดงผลไฟสีเขียวเลย
        glcd(0,0,"%d",green_count);
        out(green,1);
        out(red,0);
        if((green_count % 3 == 0 && green_count <= 12) && green_count != 1 && green_count != 0){
            g++;
            pattern_g = pattern >> g;
        }
        if((green_count % 2 == 0 && green_count >= 14) && green_count != 1 && green_count != 0){
            g++;
            pattern_g = pattern >> g;
        }
        green_count++;
        LED8(pattern_g);
        if (musicTick == 1){sound(speaker,712,50);}
        else if (musicTick == 2){sound(speaker,660,50);}
        else if (musicTick == 3){sound(speaker,600,50);}
        else if (musicTick == 4){sound(speaker,600,50);}
        else if (musicTick == 5){sound(speaker,520,50);}
        else if (musicTick == 6){sound(speaker,1200,50);}
        else if (musicTick == 7){sound(speaker,1200,50);}
        else if (musicTick == 8){sound(speaker,1200,50);}
        musicTick++;
        if (musicTick >= 9) {musicTick = 1;}
        delay(1000);
    }
    delay(1000);
}
