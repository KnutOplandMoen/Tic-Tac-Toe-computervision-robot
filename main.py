# -*- coding: utf-8 -*-
"""
main file
"""

import serial
import functions as f
import cv2

HUMAN = -1
COMP = +1

#defining serial port and baud rate
ser = serial.Serial('COM3', 9600)  

def main():
    """
    Main function that calls all functions
    """
    while True:  
        
        board = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
        ]
        
        BR1 = 1
        BR2 = 2
        BR3 = 3
        BR4 = 4
        BR5 = 5
        
        f.clean()
        h_choice = 'B'  
        c_choice = 'R'   
        
        vid = cv2.VideoCapture(1)
        f.say('heeellllooooo, my name is Steve. lets play a game of tictactoe')
        
        f.clean()
        
        humanfirst = True
    
        while len(f.empty_cells(board)) > 0 and not f.game_over(board):
            if not humanfirst:
                aimove = f.ai_turn(c_choice, h_choice, board)
                BR1, BR2, BR3, BR4, BR5 = f.bricknumber(aimove, BR1, BR2, BR3, BR4, BR5)
                brick = max([BR1, BR2, BR3, BR4, BR5])
                send = f.arduinomove(aimove, brick)
                print('\nplacing brick number', brick-10,'in tile number', aimove)
                f.sendarduino(send, ser)
                f.say('your, turn')
                humanfirst = True
            
            hmove = f.human_turn(c_choice, h_choice, board, vid) 
            if hmove == 'finished':
                break
            
            aimove = f.ai_turn(c_choice, h_choice, board) 
            if aimove == 'finished':
                break          
            
            BR1, BR2, BR3, BR4, BR5 = f.bricknumber(aimove, BR1, BR2, BR3, BR4, BR5)
            brick = max([BR1, BR2, BR3, BR4, BR5])
            send = f.arduinomove(aimove, brick)
            print('\nplacing brick number', brick-10,'in tile number', aimove)
            f.sendarduino(send, ser)
            f.say('your, turn')
            
            
        if f.wins(board, HUMAN):
            f.clean()
            f.say('good game, you won')
            f.render(board, c_choice, h_choice)
            print('Human wins!')
            if not f.new():
                break
            
        elif f.wins(board, COMP):
            f.clean()
            f.say('noob, you cant even win against me')
            f.render(board, c_choice, h_choice)
            print('You lost!')
            if not f.new():
                break
            
        else:
            f.clean()
            f.render(board, c_choice, h_choice)
            f.say('it is a tie.')
            print('tie!')
            if not f.new():
                break


if __name__ == '__main__':
    main()

#closing serial port 
ser.close()
