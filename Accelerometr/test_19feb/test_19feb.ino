//#include <helper_3dmath.h>
//#include <MPU6050.h>
//#include <MPU6050_6Axis_MotionApps20.h>
//#include <MPU6050_9Axis_MotionApps41.h>

#include "I2Cdev.h"
#include "MPU6050.h"

#define T_OUT 20

MPU6050 accel;

unsigned long int t_next;

void setup() {
    Serial.begin(9600);
    accel.initialize();
    Serial.println(accel.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
    long int t = millis();
    if( t_next < t ){
        int16_t ax_raw, ay_raw, az_raw, gx_raw, gy_raw, gz_raw;

        t_next = t + T_OUT;
        accel.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);
 
        Serial.print(ay_raw); // вывод в порт проекции ускорения на ось Y
        Serial.print(" I ");
        Serial.print(ax_raw);
        Serial.print(" I ");
        Serial.println(ax_raw);
        //delay(200);
    }
}
