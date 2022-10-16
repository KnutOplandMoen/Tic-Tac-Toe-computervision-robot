# Tic-Tac-Toe Computervision-robot
<br> the drawn vision of the finished robot from the start of the semester:
<br> ![image](https://user-images.githubusercontent.com/92923535/196031628-01bc2e85-5289-4eae-8ab2-f534e63299fe.png)
<br> Robot in action at the showcase event at the end of the semester:
<br> ![image](https://user-images.githubusercontent.com/92923535/196031416-8fcfd1de-fdb2-44fc-b976-bc96f3b4da77.png)


# introduction
this project was part of a half year prosess in the subject "technology and science" at Ullern VGS. 

The minimax algorithm and some game functions is based on Cledersonbc's minimax algorithm for tictactoe. too get a more in depth explenation about this see: https://github.com/Cledersonbc/tic-tac-toe-minimax

the projects ecosystem is based on the information flow from camera -> computer -> arduino:
![image](https://user-images.githubusercontent.com/92923535/196031242-1bc67bfb-bee0-4e38-b3ff-3e5aef0f86ba.png)

# program explenation
The camera is the only sensor used in this project. The image taken by the camera does not provide much information, but it is passed on to Python where the data in the image is analyzed and used to, for example, see that a chip has been moved. In Python, the camera information is used in two functions: seeboard(minutes) and playermove(board). in both of these functions, the cv2 library is used to find the color blue or red in the image. In playermove(board) this is used to find where a new move has been placed. Furthermore, in the playermove(board) function, the mediapipe library is also used to see hands in the image, to then stop search for the color red or blue. In seeboard(minutes) the cv2 library is used, to then draw an outline of found pieces to create a visual image of what the robot sees.

After the program has detected the pieces, found out the game state and used the minimax algorithm to calculate the next move, it sends a signal to the arduino. Since there are nine routes and five places the robot arm can pick up the pieces, there are 45 different values that can be sent. The program on the arduino converts this signal into two values, a value for which slot it should put the chip in and a value for where it should pick up the chip.

In the arduino file, we first translate the value we get from python (incomingByte) into two values, dataval is route and chip is where it should pick up the chip.
Example if incomingByte = 'a' then the robot will pick up the chip in position 1 since chip = 1 and put it in position 1 since dataval = 1. to see how this is converted in python program see line 638 in functions.py file. 

# arduino circuit: 
![image](https://user-images.githubusercontent.com/92923535/196031305-26034fe3-a27b-44f7-b47b-3fd815e8246a.png)


