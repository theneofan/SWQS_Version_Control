# SWQS_Version_Control

Submersible Water Quality Surveyance or SWQS is an initiative to provide people with a simple yet effective way to assess the quality of a water source. The project works with a website alongside the Submersible Water Quality Surveyance Probe, S.W.Q.S.P., that is a small and cheap to build "Probe" that contains sensors and a microcontroller that record data every tenth of a second to a microSD card module. This data is saved as a Comma Speperated Vector file and is then uploaded to the [website](https://water-quality-data-a-owii.bolt.host)where the data is interpretted and it is displayed in plain text how safe the water is to drink in it's current state.

When editing the arduino codebase make sure to open with PlatformIO IDE and ensure you add all required libraries to the project.
Libraries:
<Arduino.h>, <math.h>, <SPI.h>, <SD.h>, <OneWire.h>, <DallasTemperature.h>, <NewPing.h>
