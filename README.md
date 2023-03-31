# Tic-Tac-Toe Computervision-robot
# Introduction
this project was part of a half year prosess in the subject "technology and science" at Ullern VGS where we (the students) could choose our own project. 

our project is a tic-tac-toe robot, that is fully autonomous. The robot sees via its camera, "thinks" by the help of the minimax algorithm and moves with the help of a servo motor, arduino based arm. 

the projects ecosystem is then based on the information flow from camera -> computer -> arduino:
![image](https://user-images.githubusercontent.com/92923535/196031242-1bc67bfb-bee0-4e38-b3ff-3e5aef0f86ba.png)

The minimax algorithm and some of the game functions is based on Cledersonbc's minimax algorithm for tic-tac-toe. too get a more in depth explenation about this see: https://github.com/Cledersonbc/tic-tac-toe-minimax

# A brief program explenation
The camera is the only sensor used in this project. The image taken by the camera does not provide much information, but it is passed on to Python where the data in the image is analyzed and used to, for example, see that a chip has been moved. In Python, the camera information is used in two functions: seeboard(minutes) and playermove(board). in both of these functions, the cv2 library is used to find the color blue or red in the image. In playermove(board) this is used to find where a new move has been placed. Furthermore, in the playermove(board) function, the mediapipe library is also used to see hands in the image, to then stop search for the color red or blue. In seeboard(minutes) the cv2 library is used, to then draw an outline of found pieces to create a visual image of what the robot sees:

![IMG-7124](https://user-images.githubusercontent.com/92923535/196032210-b7949e0b-6c6f-4316-85e5-c901f0709029.jpg)
![IMG-7125](https://user-images.githubusercontent.com/92923535/196032212-e02134c6-d6f2-4934-95fd-35d5d4dc12bb.jpg)

After the program has detected the pieces, found out the game state and used the minimax algorithm to calculate the next move, it sends a signal to the arduino. Since there are nine routes and five places the robot arm can pick up the pieces, there are 45 different values that can be sent. The program on the arduino converts this signal into two values, a value for which slot it should put the chip in and a value for where it should pick up the chip:

![image](https://user-images.githubusercontent.com/92923535/196032246-05a66044-e50a-4aca-879b-bce5b8f2801e.png)

In the arduino file, we first translate the value we get from python (incomingByte) into two values, dataval is route and chip is where it should pick up the chip.
Example if incomingByte = 'a' then the robot will pick up the chip in position 1 since chip = 1 and put it in position 1 since dataval = 1. to see how this is converted in python program see line 638 in functions.py file:

![image](https://user-images.githubusercontent.com/92923535/196032290-e4efaf73-c075-4160-866c-725b7e398719.png)

# Arduino circuit: 
![image](https://user-images.githubusercontent.com/92923535/196031305-26034fe3-a27b-44f7-b47b-3fd815e8246a.png)

# pictures
<br> the drawn vision of the finished robot from the start of the semester and finished robot:
<br> ![image](https://user-images.githubusercontent.com/92923535/196031628-01bc2e85-5289-4eae-8ab2-f534e63299fe.png)
<br> ![image](https://user-images.githubusercontent.com/92923535/196031416-8fcfd1de-fdb2-44fc-b976-bc96f3b4da77.png)
