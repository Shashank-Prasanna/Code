
#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(115200);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960");
  }

}

void loop() {
  if (APDS.gestureAvailable()) {
    if (APDS.proximityAvailable()) {

      int gesture = APDS.readGesture();
      int proximity = APDS.readProximity();

      switch (gesture) {
        case GESTURE_UP:
          Serial.println("Detected UP gesture");
          break;
  
        case GESTURE_DOWN:
          Serial.println("Detected DOWN gesture");
          break;
  
        case GESTURE_LEFT:
          Serial.println("Detected LEFT gesture");
          break;
  
        case GESTURE_RIGHT:
          Serial.println("Detected RIGHT gesture");
          break;
  
        default:
          // ignore
          break;
    }
  }
  }
}
