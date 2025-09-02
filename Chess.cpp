#include <iostream>
#include <string>
#include <ctime>

enum Collums {A , B , C , D , E , F , G ,H}; // This uses makes the letter for Rows on the board, into valid input numbers.
enum Color {White , Black};

void Board(char PlayMat[8][8]);
int MovePlayer(char PlayMat[8][8]);
int MoveAI(char PlayMat[8][8]);


class Piece {
    public:
    char Symbol;
    bool alive = true;
    Color color;

};

class Pawn : public Piece {
    char Symbol = 'p';
};

class Rook : public Piece{
    public:
 char Symbol;
};

class Knight : public Piece{
    public:
    char Symbol = 'n';
};

class Bishop : public Piece{
    public:
    char Symbol = 'b';
};

class Queen : public Piece{
    public:
    char Symbol = 'q';
};

class King : public Piece{
    public:
    char Symbol = 'k';
};



int main(){

    srand (time(NULL));


char play;

char PlayMat[8][8] = {
    {'n', 'r', 'b', 'q', 'k', 'b', 'r', 'n'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'N', 'R', 'B', 'Q', 'K', 'B', 'R', 'N'}
};



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

        MovePlayer(PlayMat);



    return 0;
}


void Board(char PlayMat[8][8]){

std::cout << "   A   B   C   D   E   F   G   H   " << '\n';

    for(int i = 0; i < 8 ; i++){
    std::cout << " +---+---+---+---+---+---+---+---+" << '\n';
    std::cout << 8 - i  << "| ";
        for (int j = 0; j < 8; j ++){
            std::cout<< PlayMat[i][j] <<" | ";
        }
        std:: cout << '\n';
    }

std::cout << " +---+---+---+---+---+---+---+---+" << '\n';
}

int MovePlayer(char PlayMat[8][8]){


    int Select_Row;
    int Select_Collumn;


    std::cout << "Please chose the piece to move ." << '\n';

    
    std::cout << "Please chose the Row (1-8). " << '\n';
    std::cin >> Select_Row;
    std::cout << "Please enter the Collumn  (A-H), " << '\n';
    std::cin >> Select_Collumn;

    if(PlayMat[Select_Row][Select_Collumn] == 'p'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'r'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'n'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'b'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'k'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if(PlayMat[Select_Row][Select_Collumn] == 'q'){
        std::cout << "You can't select other player's pawn ! " << '\n';
        return 1;
    }

    else if (PlayMat[Select_Row][Select_Collumn] == ' '){
        std::cout << " You can't select blank spaces. " << '\n';
        return 1;
    }

    

    return 0;
}

int MoveAI(char PlayMat[8][8]){

    int SELECT = rand() % 6;
    int row = rand() % 8;
    int collumn = rand () % 8;

    switch(SELECT){
        case 0 : {  //pawx
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