# -*- coding: utf-8 -*-
"""
Created on Wed Feb 16 14:22:43 2022

this is the functions file in a total of three files that makes the full tictactoe game
project consists of 3 files (aprox 2200 lines of code):
main.py - main file
funcions.py - function file
arduinomove.ino - arduino file


this is the functions.py file, the file contains all functions used in the main.py file
and that are used to send bytes to the arduino serial port 
"""

from math import inf as infinity
from random import choice
import platform
from os import system
import cv2
import numpy as np
import speech_recognition as sr
import pyttsx3
import mediapipe as mp

HUMAN = -1
COMP = +1
        
def evaluate(state):
    """
    Function to heuristic evaluation of state.
    :param state: the state of the current board
    :return: +1 if the computer wins; -1 if the human wins; 0 draw
    """
    if wins(state, COMP):
        score = +1
    elif wins(state, HUMAN):
        score = -1
    else:
        score = 0
    return score


def wins(state, player):
    """
    This function tests if a specific player wins. Possibilities:
    * Three rows    [X X X] or [O O O]
    * Three cols    [X X X] or [O O O]
    * Two diagonals [X X X] or [O O O]
    :param state: the state of the current board
    :param player: a human or a computer
    :return: True if the player wins
    """
    win_state = [
        [state[0][0], state[0][1], state[0][2]],
        [state[1][0], state[1][1], state[1][2]],
        [state[2][0], state[2][1], state[2][2]],
        [state[0][0], state[1][0], state[2][0]],
        [state[0][1], state[1][1], state[2][1]],
        [state[0][2], state[1][2], state[2][2]],
        [state[0][0], state[1][1], state[2][2]],
        [state[2][0], state[1][1], state[0][2]],
    ]
    if [player, player, player] in win_state:
        return True
    else:
        return False


def game_over(state):
    """
    This function test if the human or computer wins
    :param state: the state of the current board
    :return: True if the human or computer wins
    """
    return wins(state, HUMAN) or wins(state, COMP)


def empty_cells(state):
    """
    Each empty cell will be added into cells' list
    :param state: the state of the current board
    :return: a list of empty cells
    """
    cells = []

    for x, row in enumerate(state):
        for y, cell in enumerate(row):
            if cell == 0:
                cells.append([x, y])

    return cells


def valid_move(x, y, board):
    """
    A move is valid if the chosen cell is empty
    :param x: X coordinate
    :param y: Y coordinate
    :return: True if the board[x][y] is empty
    """
    if [x, y] in empty_cells(board):
        return True
    else:
        return False


def set_move(x, y, player, board):
    """
    Set the move on board, if the coordinates are valid
    :param x: X coordinate
    :param y: Y coordinate
    :param player: the current player
    :return: True if move is placed 
    """
    if valid_move(x, y, board):
        board[x][y] = player
        return True
    else:
        return False


def minimax(state, depth, player):
    """
    AI function that choice the best move
    :param state: current state of the board
    :param depth: node index in the tree (0 <= depth <= 9),
    but never nine in this case (see iaturn() function)
    :param player: an human or a computer
    :return: a list with [the best row, best col, best score]
    """
    if player == COMP:
        best = [-1, -1, -infinity]
    else:
        best = [-1, -1, +infinity]

    if depth == 0 or game_over(state):
        score = evaluate(state)
        return [-1, -1, score]

    for cell in empty_cells(state):
        x, y = cell[0], cell[1]
        state[x][y] = player
        score = minimax(state, depth - 1, -player)
        state[x][y] = 0
        score[0], score[1] = x, y

        if player == COMP:
            if score[2] > best[2]:
                best = score  
        else:
            if score[2] < best[2]:
                best = score  
    return best


def clean():
    """
    Clears the console
    """
    os_name = platform.system().lower()
    if 'windows' in os_name:
        system('cls')
    else:
        system('clear')


def render(state, c_choice, h_choice):
    """
    Print the board on console
    :param state: current state of the board
    """
    chars = {
        -1: h_choice,
        +1: c_choice,
        0: ' '
    }
    str_line = '---------------'
    print('\n' + str_line)
    print('\nCurrent gamestate:')
    print('\n' + str_line)
    for row in state:
        for cell in row:
            symbol = chars[cell]
            print(f'| {symbol} |', end='')
        print('\n' + str_line)

