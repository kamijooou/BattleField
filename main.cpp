#include <iostream>
using namespace std;

int field[10][10] = {
  {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
  {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int check(int arr[10][10]);

int main()
{
  int a = check(field);
  cout << a << endl;
}

int check(int arr[10][10])
{
  //Здесь проверяем, чтобы корабли были правильно расставлены
  int checkArr[12][12];//Расширяем поле до 12х12, чтобы не попадать на ненулевой мусор при проверке на границах массива
  
  for (int i = 0; i < 12; i++){
    checkArr[0][i] = 0;
    checkArr[11][i] = 0; 
  }
  
  for (int i = 1; i < 11; i++){
    checkArr[i][0] = 0;
    checkArr[i][11] = 0;
  }
  
  for (int i = 1; i < 11; i++){
    for (int j = 1; j < 11; j++){
      checkArr[i][j] = arr[i-1][j-1];
    }
  }

  for (int i = 1; i < 11; i++){
    for (int j = 1; j < 11; j++){
      if (checkArr[i][j] == 1){
        if ((checkArr[i-1][j+1] != 0) ||
            (checkArr[i+1][j+1] != 0) ||
            (checkArr[i-1][j-1] != 0) ||
            (checkArr[i+1][j-1] != 0)) {return 0;}
      }
    }
  }
  /////////////////////

  //Здесь проверяем, чтобы не было 5-палубников и т.д. + считаем кол-во кораблей для третьей проверки
  int normalShips[] = {4, 3, 2, 1};
  int userShips[] = {0, 0, 0, 0};
  int counter = 0;

  for (int i = 1; i < 11; i++){
    for (int j = 1; j < 11; j++){
      if (checkArr[i][j] == 1){
        checkArr[i][j] = 2; //Красим клетки, чтобы не ходить по ним дважды
        ++counter;
        if (checkArr[i][j+1] == 1){
          checkArr[i][j+1] = 2;
          ++counter;
          if (checkArr[i][j+2] == 1){
            checkArr[i][j+2] = 2;
            ++counter;
            if (checkArr[i][j+3] == 1){
              checkArr[i][j+3] = 2;
              ++counter;
              if (checkArr[i][j+4] == 1){
                return 0;
              }
            }
          }
        }
        if (checkArr[i+1][j] == 1){
          checkArr[i+1][j] = 2;
          ++counter;
          if (checkArr[i+2][j] == 1){
            checkArr[i+2][j] = 2;
            ++counter;
            if (checkArr[i+3][j] == 1){
              checkArr[i+3][j] = 2;
              ++counter;
              if (checkArr[i+4][j] == 1){
                return 0;
              }
            }
          }
        }
        ++userShips[counter-1];
        counter = 0;
      }
    }
  }
  //////////////////////

//Здесь проверяем количество кораблей   
  for (int i = 0; i < 4; i++){
    if (normalShips[i] != userShips[i]) {return 0;}
  }

  return 1;
}