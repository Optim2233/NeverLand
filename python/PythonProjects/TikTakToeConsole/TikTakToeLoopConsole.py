import random
import time

class colors:
    GREEN = '\033[92m'    #player
    BLUE = '\033[94m'     # AI
    YELLOW = '\033[93m'   # Last move
    RESET = '\033[0m'     # Reset color
    GRAY = '\033[90m'     # oldest-of-3 marker (dim/gray)

class TikTakToe:
    def __init__(self):
        self.board = [" " for _ in range(9)]
        self.current_player = 'X'
        self.ai_vs = True
        self.player_moves = []
        self.ai_moves = []
        self.player_oldest_marker = None
        self.ai_oldest_marker = None
    def displayBoard(self, lastMove = None):
        for i in range(9):
            char = self.board[i]
            if i == lastMove:
                disp = f"{colors.YELLOW}{char}{colors.RESET}"
            elif i == self.player_oldest_marker or i == self.ai_oldest_marker:
                disp = f"{colors.GRAY}{char}{colors.RESET}"
            elif char == 'X':
                disp = f"{colors.GREEN}{char}{colors.RESET}"
            elif char == "O":
                disp = f"{colors.BLUE}{char}{colors.RESET}"
            else:
                disp = str(i+1)

            print(disp, end="")
            if i % 3 != 2:
                print("  |  ",end="")
            else:
                print()
            if i % 3 == 2 and i != 8:
                print("---+-----+---")
    def playerMove(self):
        while True:
            try:
                move = int(input(f"Player {self.current_player}, choose your position (1-9 || 0 to quit): "))
                if move == 0: return "quit"
                move -= 1 
                if move < 0 or move > 8:
                    print("Please enter a valid number")
                elif self.board[move] != " ":
                    print("Position has been already taken. Please choose another position")
                else:
                    self.board[move] = self.current_player
                    self.track_move(self.current_player, move)
                    return move
            except ValueError:
                print("Invalid Value Entered. Please try a valid number")

    def check_win(self):
        win_combinations = [
            [0,1,2],[3,4,5],[6,7,8],
            [0,3,6],[1,4,7],[2,5,8],
            [0,4,8],[2,4,6]
        ]
        for combo in win_combinations:
            if all(self.board[i] == self.current_player for i in combo):
                return True
        return False
    
    def check_win_for(self,player):
        win_combinations = [
            [0,1,2],[3,4,5],[6,7,8],
            [0,3,6],[1,4,7],[2,5,8],
            [0,4,8],[2,4,6]
        ]
        for a,b,c in win_combinations:
            if self.board[a] == self.board[b] == self.board[c] == player:
                return True
        return False
    def clear_board(self):
        for i in range(9):
            self.board[i] = " "
        self.player_moves = []
        self.ai_moves = []
        self.player_oldest_marker = None
        self.ai_oldest_marker = None
    def restart(self):
        while True:
            stc = input("Play again..?(y/N)").lower()
            if(stc == 'y'):
                self.clear_board()
                self.current_player = "X"
                return True
            elif(stc == 'n' or stc == ''):
                return False
            else:
                print("Please enter a valid option")
    def play_round(self):
        self.displayBoard()
        self.current_player = "X"
        while True:
            move_index = None
            if self.current_player == "O" and self.ai_vs == True:
                print("AI is thinking....")
                move_index = self.ai_move()
            else: 
                move_index = self.playerMove()    
                if move_index == "quit":
                    print("Exiting Game.....")
                    return "quit"
            self.displayBoard(lastMove=move_index)
            if self.check_win():
                self.displayBoard()
                print(f"Player {self.current_player} wins!")
                return "finished"
            if " " not in self.board:
                self.displayBoard()
                print("It is a tie!")
                return "finished"
            
            self.current_player = "O" if self.current_player == "X" else "X"


    def ai_move(self):
        
        emptyPositions = [i for i in range(9) if self.board[i] == " " ]
        if not emptyPositions: return
        opponent = "O" if self.current_player == "X" else "X"
        for pos in emptyPositions:
            self.board[pos] = self.current_player
            if self.check_win_for(self.current_player):
      
                self.track_move(self.current_player, pos)
                return pos
            self.board[pos] = " "

        emptyPositions = [i for i in range(9) if self.board[i] == " "]
        for pos in emptyPositions:
            self.board[pos] = opponent
            if self.check_win_for(opponent):
                self.board[pos] = self.current_player
                self.track_move(self.current_player, pos)
                return pos
            self.board[pos] = " "

        emptyPositions = [i for i in range(9) if self.board[i] == " "]
        for preferred in [4,0,2,6,8,1,3,5,7]:
            if preferred in emptyPositions:
                self.board[preferred] = self.current_player
                self.track_move(self.current_player, preferred)
                return preferred

        time.sleep(0.3)
        move = random.choice(emptyPositions)
        self.board[move] = self.current_player
        self.track_move(self.current_player,move)
        return move
        
    def track_move(self,player,move_index):
        moves_list = self.ai_moves if player == "O" else self.player_moves
        moves_list.append(move_index)

        # choose correct marker attribute for this player
        if player == "O":
            marker_attr = 'ai_oldest_marker'
        else:
            marker_attr = 'player_oldest_marker'

        # exactly 3 moves -> mark the oldest (index 0)
        if len(moves_list) == 3:
            setattr(self, marker_attr, moves_list[0])

        # more than 3 moves -> remove the oldest and update marker
        if len(moves_list) > 3:
            oldest = moves_list.pop(0)
            # clear the board cell (the 4th move causes deletion of the oldest)
            self.board[oldest] = " "
            # if marker pointed to that old index, clear it
            if getattr(self, marker_attr) == oldest:
                setattr(self, marker_attr, None)
            # after popping, if there are now exactly 3 moves, mark the new oldest
            if len(moves_list) >= 3:
                setattr(self, marker_attr, moves_list[0])
            else:
                setattr(self, marker_attr, None)

        #elif len(moves_list) == 3:
         # oldest = moves_list[0]
          #self.board[oldest] = f"{colors.BLUE}{self.board[oldest]}{colors.RESET}"


game = TikTakToe()
philia = True

while(philia):
    result = game.play_round()
    if result == "quit":
        break
    if not game.restart():
        break

print("Thanks for your support!")