def bricknumber(newposition, BR1, BR2, BR3, BR4, BR5):
    """
    finds the brick closest to the arm
    :param newposition: the wished position for the brick to be to placed in. 
    the new position for the first available  brick will be updated to the 
    new position of the brick
    :return: the brick that is closest to the robotic arm
    """
    
    bricks = [BR1, BR2, BR3, BR4, BR5]
    brick = min(bricks)
    
    if brick == BR1:
        BR1 = 11
    elif brick == BR2:
        BR2 = 12
    elif brick == BR3:
        BR3 = 13
    elif brick == BR4:
        BR4 = 14
    elif brick == BR5:
        BR5 = 15

    return BR1, BR2, BR3, BR4, BR5
        
def arduinomove(move, brick):
    """
    takes in:
    :param move: the tile that the brick wil be placed in
    :param brick: the position of the brick that will be moved
    converts both numbers, then adding them togheter as a string
    then converting this string back to a number
    :return: integer that will later be sent to the arduino file
    with a number that tells the arm the position of the brick it will 
    pick up, and what position it should move too 
    """
    move = str(move)
    brick = str(brick-10)
    send = move + brick
    send = int(send)
    return send 
        
def ai_turn(c_choice, h_choice, board):
    """
    It calls the minimax function if the depth < 9,
    else it choices a random coordinate.
    :param c_choice: computer's choice X or O
    :param h_choice: human's choice X or O
    :return:
    """
    global tilenumber
    
    depth = len(empty_cells(board))
    if depth == 0 or game_over(board):
        return 'finished'

    clean()
    render(board, c_choice, h_choice)

    if depth == 9:
        x = 1
        y = 1
        
    else:
        move = minimax(board, depth, COMP)
        x, y = move[0], move[1]
        
    set_move(x, y, COMP, board)
    if x == 0:
        if y == 0:
            tilenumber = 1
        elif y == 1:
            tilenumber = 2
        elif y == 2:
            tilenumber = 3
            
    elif x == 1:
        if y == 0:
            tilenumber = 4
        elif y == 1:
            tilenumber = 5
        elif y == 2:
            tilenumber = 6

    elif x == 2:
        if y == 0:
            tilenumber = 7
        elif y == 1:
            tilenumber = 8
        elif y == 2:
            tilenumber = 9
                          
    return tilenumber       

def seeboard(minutes):
    """
    function that displays the current board, including the bricks that the camera can see
    this function does not exclude every brick thats not placed on the board, so every brick can be seen 
    :param minutes: number of minutes that the image will be displayed (float or int)
    """
    import datetime

    endTime = datetime.datetime.now() + datetime.timedelta(minutes = minutes)
   
    cap = cv2.VideoCapture(1)

    x = 0
    while x < 100:
        success, img = cap.read()
        x+= 1
    
    while True:
        success, img = cap.read()

        #rød
        lower1 = np.array([0, 165, 20])
        upper1 = np.array([12, 255, 255]) 
        lower2 = np.array([160, 165, 20])
        upper2 = np.array([185, 255, 255])
        
        #blå
        lower3 = np.array([100, 165, 20])
        upper3 = np.array([130, 255, 255]) 
        lower4 = np.array([130, 165, 20])
        upper4 = np.array([135, 255, 255])
        
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) 
    
        mask1 = cv2.inRange(hsv, lower1, upper1) 
        mask2 = cv2.inRange(hsv, lower2, upper2)
        mask3 = cv2.inRange(hsv, lower3, upper3) 
        mask4 = cv2.inRange(hsv, lower4, upper4)
        mask = mask1 + mask2 + mask3 + mask4
        mask_contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
        if len(mask_contours) != 0:
            for mask_contour in mask_contours:
                if cv2.contourArea(mask_contour) > 500:
                    x, y, w, h = cv2.boundingRect(mask_contour)
                    cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 3)

        if datetime.datetime.now() >= endTime:
            print('\nElons move is finished')
            cv2.destroyAllWindows()   
            break  
        
        img = img[0:0+(int(img.shape[0])),0+(int(200)):0+(int(img.shape[1]))]
        cv2.imshow('elon wiew', img)
        cv2.waitKey(1)
                   
