#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Timer for printing data
unsigned long previousMillis = 0;
const long interval = 500; // Interval for printing in milliseconds

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);

    // Initialize I2C communication
    Wire.begin();

    // Initialize MPU-6050
    Serial.println("Initializing MPU-6050...");
    if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
    {
        Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
        while (1)
            ;
    }

    // Calibrate gyro and accelerometer
    mpu.calibrateGyro();
    mpu.setThreshold(3); // Set a small threshold for noise reduction

    Serial.println("MPU-6050 Initialized and Calibrated.");
}

void loop()
{
    // Get current time
    unsigned long currentMillis = millis();

    // Check if it's time to print the data
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        // Read raw sensor data
        Vector normAccel = mpu.readNormalizeAccel();
        Vector normGyro = mpu.readNormalizeGyro();

        // Print accelerometer data
        Serial.print("Accelerometer: ");
        Serial.print("X: ");
        Serial.print(normAccel.XAxis);
        Serial.print(" Y: ");
        Serial.print(normAccel.YAxis);
        Serial.print(" Z: ");
        Serial.println(normAccel.ZAxis);

        // Print gyroscope data
        Serial.print("Gyroscope: ");
        Serial.print("X: ");
        Serial.print(normGyro.XAxis);
        Serial.print(" Y: ");
        Serial.print(normGyro.YAxis);
        Serial.print(" Z: ");
        Serial.println(normGyro.ZAxis);

        Serial.println();
    }
}
