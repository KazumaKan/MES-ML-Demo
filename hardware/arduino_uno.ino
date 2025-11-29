// --------- Random Sensor Demo ---------

float getRandomTemperature() {
  return 25 + random(-20, 40) / 10.0;  // 23.0 - 27.0 (มี noise)
}

float getRandomVibration() {
  return 1.0 + random(-50, 50) / 100.0;  // 0.5 - 1.5 (เหมือน RMS sensor)
}

float getRMS(float v) {
  return v * 0.82; // ค่า RMS แบบประมาณ
}

String getMachineStatus() {
  return random(0, 10) > 1 ? "RUN" : "STOP";  // 90% RUN
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  float tempC = getRandomTemperature();
  float vibration = getRandomVibration();
  float vibration_rms = getRMS(vibration);

  unsigned long ts = millis(); // ใช้เป็น demo

  // Print JSON
  Serial.print("{\"machine_id\":1");
  Serial.print(",\"status\":\""); 
  Serial.print(getMachineStatus()); Serial.print("\"");
  Serial.print(",\"temperature\":"); 
  Serial.print(tempC);
  Serial.print(",\"vibration\":");
  Serial.print(vibration);
  Serial.print(",\"vibration_rms\":");
  Serial.print(vibration_rms);
  Serial.print(",\"timestamp\":");
  Serial.print(ts);
  Serial.println("}");

  delay(500);
}