def playermove(board):
    """
    finds the move done by the human player
    tranforms the picture from the camera
    searches through each tile for the color red or blue
    (depending on what color the human is using)
    if color is detected, then a move is detected 
    if there is no brick in this tile from before, then 
    a this move is returned and the tile is updated 
    :param board: current gamestate
    :return: tile number where a move is detected
    """
    
    mpHands = mp.solutions.hands
    hands = mpHands.Hands()

    cap = cv2.VideoCapture(1)
    
    #warming up the camera
    x = 0
    while x < 150:
        success, img = cap.read()
        x+= 1
        
    move = 99
    
    while True:
        success, img = cap.read()
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = hands.process(imgRGB)
        
        if results.multi_hand_landmarks:
            img = img[0:0+(int(img.shape[0])),0+(int(200)):0+(int(img.shape[1]))]
            cv2.imshow('bilde', img)
            cv2.waitKey(1)
              
        if not results.multi_hand_landmarks:
            video = img 

            #rød
            lower1 = np.array([0, 165, 20])
            upper1 = np.array([12, 255, 255]) 
            lower2 = np.array([160, 165, 20])
            upper2 = np.array([185, 255, 255])
            
            #blå
            lower3 = np.array([100, 165, 20])
            upper3 = np.array([130, 255, 255]) 
            lower4 = np.array([130, 165, 20])
            upper4 = np.array([135, 255, 255])
            
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) 
        
            mask1 = cv2.inRange(hsv, lower1, upper1) 
            mask2 = cv2.inRange(hsv, lower2, upper2)
            mask3 = cv2.inRange(hsv, lower3, upper3) 
            mask4 = cv2.inRange(hsv, lower4, upper4)
            mask = mask1 + mask2 + mask3 + mask4
            
            mask_contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
        
            if len(mask_contours) != 0:
                for mask_contour in mask_contours:
                    if cv2.contourArea(mask_contour) > 40:
                        x, y, w, h = cv2.boundingRect(mask_contour)
                        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 3)
 
            img2 = video
            
            img2 = img2[0+(int(210)):0+(int(450)),0+(int(255)):0+(int(550))]
            
            #295 = x
            #240 = y
            
            A1 = img2[0+(int(0)):0+(int(40)),0+(int(20)):0+(int(80))]
            
            A2 = img2[0+(int(0)):0+(int(40)),0+(int(100)):0+(int(150))]
            
            A3 = img2[0+(int(0)):0+(int(40)),0+(int(190)):0+(int(270))] 
            
            B1 = img2[0+(int(75)):0+(int(120)),0+(int(0)):0+(int(70))]
            
            B2 = img2[0+(int(75)):0+(int(120)),0+(int(100)):0+(int(150))]
            
            B3 = img2[0+(int(75)):0+(int(120)),0+(int(190)):0+(int(270))]
            
            C1 = img2[0+(int(170)):0+(int(240)),0+(int(20)):0+(int(60))]
            
            C2 = img2[0+(int(170)):0+(int(240)),0+(int(90)):0+(int(150))] 
            
            C3 = img2[0+(int(170)):0+(int(240)),0+(int(200)):0+(int(270))]

            def foundred(square):
                lower = np.array([0, 165, 20])
                upper = np.array([12, 255, 255]) 
                lower2 = np.array([160, 165, 20])
                upper2 = np.array([185, 255, 255])
                
                
                hsv = cv2.cvtColor(square, cv2.COLOR_BGR2HSV) 
            
                mask1 = cv2.inRange(hsv, lower, upper) 
                mask2 = cv2.inRange(hsv, lower2, upper2)
                mask = mask1 + mask2
                
                mask_contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
            
                if len(mask_contours) != 0:
                    for mask_contour in mask_contours:
                        if cv2.contourArea(mask_contour) > 20:
                            x, y, w, h = cv2.boundingRect(mask_contour)
                            cv2.rectangle(square, (x, y), (x + w, y + h), (0, 0, 255), 3)
                            return True

                else:
                    return False
                
            def foundblue(square):
                lower = np.array([100, 165, 20])
                upper = np.array([130, 255, 255]) 
                lower2 = np.array([130, 165, 20])
                upper2 = np.array([135, 255, 255])
                
                hsv = cv2.cvtColor(square, cv2.COLOR_BGR2HSV) 
            
                mask1 = cv2.inRange(hsv, lower, upper) 
                mask2 = cv2.inRange(hsv, lower2, upper2)
                mask = mask1 + mask2
                
                mask_contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
            
                if len(mask_contours) != 0:
                    for mask_contour in mask_contours:
                        if cv2.contourArea(mask_contour) > 20:
                            x, y, w, h = cv2.boundingRect(mask_contour)
                            cv2.rectangle(square, (x, y), (x + w, y + h), (0, 0, 255), 3)
                            return True

                else:
                    return False
            
            move = 99
            
            if foundblue(A1) and board[0][0] == 0:
                 print('\nfound new brick in tile: A1')
                 move = 1
                 break
    
            elif foundblue(A2) and board[0][1] == 0:
                 print('\nfound new brick in tile: A2')
                 move = 2
                 break
                 
            elif foundblue(A3) and board[0][2] == 0: 
                 print('\nfound new brick in tile: A3')
                 move = 3
                 break
    
            elif foundblue(B1) and board[1][0] == 0: 
                 print('\nfound new brick in tile: B1')
                 move = 4
                 break
    
            elif foundblue(B2) and board[1][1] == 0: 
                 print('\nfound new brick in tile: B2')
                 move = 5
                 break
    
            elif foundblue(B3) and board[1][2] == 0:
                 print('\nfound new brick in tile: B3')
                 move = 6
                 break
    
            elif foundblue(C1) and board[2][0] == 0: 
                 print('\nfound new brick in tile: C1')
                 move = 7
                 break 
             
            elif foundblue(C2) and board[2][1] == 0: 
                 print('\nfound new brick in tile: C2')
                 move = 8
                 break
     
            elif foundblue(C3) and board[2][2] == 0:
                 print('\nfound new brick in tile: C3')
                 move = 9
                 break 
             
            img = img[0:0+(int(img.shape[0])),0+(int(200)):0+(int(img.shape[1]))]
            cv2.imshow('elon wiew', img)
            cv2.waitKey(1) 
            
    cv2.destroyAllWindows() 
   
    return(move)  
           
