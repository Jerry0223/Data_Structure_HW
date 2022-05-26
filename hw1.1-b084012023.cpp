// Author : col084012023 鄭鈺丞
// Date : Oct 9, 2021
// Purcole : 利用陣列表示出1、3、5、7、9階的魔方陣
#include <iostream>
using namespace std;
void magic_square(int num);

int main() {
	magic_square(1);				//依序列印出每層魔方陣
	magic_square(3);
	magic_square(5);
	magic_square(7);
	magic_square(9);
	return 0;
}

void magic_square(int num1) {
	int n;
	int col, row = 0;
	int arr[9][9] = { 0 };			//設定9*9之陣列
	for (n = 1; n <= (num1 * num1 ); n++, col--, row--) {		//設定迴圈將數字填入二元陣列中
		if(n == 1){
			col = ((num1 + 1) / 2) - 1;							//按照題目規定將1放入最上面row中間處
			arr[row][col] = 1;
			continue;
		}
		if (col < 0)											//條件判斷:若是往左往上移在陣列之外則移到最右邊或最下面
			col = num1 - 1;
		if (row < 0)
			row = num1 - 1;
		if (arr[row][col] != 0)									//條件判斷:若是要填入時已經有數字時則往下移以此類推
		{
			col += 1;
			row += 1;
			if (col > (num1 - 1))
				col = 0;
			if (row > (num1 - 1))
				row = 0;
			row += 1;
			if (row > (num1 - 1))
				row = 0;
		}
		arr[row][col] = n;		
	}
		cout << num1 << " layer of magic square" << endl;		//列印出來
		for (row = 0; row < num1;row++)
		{
			for (col = 0; col < num1; col++) {
				if (arr[row][col] < 10 && num1 <= 3)			//依照數字格式排列整齊
					cout << arr[row][col] << " ";
				else if (arr[row][col] < 10)
					cout << " " << arr[row][col] << " ";
				else
					cout << arr[row][col] << " ";
			}
			cout << endl;
		}
		cout << endl;

}
