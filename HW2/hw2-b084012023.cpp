//Author : 鄭鈺丞(B084012023)
//Date : Oct. 17, 2021
//Purpose :	利用Class進行「聯集」、「交集」、「差集」、「包含」、「屬於」等五種運算。
#include <iostream>
using namespace std;


class SetClass {											//宣告Class

private:

	bool content[256];										//建立布林變數來判斷輸入的字元

public:
	SetClass() {
		for (int i = 0; i < 256; i++)						//將設立的布林陣列全部改為False
			this->content[i] = false;
	}
	void operator=(const SetClass& set) {					//將輸入的字元讀取到Set陣列裡
		for (int i = 0; i < 256; i++)
			this->content[i] = set.content[i];
	}

	SetClass operator+(const SetClass& set) {				//聯集:將CaseA與CaseB陣列中True的值回傳到陣列
		SetClass Union = *this;
		for (int i = 0; i < 256; i++)
			if (set.content[i])
				Union.content[i] = true;
		return Union;
	}

	SetClass operator*(const SetClass& set) {				//交集:將CaseA與CaseB陣列中同樣為True的值回傳到陣列
		SetClass Intersection;
		for (int i = 0; i < 256; i++)
			if (set.content[i] && this->content[i])
				Intersection.content[i] = true;
		return Intersection;
	}

	SetClass operator-(const SetClass& set) {				//差集:同樣陣列位置CaseA中為True且CaseB中為False的值回傳到陣列
		SetClass Difference;
		for (int i = 0; i < 256; i++)
			if (this->content[i] && !set.content[i])
				Difference.content[i] = true;
		return Difference;
	}

	bool operator>=(const SetClass& set) {					//包含:類似差集的概念，若是同樣陣列位置CaseA有True的值而CaseB卻是False則回傳False(不包含的意思)，相反則True
		for (int i = 0; i < 256; i++)
			if (set.content[i] && !this->content[i])
				return false;
		return true;
	}
	
/*	bool in(const SetClass& set, char ch1) {
		if (set.content[ch1])
			return true;
	}*/

	friend istream& operator>>(istream&, SetClass&);
	friend ostream& operator<<(ostream&, const SetClass&);

}sets[100];

istream& operator>>(istream& input, SetClass& set) {				//讀取所輸入的字元，並在相對應位置設True
	char character = getchar();
	while (character == '\n')								
		character = getchar();
	
		for (int i = 0; i < 256; i++)
			set.content[i] = false;
			set.content[character] = true, character = getchar();
			while (character != '\n' && character != 'EOF')
			{
				set.content[character] = true, character = getchar();
			};
	
	return input;
}

ostream& operator<<(ostream& output, const SetClass& set) {			//將輸入的字元輸出至螢幕
	for (int i = 0; i < 256; i++)
		if (set.content[i])
			putchar(i);
	return output;
}

int main() {
	int number, timeCount = 1;
	int a, i, j;
	char ch;
	cin >> number;
		for (a = 0; a < number; a++)
	{

		for (i = 0; i < 2; i++)
			cin >> sets[i];
		cin.get(ch);

		cout << "Test Case " << timeCount++ << ":\n";
		for (i = 0; i < 2; i++)												//列印測資
			cout << char('A' + i) << ": {" << sets[i] << "}\n";

		for (i = 0; i < 2; i++)
			for (int j = i + 1; j < number; j++)							//列印聯集
				cout << char('A' + i) << '+' << char('A' + j) << ": {" << sets[i] + sets[j] << "}\n";

		for (i = 0; i < 2; i++)
			for (j = i + 1; j < number; j++)								//列印交集
				cout << char('A' + i) << '*' << char('A' + j) << ": {" << sets[i] * sets[j] << "}\n";

		for (i = 0; i < 2; i++)												//列印差集
			for (j = 0; j < number; j++)
				if (i != j)
					cout << char('A' + i) << '-' << char('A' + j) << ": {" << sets[i] - sets[j] << "}\n";

		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				if (i != j) {
					if (sets[i] >= sets[j])									//列印是否包含
						cout << char('A' + i) << " contains " << char('A' + j) << '\n';
					else
						cout << char('A' + i) << " does not contain " << char('A' + j) << '\n';
				}

		
	}
	return 0;
}

