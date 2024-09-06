// Define the pin connected to the sensor output
#define IR_SENSOR_PIN 13

void setup()
{
    // Initialize serial communication for output
    Serial.begin(115200);

    // Set the IR sensor pin as input
    pinMode(IR_SENSOR_PIN, INPUT);
}

void loop()
{
    // Read the sensor output
    int sensorValue = digitalRead(IR_SENSOR_PIN);

    // Check if an obstacle is detected
    if (sensorValue == LOW)
    {
        // If the sensor's output is LOW, an obstacle is detected
        Serial.println("Obstacle detected!");
    }
    else
    {
        // If the sensor's output is HIGH, no obstacle is detected
        Serial.println("No obstacle.");
    }

    // Small delay for stability
    delay(200);
}
