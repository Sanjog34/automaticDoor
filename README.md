# Automatic Door
 # background 
The arena of the competition is simple. Two line folllowing bots race with each other and the one completing the arena first wins. But, at the end of arena there is a door. The door opens after 5 seconds after it detects the bot and closes after another 5 seconds. So the bot has to wait for their respective door to open and has to cross the door within 5 seconds after it opens. So, our goal is to control the detection of two bots, holding time,  and opening and closing of two doors which are independent of each other using a single Arduino board.
![img](https://github.com/Sanjog34/automaticDoor/blob/main/images/door.jpg)

 
# Electronics
1. Arduino uno
2. servo motor x2
3. ultrasonic sensor x2



  # Working

 Arduino uno is capable of reading or controlling data fron only one device at a time. But we've got two ultrasonic sensors and two servo motors which should be active all the time. If arduino senses vehicle at door 1, the arduino will have to give attention to door 1 for 10 seconds. If within that 10 seconds, vehicle arrives at door 2 the arduino wouldn't even know about it since it is busy executing the code for door 1. So, to solve this, the program is divided into three functions :-

 
 ![img](https://github.com/Sanjog34/automaticDoor/blob/main/images/function.png)

 *   checkDistance function returns the distance read by two ultrasonic sensors.
 *   openGate function opens the gate.
 *   closeGate function closes the gate.

 ## code explanation
Two global integer variables 'check1' and 'check2' for door 1 and door 2 respectively are declared. value of both check1 and check2 is set to 0 (indicating the doors are closed). first, we get the values read by two ultrasonic sensors from the checkDistance function. then it is checked if 'check1'(for door 1) is 0. i.e(if the door is close). if check1 is 0 then distance is checked. if the distance is less than 20 cm (as per the arena), the value of check1 is changed to 1 to indicate that the sensor has detected the vehicle. The time of that instant(when the vehicle passed the sensor) is read using millis();.(Returns the number of milliseconds since the device began running the current program). Then openGate function is called passing the parameters gateno and the instant. In the openGate function, we check if 5 seconds have passed since the sensor detected the vehicle. If 5 seconds haven't passed yet, the program doesn't get stuck here. Instead, it goes back to the loop function (from where the openGate(); was called) and does the same process for door 2 and updates the value of check2 as per reading. Now, let's assume 5 seconds have passed(for gate 1). we then open the door (rotating servo motor by the desired degree) and set the value of check1 to 2(indicating the door is opened). In loop function, when check1/check2 equals 2, closeGate(); is called. This function is the same as openGate and at the end of this function value of check1/check2 is set to 0.
