#include <Servo.h>

Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;

double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;



void setup() {
 Serial.begin(115200);
  base.attach(8);
  shoulder.attach(9); 
  elbow.attach(10);
  wrist.attach(11);
  gripper.attach(12); 

  base.write(base_angle);
  shoulder.write(shoulder_angle);
  elbow.write(elbow_angle);
  wrist.write(wrist_angle);

}

void loop() {
 String computerText = Serial.readStringUntil('@');
  computerText.trim();
  if (computerText.length() == 0) {
    return;
  }
  
  String command = getValue(computerText, ' ',0);

    if (command == "right" || command == "يمين" || command == "Right") {
      base.write(base_angle -= 20);
    }
    if (command == "left" || command == "يسار" || command == "left") {
     base.write(base_angle += 20);
    }

    if (command == "top" || command == "اعلى" || command == "Top") {
      shoulder.write(shoulder_angle -= 20);
    }

   if (command == "bottom"|| command == "اسفل" || command == "Bottom") {
     shoulder.write(shoulder_angle += 20);
    }
    Serial.println(command);
  Serial.println("done");
  delay(1000);
}
