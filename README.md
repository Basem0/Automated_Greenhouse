# Automated Greenhouse Monitoring System

![depositphotos_139374026-stock-photo-internet-of-things-industrial-agriculture](https://github.com/user-attachments/assets/9161f9c0-af09-4484-a1ca-40932e1582a7)

Welcome to the Automated Greenhouse Monitoring System project! This project was developed by Ahmed Basem for the CAT Reloaded Hackathon. It leverages three microcontrollers to monitor and control various environmental parameters within a greenhouse, ensuring optimal conditions for plant growth.
![Screenshot 2024-07-14 055327](https://github.com/user-attachments/assets/8b657e5e-b8ea-4630-bb9e-ae2f93da265f)

## Project Overview

The system comprises three microcontrollers (MCUs):
1. **ATmega32 (MCU1)**
2. **STM32F103C8 (Blue Pill) - MCU2**
3. **STM32F103C8 (Blue Pill) - MCU3**
![Screenshot 2024-07-14 055241](https://github.com/user-attachments/assets/4038c353-4b66-43c6-9897-8d2f5735a911)

### ATmega32 (MCU1)

**Sensors:**
- **LM35 Temperature Sensors** (Right and Left): Measure the temperature inside the greenhouse.
- **Soil Moisture Sensors** (Right and Left): Monitor the soil moisture levels.
- **HIH5030 Humidity Sensor**: Measures the humidity level in the greenhouse.
- **LDR (Light Dependent Resistor)**: Detects the light intensity.
![Screenshot 2024-07-14 055059](https://github.com/user-attachments/assets/b7b6259b-3eb6-4ae8-828c-2004cc25b024)

**Functionality:**
- Reads sensor values using the Analog-to-Digital Converter (ADC).
- Controls LEDs in the light system using Timer 0 PWM based on LDR values.
- Displays temperature, water percentage, and humidity percentage on an LCD connected to PORTC.
- Sends flags via UART to MCU2 when:
  - Temperature is greater than 45°C or less than 25°C.
  - Water percentage is less than 50%.

### STM32F103C8 (Blue Pill) - MCU2

**Sensors:**
- **Flame Sensors** (Right and Left): Detects fire inside the greenhouse.
- **MQ4 Gas Sensors** (Right and Left): Detects gas presence in the greenhouse.

**Functionality:**
- Detects the presence of fire or gas.
- Triggers a siren if fire, gas, or a flag from MCU1 is detected.
- Sends flags via UART to MCU3, including:
  - Flags received from MCU1.
  - Fire or gas detection flags.

![Screenshot 2024-07-14 060002](https://github.com/user-attachments/assets/4465776b-c592-4ab3-978b-1ca95db4214a)

### STM32F103C8 (Blue Pill) - MCU3

**Actuators:**
- **Motors**:
  - 2 Fans
  - 2 Heaters
  - 2 Pumps
  
![Screenshot 2024-07-14 055216](https://github.com/user-attachments/assets/a02ce323-52ea-4142-9a94-0804e30664cf)

**Functionality:**
- Controls fans, heaters, and pumps based on flags received from MCU2:
  - Right fire flag: Starts the right pump.
  - Left fire flag: Starts the left pump.
  - Right temperature sensor > 45°C: Starts the right fan.
  - Right temperature sensor < 25°C: Starts the right heater.
  - Left temperature sensor > 45°C: Starts the left fan.
  - Left temperature sensor < 25°C: Starts the left heater.
  - Right moisture flag: Starts the right pump.
  - Left moisture flag: Starts the left pump.
- Displays warning messages on a 4x20 LCD when a flag is received.

![Screenshot 2024-07-14 060026](https://github.com/user-attachments/assets/02ef284b-1577-4238-bad5-201cddf44641)

## Getting Started

### Prerequisites

- ATmega32 Microcontroller
- STM32F103C8 (Blue Pill) Microcontrollers
- LM35 Temperature Sensors
- Soil Moisture Sensors
- HIH5030 Humidity Sensor
- LDR (Light Dependent Resistor)
- Flame Sensors
- MQ4 Gas Sensors
- LCD Displays (4x20)
- Motors (Fans, Heaters, Pumps)
- UART Communication Setup

![Screenshot 2024-07-14 055305](https://github.com/user-attachments/assets/8ce4c769-157e-48c8-b88f-ab87b5e413ed)

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Basem0/Automated_Greenhouse.git
    ```
2. Follow the schematics to connect the sensors and actuators to the respective MCUs.
3. Upload the provided firmware to each microcontroller using your preferred development environment.

### Usage

1. Power up the system.
2. Monitor the LCD displays for real-time environmental data and warnings.
3. Ensure all sensors and actuators are functioning as expected.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License.

## Acknowledgements

This project was developed by Ahmed Basem for the CAT Reloaded Hackathon.
