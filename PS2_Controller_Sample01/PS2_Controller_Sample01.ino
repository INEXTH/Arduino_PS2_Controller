/*
 * Copyright (c) 2014 Innovative Experiment Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * ตัวอย่างการใช้งานบอร์ด Arduino Uno R3 ร่วมกับ PS2 Controller
 *
 * โปรแกรมทดสอบการทำงานของ PS2 Controller
 *
 * ใช้ทดสอบ PS2 Controller โดยมีหน้าจอแสดงผลเป็นเลย์เอาท์ของปุ่มต่างๆบนตัว PS2 Controller (เป็นภาพสีเทา)
 * เมื่อกดปุ่มใดๆบน PS2 Controller ก็จะแสดงบนหน้าจอเป็นภาพว่าปุ่มนั้นๆถูกกดอยู่ (สีแตกต่างกันไปตามแต่ละปุ่ม)
 * และแสดงพิกัดของคันโยกอะนาล็อกด้วยจุดสีแดง ซึ่งจะเคลื่อนตำแหน่งไปตามการโยกคันโยก
 */

#include <PS2X_lib.h>                           // เรียกใช้งานไลบรารีสำหรับ PS2 Controller
 
#define PS2_DAT        8                        // กำหนดขา Data    เป็นขา 30
#define PS2_CMD        9                        // กำหนดขา Command เป็นขา 4
#define PS2_SEL        10                       // กำหนดขา Select  เป็นขา 6
#define PS2_CLK        11                       // กำหนดขา Clock   เป็นขา 12

PS2X ps2x;                                       // ประกาศตัวแปรสำหรับ PS2 Controller

void setup()
{
  delay(1000);                                   // หน่วงเวลา 1 วินาทีเพื่อรอให้บอร์ดพร้อมทำงาน
  Serial.begin(9600);
  
  // กำหนดขาที่จะเชื่อมต่กับ PS2 Controller โดยมีการเก็บค่าที่ส่งกลับมาเป็น Integer เพื่อรู้ได้ว่าเชื่อมต่อได้หรือไม่
  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  
  if(error == 0)                                 // กรณีที่เชื่อมต่อได้ ไม่มีปัญหาอะไร (Error = 0)
  {
    Serial.println("Controller Available");      // แสดงข้อความว่าเชื่อมต่อกับ PS2 Controller เรียบร้อยแล้ว
  } 
  else                                           // ถ้าไม่สามารถเชื่อมต่อกับ PS2 Controller 
  {                                
    Serial.println("Controller Unavailable");    // แสดงข้อความว่าไม่สามารถเชื่อมต่อกับ PS2 Controller
    while(true);                                 // วนไม่จำกัด เพื่อให้ผู้ใช้รีเซตบอร์ดเพื่อเชื่อมต่อใหม่
  }
}

void loop()
{
  ps2x.read_gamepad(false, false);               // อ่านข้อมูลจาก PS2 Controller
  
  
  if(ps2x.Button(PSB_CIRCLE))                    // ถ้าปุ่มวงกลมถูกกด
    Serial.println("Circle");                    // แสดงข้อความว่า Circle 
  else if(ps2x.Button(PSB_CROSS))                // ถ้าปุ่มกากบาทถูกกด
    Serial.println("Cross");                     // แสดงข้อความว่า Cross 
  else if(ps2x.Button(PSB_SQUARE))               // ถ้าปุ่มสี่เหลี่ยมถูกกด
    Serial.println("Square");                    // แสดงข้อความว่า Square 
  else if(ps2x.Button(PSB_TRIANGLE))             // ถ้าปุ่มสามเหลี่ยมถูกกด
    Serial.println("Triangle");                  // แสดงข้อความว่า Triangle 
  else if(ps2x.Button(PSB_L1))                   // ถ้าปุ่ม L1 ถูกกด
    Serial.println("L1");                        // แสดงข้อความว่า L1 
  else if(ps2x.Button(PSB_L2))                   // ถ้าปุ่ม L2 ถูกกด
    Serial.println("L2");                        // แสดงข้อความว่า L2 
  else if(ps2x.Button(PSB_L3))                   // ถ้าปุ่ม L3 ถูกกด
    Serial.println("L3");                        // แสดงข้อความว่า L3 
  else if(ps2x.Button(PSB_R1))                   // ถ้าปุ่ม R1 ถูกกด
    Serial.println("R1");                        // แสดงข้อความว่า R1 
  else if(ps2x.Button(PSB_R2))                   // ถ้าปุ่ม R2 ถูกกด
    Serial.println("R2");                        // แสดงข้อความว่า R2 
  else if(ps2x.Button(PSB_R3))                   // ถ้าปุ่ม R3 ถูกกด
    Serial.println("R3");                        // แสดงข้อความว่า R3 
  else if(ps2x.Button(PSB_START))                // ถ้าปุ่ม Start ถูกกด
    Serial.println("Start");                     // แสดงข้อความว่า Start 
  else if(ps2x.Button(PSB_SELECT))               // ถ้าปุ่ม Select ถูกกด
    Serial.println("Select");                    // แสดงข้อความว่า Select 
  else if(ps2x.Button(PSB_PAD_UP))               // ถ้าปุ่ม Up ถูกกด
    Serial.println("Up");                        // แสดงข้อความว่า Up 
  else if(ps2x.Button(PSB_PAD_DOWN))             // ถ้าปุ่ม Down ถูกกด
    Serial.println("Down");                      // แสดงข้อความว่า Down 
  else if(ps2x.Button(PSB_PAD_LEFT))             // ถ้าปุ่ม Left ถูกกด
    Serial.println("Left");                      // แสดงข้อความว่า Left 
  else if(ps2x.Button(PSB_PAD_RIGHT))            // ถ้าปุ่ม Right ถูกกด
    Serial.println("Right");                     // แสดงข้อความว่า Right 
    
  delay(50);                                     // หน่วงเวลา 50 มิลลิวินาที
}
