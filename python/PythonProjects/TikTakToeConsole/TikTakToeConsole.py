board = [" " for _ in range(9)] 

def display_board():
    for i in range(9):
        print(board[i] if board[i] != " " else str(i+1), end="")
        if i % 3 != 2:
            print(" | ", end="")
        else:
            print()
        if i % 3 == 2 and i != 8:
            print("--+---+--")


def player_move(player):
    while(True):
        try: 
            move = int(input(f"Player {player}, choose a position (1-9, 0 to quit): "))
            if move == 0:
                return "quit"
            
            move = int(move) - 1
            if move < 0 or move > 8:
                print("Invalid position. Choose 1-9")
            elif board[move] != " ":
                print("That spot is already taken.")

            else:
                board[move] = player
                break

        except ValueError:
            print("Please enter a number between 1 and 9.")

def check_win(player):
    win_combinations = [
        [0,1,2], [3,4,5],[6,7,8],
        [0,3,6], [1,4,7],[2,5,8],
        [0,4,8], [2,4,6]
    ]
    for combo in win_combinations:
        if all(board[i] == player for i in combo):
            return True
    return False

def clear_board():
    for i in range(9):
        board[i] = " "

def restart():
    while True:
            stc = input("Play Again..?(y/N)")
            if stc.lower() == 'y':
                clear_board()
                return True
            elif stc.lower() == 'n':
                return False
            else :                  
                print("Please Enter a valid option")

philia = True
while(philia):
    current_player = "X"
    while True :
        display_board()
        result = player_move(current_player)
        if(result == "quit"):
            print("Game exited")
            philia = False
            break
        if check_win(current_player):
            display_board()
            print(f"Player {current_player} wins!")
            philia = restart()
            break
        if " " not in board:
            display_board()
            print("It is a tie!")
            philia = restart()
            break
        current_player = "O" if current_player == "X" else "X"
