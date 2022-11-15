Alt-Alphabot (Maze Traversing Bot)
======
## Politechnika Poznanska (WARiE)
### Term Design Project (Group 5)

#### Students : Ram Ellanki, Mohamed Majdouline.
#### Instructor : Mgr inz. Jan Wietrzykowski
------
### Introduction

   The Aim of the project is to traverse a maze using AlphaBot2 – Ar. We used additional sensors (Ultrasonic sensor) to make it easy to the bot to detect the walls and to traverse the maze. This project also includes various versions and algorithms to confirm which suits best for the bot and building various prototypes of mazes including the final moderate level testing maze. The best likely suitable algorithm for our alphabot is wall algorithm using one additional senor but with  unique setup.

### BASE PLATFORM (ALPHABOT2 – AR)
 
   AlphaBot2-Ar robot kits includes a chassis (AlphaBot2-Base chassis) and an adapter board AlphaBot2-Ar. The robot supports Arduino with AlphaBot2-Ar adapter board. The platform comes with everything we needed including wheels with ball supports on the bottom section of the bot and thanks to this modular design it was very easy to assemble the whole bot without any additional wiring or soldering unless we want to use soem additional sensors other than on – board. It also comes with various options and chips for communicating or connecting the additioanl sensors which we actually didn’t used most of them. The complete description of all the base platform can found in AlphaBot2 – Ar. 

### ADDITIONAL SENSORS

   To make it easier to traverse the maze we added an additional ultrasonic sensor (HC-SR04) to the alphabot. Thanks to this sensor we were able to implement the wall – following algorithm much easier to the AlphaBot2 base platform. 
      
* ULTRASONIC SENSOR (HC-SR04) :
     
     Ultrasonic ranging module HC-SR04 provides 2cm - 400cm non-contact measurement function, the ranging accuracy can reach to 3mm. The modules includes ultrasonic transmitters, receiver and control circuit.It works with a 5V power supply.

* PLACEMENT OF HC-SR04 :
      
     The Additional sensor we added on the base platform AlphaBot2 – Ar is responsible to detect the walls on its right side and follow it and at the same time to detect the obstacles or a freeway between the bot and the walls. The base platform already consists of same sensor on – board in the front which we used it to detect the obstacles and  move forward. We placed the additional sensor on the top left of the bot but with a twist where the sensor actually faced towards right direction and follows the walls on the right side. We applied this concept here so that the sensor can work properly without any minimum distance range issues. To connect this additional sensor, we removed the jumpers of DOUT and ADDR on the bot and used the pins 11 and 12 from the Arduino to connect the sensor’s ECHO and TRIG pins.
<p align="center">
 <img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Screenshot_10.png" width="400" height="300" />

<p align="center">
<img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Picture5.png" width="400" height="300" />



### MAZE
  
 To test the behavior of AlphaBot2 – Ar we build a special maze starting with a simple maze followed by a complex maze. The construction is fully made with cardboard. But for the final test we used one of our colleagues maze which was made with wood.

<p align="center">
      <img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Picture1.png" width="400" height="300" />

### SOFTWARE AND HARDWARE IMPLEMENTATION

* SPECIFICATION :
      
     The platform is supposed to follow the wall on its right side. Based on the signal received from the sensors it should detect whether the wall is on front or right side or a free way to change the lanes.

* IMPLEMENTATION :
      
     Several Arduino compliant C++ libraries were used for the purpose of motor and sensor handling. Some of the code is provided in the examples from the manufacturer. All the library files that are used in our code are uploaded in our GitHub repository to which the instructor has full access. In the listing below, the algorithm that we used in our bot is presented.
[MazeSolver](https://github.com/RamEllanki/Alphabot/blob/main/Final_MazeSolver.ino)
      
* CONCLUSION :
      
     The bot was able to solve the maze although the obtained results are not perfect but satisfactory. The reason it is not perfect because it is getting stuck at the edges of the maze while traversing due to sharp edge of the alphabot around its body. Because of this issue the bot needs a little back support sometimes when it is stuck in this scenario. Other than this issue out maze successfully was able to traverse the maze in first try without any back support which is a great progress.

### SUMMARY

  We successfully finished this project although with little drawbacks. Thanks to this project which helps us to gain more knowledge about different types of bots and their nature of working. After finishing this project we can say that it is more interesting in this field and gaining knowledge more about Robots. The following images are taken in the process of whole project.

<p align="center">
      <img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Picture4.jpg" width="400" height="300" />
<p align="center">
      <img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Picture3.png" width="400" height="300" />
<p align="center">
      <img src="https://github.com/RamEllanki/Alphabot/blob/main/Images/Picture2.png" width="400" height="300" />

### References
[WaveShare](https://www.waveshare.com/wiki/AlphaBot2-Ar)
      
[Bot_Manual](https://www.mouser.com/pdfdocs/Alphabot2-user-manual-en.pdf)
