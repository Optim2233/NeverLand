class TikTakToe:
    def __init__(self):
        self.board = [" " for _ in range(9)]
        self.current_player = 'X'
    def displayBoard(self):
        for i in range(9):
            print(self.board[i] if self.board[i] != " " else str(i+1), end="")
            if i % 3 != 2:
                print("  |  ",end="")
            else:
                print()
            if i % 3 == 2 and i != 8:
                print("---+-----+---")
    def playerMove(self):
        while True:
            try:
                move = int(input(f"Player {self.current_player}, Chose your position (1-9 || 0 to quit"))
                if move == 0: return "quit"
                move = int(move) - 1 
                if move < 0 or move > 8:
                    print("Please enter a valid number")
                elif self.board[move] != " ":
                    print("Position has been already taken. Please choose another position")
                else:
                    self.board[move] = self.current_player
                    break
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
    def clear_board(self):
        for i in range(9):
            self.board[i] = " "

    def restart(self):
        while True:
            stc = input("Play again..?(y/N)")
            if(stc.lower() == 'y'):
                self.clear_board()
                self.current_player = "X"
                return True
            elif(stc.lower() == 'n'):
                return False
            else:
                print("Please enter a valid option")
        
game = TikTakToe()
philia = True

while(philia):
    game.displayBoard()
    result = game.playerMove()
    if(result == "quit"):
        print("Exitting Game...")
        philia = False
        break
    if(game.check_win()):
        game.displayBoard()
        print(f"Player {game.current_player} wins")
        philia = game.restart()
        break
    if(" " not in game.board):
        game.displayBoard()
        print("It is a tie.")
        philia = game.restart()
        break
    game.current_player = "O" if game.current_player == "X" else "X"
