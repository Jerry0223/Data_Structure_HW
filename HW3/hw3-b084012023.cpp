// Author : B084012023 鄭鈺丞
// Date : Oct 31, 2021
// Purpose : 判斷西洋棋騎士能否走完N*N棋盤的順序，並利用Stack儲存所走過紀錄
#include<iostream>
using namespace std;
void knight(int num);											//建立函式判斷棋子是否走完全部棋盤

class Stack														//利用class實作Stack
{
public:
	Stack(int stackCapacity = 36);
	bool IsEmpty() const;
	int Top() const;
	void Push(const int item);
	void Pop();
private:
	int* stack;
	int top;
	int capacity;
};

Stack::Stack(int stackCapacity) :
	capacity(stackCapacity)											//創立容量為36的array
{
	stack = new int[capacity];
	top = -1;
}

inline bool Stack::IsEmpty() const
{
	return top == -1;												//判斷stack是否為空
}

inline int Stack::Top() const
{
	return stack[top];												//顯示目前最上層的數值
}
void Stack::Push(const int x)
{
	if (top == capacity - 1)
		throw "Stack is full";										//放入一個新增的值
	stack[++top] = x;
}

void Stack::Pop()
{
	if (IsEmpty())
		throw "Stack is empty.";									//刪除最上層的數值
	stack[top--].~int();
}

int main(){
	cout << "1 * 1 Board:" << endl;									//判斷各式N*N的棋盤
	knight(1);
	cout << "2 * 2 Board:" << endl;
	knight(2);
	cout << "3 * 3 Board:" << endl;
	knight(3);
	cout << "4 * 4 Board:" << endl;
	knight(4);
	cout << "5 * 5 Board:" << endl;
	knight(5);
	cout << "6 * 6 Board:" << endl;
	knight(6);

	return 0;
}

void knight(int num1) {
	Stack stk;													
	int board[6][6] = { 0 };										//建立6*6之矩陣						
	int col = 0, row = 0;
	int num, a = 1;
	board[0][0] = 1;												//在棋盤1之1的部分設為起點並為1
	for (int n = 2; n <= (num1 * num1); n++) {						//總共進行n*n的迴圈
		for (int o = 1; o <= 8; o++) {								//判斷棋子走法的8種情況
			if (o == 1) {
				if (((row - 2) < 0 || (col + 1) >= num1) || board[row - 2][col + 1] != 0)	//若是走法超出棋盤或是點上已走過則Continue到下一個走法
					continue;
				else {												//若走到的陣列值為0且在棋盤內則Push(百位數為Row,十位數為Column,個位數為第幾個走法
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);	
					row -= 2, col += 1;								
					board[row][col] = n;							//移動至該位置並填上目前為第幾步
					break;											//結束並從下一步開始
				}
			}
			if (o == 2) {
				if (((row - 1) < 0 || (col + 2) >= num1) || board[row - 1][col + 2] != 0)	//原理同上到 O == 7
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row -= 1, col += 2;
					board[row][col] = n;
					break;
				}
			}
			if (o == 3) {
				if (((row + 1) >= num1 || (col + 2) >= num1) || board[row + 1][col + 2] != 0)
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row += 1, col += 2;
					board[row][col] = n;
					break;
				}
			}
			if (o == 4) {
				if (((row + 2) >= num1 || (col + 1) >= num1) || board[row + 2][col + 1] != 0)
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row += 2, col += 1;
					board[row][col] = n;
					break;
				}
			}
			if (o == 5) {
				if (((row + 2) >= num1 || (col - 1) < 0) || board[row + 2][col - 1] != 0)
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row += 2, col -= 1;
					board[row][col] = n;
					break;
				}
			}
			if (o == 6) {
				if (((row + 1) >= num1 || (col - 2) < 0) || board[row + 1][col - 2] != 0)
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row += 1, col -= 2;
					board[row][col] = n;
					break;
				}
			}
			if (o == 7) {
				if (((row - 1) < 0 || (col - 2) < 0) || board[row - 1][col - 2] != 0)
					continue;
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row -= 1, col -= 2;
					board[row][col] = n;
					break;
				}
			}
			if (o == 8) {									
				if (((row - 2) < 0 || (col - 1) < 0) || board[row - 2][col - 1] != 0) {		//O == 8為最後一種走法，因此不行則需倒退至上一步
					if (n == 2) {															//若是n = 2則代表已試過所有方法皆不行因此break並結束迴圈
						cout << "No Solution!!" << endl;									
						n = 1;																//設定n = 1為判斷是否結束判斷
						break;
					}
					while (o == 8) {														//迴圈到O不等於8為止					
						num = stk.Top();													//取出目前Stack最上層的值
						stk.Pop();															//刪除Stack最上層的值
						n -= 1;																//倒退1步
						o = num % 10;													
						num /= 10;
						col = num % 10 - 1;													//依序從百位數、十位數、個位數取出Row、Column、O
						num /= 10;
						row = num % 10 - 1;
						if (o == 1)															//將目前走到的最後一步改為0
							board[row - 2][col + 1] = 0;		
						else if (o == 2)
							board[row - 1][col + 2] = 0;
						else if (o == 3)
							board[row + 1][col + 2] = 0;
						else if (o == 4)
							board[row + 2][col + 1] = 0;
						else if (o == 5)
							board[row + 2][col - 1] = 0;
						else if (o == 6)
							board[row + 1][col - 2] = 0;
						else if (o == 7)
							board[row - 1][col - 2] = 0;
						else if (o == 8)
							board[row - 2][col - 1] = 0;
					}
				}
				else {
					stk.Push((row + 1) * 100 + (col + 1) * 10 + o);
					row -= 2, col -= 1;
					board[row][col] = n;
					break;
				}
			}
		}
		if (n == 1) {													//結束迴圈(代表沒有方法可以走完棋盤)
			break;
			a = 0;
		}
	}
	for (int n = 0; n < num1; n++)
		for (int o = 0; o < num1; o++)									//判斷是否走完棋盤若陣列有0則代表沒有
			if (board[n][o] == 0)
				a = 0;
	if(a == 1)															//若有走完棋盤走印出來
		for (int n = 0; n < num1; n++) {
			for (int o = 0; o < num1; o++) {
				if (board[n][o] < 10 && num1 <= 3)						//調整列印格式
					cout << board[n][o] << " ";
				else if (board[n][o] < 10)
					cout << " " << board[n][o] << " ";
				else
					cout << board[n][o] << " ";
			}
			cout << endl;
		}
	cout << endl;
}	