def human_turn(h_choice, c_choice, board, vid):
    """
    The Human plays choosing a valid move.
    :param c_choice: computer's choice X or O
    :param h_choice: human's choice X or O
    :return:
    """
    depth = len(empty_cells(board))
    if depth == 0 or game_over(board):
        return 'finished'

    move = 0
    moves = {
        1: [0, 0], 2: [0, 1], 3: [0, 2],
        4: [1, 0], 5: [1, 1], 6: [1, 2],
        7: [2, 0], 8: [2, 1], 9: [2, 2],
    }

    clean()

    while move < 1 or move > 9:
            render(board, h_choice, c_choice)
            move = playermove(board)
            move = int(move)
            coord = moves[move]
            set_move(coord[0], coord[1], HUMAN, board)
            
def new():
    """
    asking player for a new round
    :return: True if player wants new round
    """
    answer = input('\nnew round [yes/no]: ')
    if answer == 'yes':
        print('\nstarting new round')
        return True
    else:
        return False
        
def say(text):
    """
    makes the operating system on the computer "speak"
    :param text: Line of text that the computer should say
    """
    engine = pyttsx3.init()
    engine.setProperty('voice', 'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_DAVID_11.0')
    engine.say(text)
    engine.runAndWait()
    engine.stop()
      
def question(question, answer1, answer2):
    """
    asking the player a qustion and listening for an answer that matches predefined text
    :param question: question that the will be asked
    :param answer1: predefined text that can be an answer 
    :param answer2: predefined text that can be another answer
    :return: answer1, answer2 or command to quit
    """
    r = sr.Recognizer()
    answer = ''
    with sr.Microphone() as source:
        sound = r.adjust_for_ambient_noise(source, duration=1)
        while answer != answer1 or answer != answer2:
            try:  
                say(question)
                print('\nlistening for input')
                sound = r.listen(source, timeout=4)
                if sound == None:
                    sound = ''
                answer = r.recognize_google(sound)
                answer = str(answer)
                answer = list(answer.split(" "))

                print('\nlist of words that was heard by computer:', answer)

                for i in answer:
                    if i == answer1:
                        print('\nheard: ', i)
                        answer = answer1
                        break
                    elif i == answer2:
                        print('\nheard: ', i)
                        answer = answer2 
                        break

                if answer == answer1 or answer == answer2:
                    break
            
            except sr.UnknownValueError:
                say('i could not hear you, please repeat')
            except sr.RequestError as e:
                print("Could not request results; {0}".format(e))
                
    return answer
    
