#include<iostream>
#include<string>

//прогон по строкам или в заданном порядке (базисная функция)
char xySet (std::string str1, std::string str2, std::string str3, int x, int y) {
   if (x== 0 ) return str1[y];
   if (x== 1 ) return str2[y];
   if (x== 2 ) return str3[y];
   return 0;
}
//проверка на корректность ввода данных
bool properInput (std::string rowOne,std::string rowTwo,std::string rowThree) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            char sit = xySet(rowOne, rowTwo, rowThree, x, y);
            if (sit != 'X' && sit != 'O' && sit != '.') return false;
        }
    }
    return true;
}

int checkWhoTheWinner (std::string rowOne, std::string rowTwo,std::string rowThree, char sign);
int numberMovePlayer (std::string rowOne, std::string rowTwo,std::string rowThree, char sign);

int main()
{
   std::string rowOne;
   std::string rowTwo;
   std::string rowThree;
   std::cout << " Please enter strings, without spaces using X, O or . instead of a space ! "; // БЕЗ ПРОБЕЛОВ
   std::cout << "\n ***************************************************************************"<<"\n";
   std::cout << " First line : "<<"\n";
   std::getline(std::cin,rowOne);
   std::cout << " Second line : "<<"\n";
   std::getline(std::cin,rowTwo);
   std::cout << " Third line : "<<"\n";
   std::getline(std::cin,rowThree);

bool pi = properInput ( rowOne, rowTwo, rowThree);
int winPlayerX = checkWhoTheWinner(rowOne, rowTwo, rowThree, 'X');
int winPlayerO = checkWhoTheWinner(rowOne, rowTwo, rowThree, 'O');
int numMovX = numberMovePlayer(rowOne, rowTwo, rowThree, 'X');
int numMovO = numberMovePlayer(rowOne, rowTwo, rowThree, 'O');

//проверка на корректность ввода данных
    if(rowOne.length() !=3 || rowTwo.length() !=3 || rowThree.length() !=3 )
    std::cout << "\n"<<" Invalid symbols (incorrect string length ) !"<<"\n";
    else if(!pi){
    std::cout << "\n"<<" Invalid symbols (allowed only X or O or . ) !"<<"\n";
    }

//проверка на ошибочность побед
    else if (winPlayerX > 0 && winPlayerO > 0) {
    std::cout << "Incorrect (there are multiple winners at the same time)";
    }
    else if (winPlayerX > 1 || winPlayerO > 1) {
    std::cout << "Incorrect (zeros or crosses have won several times)";
    }

//проверка на некорректные победы и ничью 
    else if (numMovX < numMovO){
    std::cout << "Incorrect (more zeros than crosses)";   
    }
    else if (winPlayerO > 0 && numMovX != numMovO){
    std::cout << "Incorrect (zeros win, but the number of crosses is wrong)";   
    }
    else if (winPlayerX > 0 && numMovX-1 != numMovO){
    std::cout << "Incorrect (crosses win, but the number of zeros is wrong)";   
    }
    
//"чистые" победы и ничьи
    else if (winPlayerX > 0) std::cout << "Petya won!";
    else if (winPlayerO > 0) std::cout << "Vasya won!";
    else if (numMovX + numMovO < 9) std::cout << "Draw (the game's not over)";
    else if (numMovX == 9 - numMovO) std::cout << "Draw!";
    return 0;
}

//------------------------------------------------------------------------------------------------------//
int checkWhoTheWinner (std::string rowOne, std::string rowTwo,std::string rowThree, char sign) {
    int count = 0;
// победы по строкам
    for (int x = 0, y = 0; x < 3; x++, y=0) {
        if (xySet(rowOne,rowTwo,rowThree,x,y++) == sign &&
            xySet(rowOne,rowTwo,rowThree,x,y++) == sign &&
            xySet(rowOne,rowTwo,rowThree,x,y++) == sign) count++;
    }
// победы по столбцам
    for (int x = 0, y = 0; y < 3; y++, x=0) {
        if (xySet(rowOne,rowTwo,rowThree,x++,y) == sign &&
            xySet(rowOne,rowTwo,rowThree,x++,y) == sign &&
            xySet(rowOne,rowTwo,rowThree,x++,y) == sign) count++;
    }
// проверяем диагональные победы
    if (xySet(rowOne,rowTwo,rowThree,0,0) == sign &&
        xySet(rowOne,rowTwo,rowThree,1,1) == sign &&
        xySet(rowOne,rowTwo,rowThree,2,2) == sign) count++;

    if (xySet(rowOne,rowTwo,rowThree,2,0) == sign &&
        xySet(rowOne,rowTwo,rowThree,1,1) == sign &&
        xySet(rowOne,rowTwo,rowThree,0,2) == sign) count++;
    return count;
}
//----------------------------------------------------------------------------------------------------//
int numberMovePlayer (std::string rowOne, std::string rowTwo,std::string rowThree, char sign)
{
 int count = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (xySet(rowOne, rowTwo, rowThree, x, y) == sign) count++;
        }
    }
    return count;
}
