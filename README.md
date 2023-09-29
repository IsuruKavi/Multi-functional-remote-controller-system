# Multi-functional-remote-controller-system

Successfully Designed a Remote Controller System for Wave Soldering Machine 🛠️
During my internship , I had the opportunity to work on an innovative project aimed at enhancing the safety and convenience of wave soldering machine operations. The core objective was to remotely control the hot solder bath, eliminating the need for operators to be in close proximity to the potentially dangerous liquid solder.

**Key Features**:
- I designed and implemented a user-friendly interface with four push buttons (Up, Down, In, Out) to facilitate machine operations.
- Normal operation required a 2-3 minute continuous button press, but I engineered a solution allowing operators to initiate actions with a single button press and stop the operation by pressing again.

**Two Operating Modes**:
- **Manual Mode (Green Light)**: The system defaults to this mode at startup. Operators must press and hold buttons to execute operations.
- **Auto Mode (Red Light)**: In this mode, a single button press triggers and controls the operation. Press "Out" to start, and it can be stopped by pressing "In" or "Out." Additionally, the system includes a safety feature: the relays will automatically turn off after 2.5 minutes, ensuring that even if the operator doesn't manually turn off the operation, safety is maintained.

**Seamless Mode Switching**:
- Users can effortlessly switch between modes by pressing the middle button.

**Technology Stack**:
- I harnessed RF communication with RF modules, encoders, and decoders.
- The project's core is the PIC16F76 microcontroller, enabling precise control and reliable operation.

**Code Implementation**:
-I meticulously crafted robust code for both the transmitter and receiver sides to guarantee error-free signal transmission and reception.
-A critical focus was to ensure the system could maintain control and data integrity during signal interruptions, preventing risky conditions during operations.

### Code,schematic and some photos of project have been uploaded. ####
