#include <iostream>
#include <string>
#include <ctime>

void Board(char PlayMat[8][8]);
int MovePlayer(int &points, char piece, char PlayMat[8][8]);
int MoveAI(char piece, char PlayMat[8][8]);

int main(){

    srand (time(NULL));
int points = 0;

char piece;
char play;

char PlayMat[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

int test;

    std::cout << " Welcome to C++ hess ! " << '\n';
    std::cout << " Do you want to play a game of chess ? (Y/N) " << '\n';

  std::cin >> play;
  play = toupper(play);



    do{
  if(play == 'Y'){
        std::cout << " Get ready to play !" << '\n';
        break;
    }

  else if(play == 'N'){
        std::cout << "Aw..." << '\n';
        return 0;
    }

  else{
        std::cout << " Sorry i didn't understand that. " << '\n';
        return 1;
    }

    }while(play != 'Y' && play != 'N');



        Board(PlayMat);
do{
    MovePlayer(points, piece, PlayMat);
    Board(PlayMat);
    std::cout << "Play?";
    std::cin >> test;
}while(test !=1);
        



    return 0;
}


void Board(char PlayMat[8][8]){

std::cout << "   A   B   C   D   E   F   G   H   " << '\n';

    for(int i = 0; i < 8 ; i++){
    std::cout << " +---+---+---+---+---+---+---+---+" << '\n';
    std::cout << 1 + i  << "| ";
        for (int j = 0; j < 8; j ++){
            std::cout<< PlayMat[i][j] <<" | ";
        }
        std:: cout << '\n';
    }

std::cout << " +---+---+---+---+---+---+---+---+" << '\n';
}

int MovePlayer(int &points, char piece, char PlayMat[8][8]){


    int Select_Row = 0;
    int Select_Collumn = 0;
    int move_Horizontal = 0;
    int move_Vertical = 0;

    //This variable is used for selecting the type of move you want to make with a special piece (King or Queen).
    int type;


    std::cout << "Please chose the piece to move ." << '\n';
    
    std::cout << "Please chose the Row (1-8). " << '\n';
    std::cin >> Select_Row;
    //We decrease 1 each time, because the array always reads the number with 1 lower.
    Select_Row --;

    std::cout << "Please enter the Collumn  (A-H), " << '\n';
    std::cin >> Select_Collumn;
    Select_Collumn = toupper(Select_Collumn) - 1;

    int StartRow = Select_Row;
    int startCol = Select_Collumn;

    // These statements are used to tell the player that he can' t use the AI's pieces.
    if(PlayMat[Select_Row][Select_Collumn] == 'p'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'r'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'n'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'b'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'k'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'q'){
        std::cout << "You can't select other player's pawn ! " << '\n';
    }

    //This is used to invalidate the empty space.
    else if (PlayMat[Select_Row][Select_Collumn] == ' '){
        std::cout << " You can't select blank spaces. " << '\n';
    }

    //These statements are used for the player's pieces.

    //PAWN
    if (PlayMat[Select_Row][Select_Collumn] == 'P'){
        std::cout << " Please select how many spaces do you want to move. " << '\n';
        std::cin >> move_Vertical;
        std::cout << " If there are any pieces diagonally , you can move too, else please insert 0. " << '\n';
        std::cin >> move_Horizontal;
        if(move_Vertical > 2 || move_Vertical < 1 ){
            std::cout << "Invalid move. " << '\n';
            return 1;
        }

        else if(move_Vertical == 2 && PlayMat[StartRow - move_Vertical][startCol] == ' '){
            PlayMat[StartRow - move_Vertical][startCol] = 'P';
            PlayMat[StartRow][startCol] = ' ';
        }

        else if(move_Vertical == 1 && PlayMat[StartRow - move_Vertical][startCol] == ' '){
            PlayMat[StartRow - move_Vertical][startCol] = 'P';
            PlayMat[StartRow][startCol] = ' ';
        }

        else if(move_Vertical == 1 && move_Horizontal == 1 && PlayMat[StartRow - move_Vertical][startCol + move_Horizontal] != ' '){
             PlayMat[StartRow - move_Vertical][startCol + move_Horizontal] = 'P';
            PlayMat[StartRow][startCol] = ' ';
            points++;
        }
        
        else if(move_Vertical == 1 &&  move_Horizontal == 1 && PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] != ' '){
            PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] = 'P';
            PlayMat[StartRow][startCol] = ' ';
            points++;
        }

        else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }

        else {
            std::cout << "The path is blocked. You can only move 1 or 2 tiles in front of you if the path is clear, or move 1 tile horizontally if there is a enemy piece there. " << '\n';
        }
    }

    //KNIGHT
    if (PlayMat[Select_Row][Select_Collumn] == 'N'){
        std::cout << " Please select where you want to move the piece. (Use positive numbers to go up/right , and negative to go down/left). " << '\n';
        std::cout << "Select the number of tiles to move foward . (No more than 2 or less than -2)." << '\n';
        std::cin >> move_Vertical;
        std::cout << " Move in an L shape. (3x2 / 2x3)." <<'\n';
        std::cout << "Select the number of tiles to move to the sides . (No more than 2 or less than -2)." << '\n';
        std::cin >> move_Horizontal;

        if((move_Vertical == 2 && move_Horizontal == 1) ||
            (move_Vertical == 2 && move_Horizontal == -1) ||
            (move_Vertical == -2 && move_Horizontal == 1) ||
            (move_Vertical == -2 && move_Horizontal == -1) ||
            (move_Vertical == 1 && move_Horizontal == 2) ||
            (move_Vertical == 1 && move_Horizontal == -2) ||
            (move_Vertical == -1 && move_Horizontal == 2) ||
            (move_Vertical == -1 && move_Horizontal == -2)){

            if(PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] == ' '){
            PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] = 'N';
            PlayMat[StartRow][startCol] = ' ';
            }

            else if(PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] != ' '){
            PlayMat[StartRow - move_Vertical][startCol - move_Horizontal] = 'N';
            PlayMat[StartRow][startCol] = ' ';
        }
        else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }
        }

        else{
            std::cout << "You can only move in an L shape !" << '\n';
        }
    }

    //ROOK
    if (PlayMat[Select_Row][Select_Collumn] == 'R'){
        std::cout << "Please select if you want to move horizontally (1) or vertically (2). " << '\n';
        std::cin >> type;

        if(type == 1){
            std::cout << "Please select how many spaces do you want to move (use positive numbers to go right and negative to go left). " << '\n';
            std::cin >> move_Horizontal;

            if(move_Horizontal > 8){
                std::cout << "Invalid move." << '\n';
            }

            if(PlayMat[StartRow][startCol - move_Horizontal] == ' '){
                PlayMat[StartRow ][startCol - move_Horizontal] = 'R';
                PlayMat[StartRow][startCol] = ' ';
            }
            
            if(PlayMat[StartRow][startCol - move_Horizontal] != ' '){
                PlayMat[StartRow ][startCol - move_Horizontal] = 'R';
                PlayMat[StartRow][startCol] = ' ';
                points++;
            }
            else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }
        }

        else if(type ==2){
            std::cout << "Please select how many spaces do you want to move (use positive numbers to go up and negative to go down). " << '\n';
            std::cin >> move_Vertical;

            if(move_Vertical > 8){
                std::cout << "Invalid move." << '\n';
            }

            if(PlayMat[StartRow - move_Vertical][startCol] == ' '){
                PlayMat[StartRow- move_Vertical][startCol] = 'R';
                PlayMat[StartRow][startCol] = ' ';
            }
            
            if(PlayMat[StartRow - move_Vertical][startCol] != ' '){
                PlayMat[StartRow - move_Vertical][startCol] = 'R';
                PlayMat[StartRow][startCol] = ' ';
                points++;
            }
            else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }
        }

        
    }

    //BISHOP
    if (PlayMat[Select_Row][Select_Collumn] == 'B'){
        std::cout << " (You can only move diagonally)." << '\n';
        std::cout << " Please chose how many tiles to move foward(YOU NEED THE EXACT SAME NUMBER FOR THE HORIZONTAL TOO). " << '\n';
        std::cin >> move_Vertical;
        std::cout << " Please chose how many tiles to move(YOU NEED THE EXACT SAME NUMBER FOR THE VERTICAL TOO). " << '\n';
        std::cin >> move_Horizontal;

        if(move_Horizontal == move_Vertical){

            if(PlayMat[StartRow - startCol][startCol - move_Horizontal] == ' '){
                    PlayMat[StartRow - startCol][startCol - move_Horizontal] = 'Q';
                    PlayMat[StartRow][startCol] = ' ';
            }
                
            else if(PlayMat[StartRow - startCol][startCol - move_Horizontal] != ' '){
                    PlayMat[StartRow - startCol][startCol - move_Horizontal] = 'Q';
                    PlayMat[StartRow][startCol] = ' ';
                    points++;
            }

            if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
            }

            else if(move_Horizontal != move_Vertical){
                std::cout << "You didn't move vertically." <<'\n';
            }    
            }
    }

    //QUEEN
    if (PlayMat[Select_Row][Select_Collumn] == 'Q'){
        std::cout << " Please select where you want to move the piece.(Type 1 for vertical, 2 for horizontal, 3 for vertical). " << '\n';
        std::cin >> type;
        if(type == 1){
        std::cout << "Enter how many spaces you want to move. (Positive to move foward, and negative to move backwards.)" << '\n';
        std::cin >> move_Vertical;

        if(PlayMat[StartRow - move_Vertical][startCol] == ' '){
                PlayMat[StartRow - move_Vertical][startCol] = 'Q';
                PlayMat[StartRow][startCol] = ' ';
            }

        else if(PlayMat[StartRow - move_Vertical][startCol] != ' '){
                PlayMat[StartRow - move_Vertical][startCol] = 'Q';
                PlayMat[StartRow][startCol] = ' ';
                points++;
            }

        else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }                
        }
        

        if(type == 2){
            std::cout << "Enter how many spaces you want to move. " << '\n';
            std::cin >> move_Horizontal;

        if(PlayMat[StartRow][startCol - move_Horizontal] == ' '){
                PlayMat[StartRow][startCol - move_Horizontal] = 'Q';
                PlayMat[StartRow][startCol] = ' ';
            }

        else if(PlayMat[StartRow][startCol - move_Horizontal] != ' '){
                PlayMat[StartRow][startCol - move_Horizontal] = 'Q';
                PlayMat[StartRow][startCol] = ' ';
                points++;
            }

              else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }                
        }
        
        if(type == 3){
            std::cout << " Please chose how many tiles to move foward(YOU NEED THE EXACT SAME NUMBER FOR THE HORIZONTAL TOO). " << '\n';
            std::cin >> move_Vertical;
            std::cout << " Please chose how many tiles to move(YOU NEED THE EXACT SAME NUMBER FOR THE VERTICAL TOO). " << '\n';
            std::cin >> move_Horizontal;

            if(move_Horizontal == move_Vertical){

                if(PlayMat[StartRow - startCol][startCol - move_Horizontal] == ' '){
                    PlayMat[StartRow - startCol][startCol - move_Horizontal] = 'Q';
                    PlayMat[StartRow][startCol] = ' ';
                }
                
                else if(PlayMat[StartRow - startCol][startCol - move_Horizontal] != ' '){
                    PlayMat[StartRow - startCol][startCol - move_Horizontal] = 'Q';
                    PlayMat[StartRow][startCol] = ' ';
                    points++;
                }

                else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'K' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q'){
                    std::cout << "You can't go over your own pieces !" <<'\n';
                }
            else if(move_Horizontal != move_Vertical){
                std::cout << "You didn't move vertically." <<'\n';
            }    
            }
        }
    }

    //KING
    if (PlayMat[Select_Row][Select_Collumn] == 'K'){
        std::cout << " Please select where you want to move the piece. (You can only move one tile in any direction). " << '\n';
        std::cin >> move_Vertical;
        std::cin >> move_Horizontal;

        if(move_Vertical > 1 || move_Horizontal > 1){
            std::cout << "Too far!" <<'\n';
        }

        if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == ' '){
            PlayMat[StartRow- move_Vertical][startCol - move_Horizontal] = 'K';
            PlayMat[StartRow][startCol] = ' ';
        }

        else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] != ' '){
            PlayMat[StartRow- move_Vertical][startCol - move_Horizontal] = 'K';
            PlayMat[StartRow][startCol] = ' ';
            points++;
        }

        else if(PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'P' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'R' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'N' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'B' ||
                PlayMat[Select_Row - move_Vertical][Select_Collumn - move_Horizontal] == 'Q')
                {
                std::cout << "You can't go over your own pieces !" <<'\n';
        }        
    }
    return 0;
}

int MoveAI(char piece, char PlayMat[8][8]){

    int SELECT = rand() % 6;
    int row = rand() % 8;
    int collumn = rand() % 8;
    int action = rand() % 4;

    switch(SELECT){
        case 0 : {PlayMat[row][collumn] == 'p';  //pawx
        }
            break;
        case 1 : {} //rook
            break;
        case 2 : {} //knight
            break;
        case 3 : {} //bishop
            break;
        case 4 : {} // queen
            break;
        case 5 : {} //king
            break;    
        default : return 1;
    }
    return 0;
}