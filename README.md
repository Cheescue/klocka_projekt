# Clock and Temperature Display Project

This project displays the current time and temperature on an OLED screen and uses a servo motor to visually indicate temperature changes. It is built with an **RTC DS3231** for precise timekeeping, a **1306 OLED display** for showing time and temperature, and an **analog temperature module** to measure ambient temperature. A button is included for interaction, counting the number of presses and displaying the count on the OLED.

## Features
- **Clock Display**: Uses the DS3231 Real-Time Clock to display the current time.
- **Temperature Measurement**: Reads the ambient temperature with the DS3231 and adjusts a servo motor based on temperature values.
- **OLED Screen Output**: The OLED displays:
  - The current time.
  - The current temperature.
  - The number of button presses.
- **Servo Motor Indicator**: Maps the temperature to the angle of a 9g servo motor, which moves to indicate temperature changes.
- **Button Interaction**: A button records the number of presses, which are shown on the OLED display.

## Hardware Requirements
- **DS3231 RTC Module**: Provides accurate time and temperature data.
- **SSD1306 OLED Display**: 128x64 pixels for clear time and temperature readouts.
- **Servo Motor (9g)**: Moves based on temperature changes.
- **Button**: For incrementing the press count and interaction.
- **Arduino Compatible Board**

## Setup and Usage
1. **Wiring**:
   - Connect the DS3231, OLED, and servo motor to your microcontroller following the pin assignments.
   - Connect the button to pin 4 on the microcontroller, using the internal pull-up resistor.

2. **Code Configuration**:
   - The project code uses libraries for the DS3231, OLED, and Servo motor. Ensure you have installed `RTClib`, `U8glib`, and `Servo` libraries.
   - Upon setup, the RTC initializes to the current date and time, and the servo is set to a neutral position (90 degrees).

3. **Functionality**:
   - **Clock**: The DS3231 module provides time, which is updated every loop cycle and shown on the OLED.
   - **Temperature Display**: The temperature from the DS3231 is displayed and used to adjust the servo angle.
   - **Servo Mapping**: The servo maps the temperature to a range of 0-180 degrees, based on the deviation from a base temperature (25°C).
   - **Button**: Each button press increments a counter shown on the OLED.

## Code Breakdown
### Main Functions
- **`getTime()`**: Retrieves and formats the current time from the DS3231.
- **`oledWrite()`**: Updates the OLED with the time, temperature, and button press count.
- **`servoWrite()`**: Maps temperature to servo angle for visual feedback.
- **`getTemp()`**: Reads temperature data from the DS3231.
- **Button Debounce Logic**: Detects button state changes, debounces, and increments the press count when pressed.

### Loop
In the loop function, the temperature is read, button state changes are detected and debounced, and the OLED and servo are updated accordingly.

## Libraries Used
- **RTClib**: For interfacing with the DS3231.
- **U8glib**: For controlling the SSD1306 OLED display.
- **Servo**: For controlling the 9g servo motor.

## Project Inspiration
This project is inspired by a need for a compact and easy-to-read clock and temperature display with an intuitive, visual indicator of temperature changes.


