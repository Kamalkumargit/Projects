
# IoT Based Weather monitoring System Using ESP32

This project is a real-time environmental monitoring system that leverages the **Internet of Things (IoT)** to track temperature and humidity[cite: 33]. [cite_start]It utilizes an **ESP32** microcontroller and a **DHT22** sensor, with data visualized on the **ThingSpeak** cloud platform[cite: 33, 34].

## 📌 Project Overview
The system collects environmental data, processes it via the ESP32, and transmits it to the cloud using Wi-Fi and HTTP protocol[cite: 35, 71]. [cite_start]This allows for continuous remote monitoring from any location[cite: 36]. [cite_start]The project was developed and tested using the **Wokwi** simulator to ensure circuit integrity without the need for physical hardware[cite: 34, 39].

## 🛠️ Components & Tools
* **Microcontroller:** ESP32 Development Board (Built-in Wi-Fi).
* **Sensor:** DHT22 (High-accuracy temperature and humidity).
* **Simulation Platform:** [Wokwi](https://wokwi.com).
* **Cloud Analytics:** [ThingSpeak](https://thingspeak.com).
* **IDE:** Arduino IDE.

## 🚀 Features
* **Real-time Monitoring:** Continuous tracking of parameters with 20-second update intervals.
* **Cloud Integration:** Historical data logging and graphical representation on ThingSpeak.
* **Cost-Effective:** Built using affordable, open-source components and tools.
* **Scalable Architecture:** Modular design allows for adding more sensors like MQ135 or BMP180 in the future.

## 📊 System Architecture
1.  **Data Collection:** DHT22 sensor measures ambient temperature and humidity.
2.  **Processing:** ESP32 reads digital signals from the sensor.
3.  **Transmission:** Data is sent via Wi-Fi to ThingSpeak using HTTP GET requests.
4.  **Visualization:** Real-time graphs and statistical analysis (mean/standard deviation) are available on the ThingSpeak dashboard.

## 📈 Results
The simulation results validated the system's performance, showing smooth and consistent data transitions on the cloud dashboard. The system proved effective for applications in smart agriculture, home automation, and research labs.

## 📝 Future Enhancements
* Adding an **alert system** for threshold breaches (email/SMS).
* Developing a **mobile application** for easier dashboard access.
* Integrating **Machine Learning** for weather prediction models.
* Implementing **solar power** for remote field deployment.

---
**Developed by:** Kamal Kumar
**Internship Organization:** 1Stop.ai