def sendarduino(move, ser):
    """
    sends a number to the arduino serial port
    :param move: a 2 digit number, where the first number is the tile where
    the number represent the tile that the brick will be moved too. 
    The second number represent the brick that will be moved
    """
    
    minutes = 0.5

    if move == 11:
        ser.write(b'a')
        seeboard(minutes)
    elif move == 21:
        ser.write(b'b')
        seeboard(minutes)
    elif move == 31:
        ser.write(b'c')
        seeboard(minutes)
    elif move == 41:
        ser.write(b'd')
        seeboard(minutes)
    elif move == 51:
        ser.write(b'e')
        seeboard(minutes)
    elif move == 61:
        ser.write(b'f')
        seeboard(minutes)
    elif move == 71:
        ser.write(b'g')
        seeboard(minutes)
    elif move == 81:
        ser.write(b'h')
        seeboard(minutes)
    elif move == 91:
        ser.write(b'i')
        seeboard(minutes)
        
    elif move == 12:
        ser.write(b'j')
        seeboard(minutes)
    elif move == 22:
        ser.write(b'k')
        seeboard(minutes)
    elif move == 32:
        ser.write(b'l')
        seeboard(minutes)
    elif move == 42:
        ser.write(b'm')
        seeboard(minutes)
    elif move == 52:
        ser.write(b'n')
        seeboard(minutes)
    elif move == 62:
        ser.write(b'o')
        seeboard(minutes)
    elif move == 72:
        ser.write(b'p')
        seeboard(minutes)
    elif move == 82:
        ser.write(b'q')
        seeboard(minutes)
    elif move == 92:
        ser.write(b'r')
        seeboard(minutes)
        
    elif move == 13:
        ser.write(b's')
        seeboard(minutes)
    elif move == 23:
        ser.write(b't')
        seeboard(minutes)
    elif move == 33:
        ser.write(b'u')
        seeboard(minutes)
    elif move == 43:
        ser.write(b'v')
        seeboard(minutes)
    elif move == 53:
        ser.write(b'w')
        seeboard(minutes)
    elif move == 63:
        ser.write(b'x')
        seeboard(minutes)
    elif move == 73:
        ser.write(b'y')
        seeboard(minutes)
    elif move == 83:
        ser.write(b'z')
        seeboard(minutes)
    elif move == 93:
        ser.write(b'A')
        seeboard(minutes)
    
    elif move == 14:
        ser.write(b'B')
        seeboard(minutes)
    elif move == 24:
        ser.write(b'C')
        seeboard(minutes)
    elif move == 34:
        ser.write(b'D')
        seeboard(minutes)
    elif move == 44:
        ser.write(b'E')
        seeboard(minutes)
    elif move == 54:
        ser.write(b'F')
        seeboard(minutes)
    elif move == 64:
        ser.write(b'G')
        seeboard(minutes)
    elif move == 74:
        ser.write(b'H')
        seeboard(minutes)
    elif move == 84:
        ser.write(b'I')
        seeboard(minutes)
    elif move == 94:
        ser.write(b'J')
        seeboard(minutes)
    
    elif move == 15:
        ser.write(b'K')
        seeboard(minutes)
    elif move == 25:
        ser.write(b'L')
        seeboard(minutes)
    elif move == 35:
        ser.write(b'M')
        seeboard(minutes)
    elif move == 45:
        ser.write(b'N')
        seeboard(minutes)
    elif move == 55:
        ser.write(b'O')
        seeboard(minutes)
    elif move == 65:
        ser.write(b'P')
        seeboard(minutes)
    elif move == 75:
        ser.write(b'Q')
        seeboard(minutes)
    elif move == 85:
        ser.write(b'R')
        seeboard(minutes)
    elif move == 95:
        ser.write(b'S')
        seeboard(minutes)
        
