Intro: 
<img width="779" height="457" alt="image" src="https://github.com/user-attachments/assets/20915634-5525-4e46-8589-eec0e85e5fc7" />



The MECBOT is a robotic vehicle designed to autonomously navigate through unstructured paths, avoid dynamic obstacles, and adjust its speed based on environmental feedback.

Overview: 
This project was developed as part of a Mechatronics System Design class to apply principles of autonomous navigation, sensor integration, and electromechanical design. MECBOT features a custom-designed gearbox with a DC motor for optimized transmission, an ultrasonic sensor for real-time obstacle detection, and an LDR (Light Dependent Resistor) sensor for light-based path tracking. A closed-loop PID controller was implemented to adjust the vehicle's speed autonomously, using real-time sensor data to provide feedback for continuous control. All logic was implemented using an Arduino Uno with embedded C programming.

Features: 
•	Autonomous navigation and obstacle avoidance
•	Real-time speed adjustment
•	Light-based path tracking safety feature
•	Custom electromechanical design (gearbox, chassis)

How to build:
Electronic Components:
•	830 Tie-Points Breadboard
•	Arduino Uno R3 Controller Board
•	Micro Servo Motor
•	DC Motor
•	L293 Motor Driver
•	Jumper Wires
•	9V Battery
•	Ultrasonic Sensors 
•	LDR Photoresistors 
•	1k Ω Resistors
Mechanical Components:
•	Plastic Base
•	Rubber Wheels
•	Metal Chassis
•	Carboard Square
•	Wooden Block
•	Toy Gear Box

Step-by-Step Instructions:
1. Connecting the Ultrasonic Sensor (HC-SR04):
•	Connect VCC to the positive rail of the breadboard.
•	Connect GND to the negative rail of the breadboard.
•	Connect Trig to Arduino Uno digital pin 7.
•	Connect Echo to Arduino Uno digital pin 6.
2. Connecting the LDR Sensors (Light Dependent Resistors):
Each LDR should be part of a voltage divider circuit using a resistor.
•	Connect one terminal of each LDR to the positive rail of the breadboard.
•	Connect the second terminal of the first LDR to Arduino Uno analog pin A3.
•	Connect the second terminal of the second LDR to Arduino Uno analog pin A0.
3. Connecting the Resistors for LDRs:
•	Connect one end of a 10kΩ resistor to the junction point between the LDR and analog input (A3 or A0).
•	Connect the other end of the resistor to GND.
•	Repeat for the second LDR.
4. Connecting the Servo Motor:
•	Connect the red wire (VCC) to the positive rail of the breadboard.
•	Connect the black wire (GND) to the negative rail of the breadboard.
•	Connect the yellow or orange wire (signal) to Arduino Uno digital pin 9.
5. Connecting the L293D Motor Driver:
•	Insert the L293D chip into the breadboard across the center gap.
•	Connect pin 1 (Enable 1) to Arduino Uno digital pin 5.
•	Connect pin 2 (Input 1) to Arduino Uno digital pin 4.
•	Connect pin 7 (Input 2) to Arduino Uno digital pin 3.
•	Connect pin 4 and pin 5 (GND) to the negative rail of the breadboard.
•	Connect pin 8 (VCC2 - motor supply) to the positive rail of the breadboard (or external motor power supply).
•	Connect pin 16 (VCC1 - logic supply) to 5V from Arduino.
6. Connecting the DC Motor:
•	Connect the positive (red) wire of the DC motor to L293D pin 3 (Output 1).
•	Connect the negative (black) wire of the motor to L293D pin 6 (Output 2).

Custom GearBox: <img width="710" height="239" alt="image" src="https://github.com/user-attachments/assets/7a029ec5-aa36-4188-8e2b-2a9e6de8a7f1" />

Calibration: 
•	Once the ultrasonic and LDR sensor circuits are set up, perform static calibration to eliminate unexpected readings. Place a block at a fixed distance and send ultrasonic waves via the Trig pin to check accuracy.
•	For the LDR sensor, place it under a dark spot to avoid ambient light interference. Use a torch or phone flashlight and shine it at the top of the sensor to test response.
•	To tune the PID controller, start by modeling the DC motor and power supply in Simulink. Add a PID Controller block and define a step input. Use the PID Tuner to auto-tune the controller and analyze the system response. Finally, export the tuned PID gains for implementation in the Arduino code.

MATLAB Simulink Block Diagram: 
<img width="948" height="373" alt="image" src="https://github.com/user-attachments/assets/d71598e8-1814-471b-96de-5e2f74f7d6fd" />

CAD Model: 
<img width="344" height="258" alt="image" src="https://github.com/user-attachments/assets/c97b35c9-d336-4aff-b2ff-1d18c7b4fbce" />


How to use:
Loading code to Arduino Uno
•	Connect Arduino Uno board to computer via USB
•	Open the MECBOT.ino file in Arduino IDE
•	Make sure to select correct Board and COM port from the Tools menu
•	Click Upload 
•	Disconnect the USB 
Running the Bot:
•	Connect battery back to Arduino Uno
•	Place the MECBOT on the floor
•	Turn on the power

Expected Outcome:
•	After completing the hardware setup, sensor calibration, and PID tuning, the robot is placed on the floor and begins operation. It initially checks for obstacles using the ultrasonic sensor. If no obstacle is detected, the robot starts moving forward. When an obstacle is detected ahead, the robot slows down and gradually coming to a stop. The ultrasonic sensor continues scanning the environment, and the robot adjusts its motor speed using a PID control loop based on the measured distance to the obstacle. This allows the robot to respond dynamically to changes in its surroundings, ensuring smooth and autonomous navigation.
