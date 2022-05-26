// Author : B084012023 鄭鈺丞
// Date : Nov 7, 2021
// Purpose : 判斷西洋棋騎士能否走完num*num棋盤的順序，並利用遞迴方式進行。
#include<iostream>
# define long 6
using namespace std;
int RunKnight(int r, int c, int count, int board[long][long],   //建立函式判斷棋子是否走完全部棋盤
    int row[], int col[], int num);
int Knight(int num);                                            //建立函式判斷棋子是否走完全部棋盤

int main()
{
    cout << "1 * 1 Board:" << endl;					            //判斷各式N*N的棋盤		
    Knight(1);
    cout << "2 * 2 Board:" << endl;
    Knight(2);
    cout << "3 * 3 Board:" << endl;
    Knight(3);
    cout << "4 * 4 Board:" << endl;
    Knight(4);
    cout << "5 * 5 Board:" << endl;
    Knight(5);
    cout << "6 * 6 Board:" << endl;
    Knight(6);
    return 0;
}

int Knight(int num)
{
    int board[long][long];                                          //建立6*6陣列

    for (int n = 0; n < num; n++)                                   //總共進行n*n的迴圈
        for (int o = 0; o < num; o++)
            board[n][o] = 0;

    int row[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int col[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        
    board[0][0] = 1;                                                //在棋盤1之1的部分設為起點並為1

    if (RunKnight(0, 0, 2, board, row, col, num) == 0) {            //若是跑完所有遞迴無結果則列印不存在  
       	cout << "Solution does not exist" << endl;
        cout << endl;
        return 0;
    }
    else {
        for (int n = 0; n < num; n++) {     
            for (int o = 0; o < num; o++) {
                if (board[n][o] < 10 && num <= 3)						//若有走完棋盤走印出來
                    cout << board[n][o] << " ";
                else if (board[n][o] < 10)
                    cout << " " << board[n][o] << " ";                  //調整列印格式
                else
                    cout << board[n][o] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return 1;
    }
}

int RunKnight(int r, int c, int count, int board[long][long], int row[8], int col[8], int num)
{
    int next_row, next_col;
    if (count == num * num+1)                                           //若跑完棋盤上的陣列則return1
        return 1;
    for (int m = 0; m < 8; m++) {
        next_row = r + row[m];                                          //設定下一步的走法
        next_col = c + col[m];
        if (board[next_row][next_col] == 0 && next_row >= 0 && next_row < num && next_col >= 0 && next_col < num) {     //判斷走法是否在陣列內且無人經過
            board[next_row][next_col] = count;
            if (RunKnight(next_row, next_col, count + 1, board, row, col, num)== 1)        //判斷下一步走法
                return 1;
            else           
                board[next_row][next_col] = 0;                            //若不行則設為0且回上一步
        }
    }
    return 0;
}
