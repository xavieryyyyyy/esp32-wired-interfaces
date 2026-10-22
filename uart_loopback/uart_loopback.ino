const int UART_TX = 17;
const int UART_RX = 16;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, UART_RX, UART_TX);
}

void loop() {
  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 1000) {
    lastSend = millis();
    Serial2.println("PING");
  }

  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}