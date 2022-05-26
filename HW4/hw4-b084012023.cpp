// Author : B084012023 �G౥�
// Date : Nov 7, 2021
// Purpose : �P�_��v���M�h��_����num*num�ѽL�����ǡA�çQ�λ��j�覡�i��C
#include<iostream>
# define long 6
using namespace std;
int RunKnight(int r, int c, int count, int board[long][long],   //�إߨ禡�P�_�Ѥl�O�_���������ѽL
    int row[], int col[], int num);
int Knight(int num);                                            //�إߨ禡�P�_�Ѥl�O�_���������ѽL

int main()
{
    cout << "1 * 1 Board:" << endl;					            //�P�_�U��N*N���ѽL		
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
    int board[long][long];                                          //�إ�6*6�}�C

    for (int n = 0; n < num; n++)                                   //�`�@�i��n*n���j��
        for (int o = 0; o < num; o++)
            board[n][o] = 0;

    int row[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int col[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        
    board[0][0] = 1;                                                //�b�ѽL1��1�������]���_�I�ì�1

    if (RunKnight(0, 0, 2, board, row, col, num) == 0) {            //�Y�O�]���Ҧ����j�L���G�h�C�L���s�b  
       	cout << "Solution does not exist" << endl;
        cout << endl;
        return 0;
    }
    else {
        for (int n = 0; n < num; n++) {     
            for (int o = 0; o < num; o++) {
                if (board[n][o] < 10 && num <= 3)						//�Y�������ѽL���L�X��
                    cout << board[n][o] << " ";
                else if (board[n][o] < 10)
                    cout << " " << board[n][o] << " ";                  //�վ�C�L�榡
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
    if (count == num * num+1)                                           //�Y�]���ѽL�W���}�C�hreturn1
        return 1;
    for (int m = 0; m < 8; m++) {
        next_row = r + row[m];                                          //�]�w�U�@�B�����k
        next_col = c + col[m];
        if (board[next_row][next_col] == 0 && next_row >= 0 && next_row < num && next_col >= 0 && next_col < num) {     //�P�_���k�O�_�b�}�C���B�L�H�g�L
            board[next_row][next_col] = count;
            if (RunKnight(next_row, next_col, count + 1, board, row, col, num)== 1)        //�P�_�U�@�B���k
                return 1;
            else           
                board[next_row][next_col] = 0;                            //�Y����h�]��0�B�^�W�@�B
        }
    }
    return 0;
}
