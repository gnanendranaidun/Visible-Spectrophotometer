# Visible Spectrophotometer

This project is an implementation of a **Visible Spectrophotometer** using an Arduino, a light sensor, and RGB LEDs. The spectrophotometer measures light intensity at different wavelengths and processes the data accordingly.

## Features
- Uses RGB LEDs to illuminate a sample at different wavelengths.
- Measures light intensity using an LDR (Light Dependent Resistor).
- Computes absorption values based on the captured intensity.
- Outputs processed values over Serial communication.

## Code Overview

The main functionality is divided into:
1. **Value Class**
   - Converts wavelength values into RGB color intensities.
   - Computes a visibility factor based on the spectrum range.
   - Applies intensity correction for accurate readings.

2. **Setup Function**
   - Initializes serial communication and pins.
   - Precomputes RGB values for different wavelengths.

3. **Loop Function**
   - Controls the LED output based on the computed RGB values.
   - Reads the LDR sensor values and calculates absorption.
   - Outputs results via Serial communication.

## Hardware Requirements
- Arduino board
- RGB LED (connected to pins 9, 10, and 11)
- LDR sensor (connected to analog pin A0)
- Resistors for proper voltage division
- Push button (to start/stop measurement)

## Usage Instructions
1. Upload the code to the Arduino board.
2. Ensure the RGB LEDs and LDR are properly connected.
3. Press the button to start the measurement.
4. The system will cycle through different wavelengths, measuring the intensity.
5. Data will be sent via Serial communication for further analysis.

## Future Improvements
- Implement real-time plotting of spectral data.
- Improve wavelength-to-RGB conversion for better accuracy.
- Add support for different light sensors for enhanced precision.

## more details
- The detailed description of the project is in report.

## License
This project is open-source and can be modified as needed.


