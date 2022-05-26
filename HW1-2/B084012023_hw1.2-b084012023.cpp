//Author : B084012023 鄭鈺丞
//Date : Oct. 9, 2021
//Purpose : 利用陣列算出階層用以解決使用int時會產生overflow的問題
#include <iostream>
using namespace std;

int main() {
	int n;									//設立n變數用以判斷使用者所需要的階層數
	while (cin >> n && n) {					//重複執行直到使用者輸入0來結束迴圈
		int a, length = 1, index;		    //設定a變數用以判斷目前跑到的階層數, length判斷陣列長度, index表示目前要處理的第幾陣列
		int arr[25] = { 0 };				//利用陣列儲存數字
		for (a = 1; a <= n; a++) {
			if (a == 1) {
				arr[0] = a;
			}
			for (index = 0; index < length; index++) {  //將陣列中所有數字乘以目前第a階層
				arr[index] = arr[index] * a;
			}
			for (index = 0; index < length; index++)	//判斷陣列中的數字是否需要進位到下一個
				if (arr[index] > 10) {
					arr[index + 1] += arr[index] / 10;
					arr[index] = arr[index] % 10;
						if (index == (length - 1))		//若是產生新的位數則長度會加1
							length++;
				}
				cout << a << "!= ";						//列印出來
				for (index = length-1; index >= 0; index--) {
					cout << arr[index];
			}
			cout << endl;
				
		}
		cout << endl;
	}
		return 0;
	}


