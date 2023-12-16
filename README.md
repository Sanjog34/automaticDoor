# Automatic Door
 # background 
The arena of the competition is simple. Two line folllowing bots race with each other and the one completing the arena first wins. But, at the end of arena there is a door. The door opens after 5 seconds after it detects the bot and closes after another 5 seconds. So the bot has to wait for their respective door to open and has to cross the door within 5 seconds after it opens. So, our goal is to control the detection of two bots, holding time,  and opening and closing of two doors which are independent of each other using a single Arduino board.
![img](https://github.com/Sanjog34/automaticDoor/blob/main/images/door.jpg)

 
# Electronics
1. Arduino uno
2. servo motor x2
3. ultrasonic sensor x2



  # Working

 Arduino uno is capable of reading or controlling data fron only one device at a time. But we've got two ultrasonic sensors and two servo motors which should be active all the time. If arduino senses vehicle at door 1, the arduino will have to give attention to door 1 for 10 seconds. If within that 10 seconds, vehicle arrived at door 2 the arduino wouldn't even know about it since it is busy executing the code for door 1. So, to solve this, the program is divided into three functions :-
 ![img](https://github.com/Sanjog34/automaticDoor/blob/main/images/function.png)

 *   Distance function returns the distance read by two ultrasonic sensors.
 *   openGate function opens the gate.
 *   closeGate function closes the gate.

 ## void loop function
 ![img](https://github.com/Sanjog34/automaticDoor/blob/main/images/loop.png)
