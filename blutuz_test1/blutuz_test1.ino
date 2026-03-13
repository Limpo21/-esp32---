#include "BluetoothSerial.h" // Включаем библиотеку для работы с Bluetooth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT; // Создаем объект BluetoothSerial
void setup() {
  Serial.begin(115200); // Инициализация серийного порта для отладки (на монитор порта Arduino IDE)
  SerialBT.begin("ESP32_BT_Responder"); // Инициализация Bluetooth с именем устройства "ESP32_BT_Responder"

  Serial.println("Bluetooth BluetoothSerial.begin() успешно инициализирован.");
  Serial.println("Готов к приему команд...");
}
void loop() {
  // Проверяем, есть ли данные, полученные через Bluetooth
  if (SerialBT.available()) {
    SerialBT.println("введите 1 чтоб получить сообщение");
    char incomingChar = SerialBT.read(); // Читаем полученный символ
    Serial.print("Получен символ: ");
    Serial.println(incomingChar);
    // Проверяем, является ли полученный символ '1'
    if (incomingChar == '1') {
      Serial.println("Обнаружена команда '1'. Отправляю ответ...");
      // Отправляем сообщение "hello world" обратно через Bluetooth
      SerialBT.println("hello world");
      Serial.println("Сообщение 'hello world' отправлено.");
    }
  }
  // Здесь можно добавить другую логику, которая должна выполняться постоянно,
  // но в данном примере мы просто ждем команды.
  delay(10); // Небольшая задержка, чтобы не перегружать процессор
}

