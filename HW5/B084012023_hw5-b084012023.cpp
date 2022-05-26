// Author : B084012023 鄭鈺丞
// Date : Nov 27, 2021
// Purpose : 利用Linked List來儲存多項式並進行加法及乘法的運算。
#include<iostream>
using namespace std;

struct Term {									//定義鏈結包含係數、指數及連接下一個鏈結的指標
	int coef;
	int exp;
	Term* next;
};

class Poly {									//實作多項式
private:
	Term* first;								//定義開頭的指標
public:
	Poly();										//初始化Class
	void Create(int num);						//創建Class
	void Sort();								//排序Linked List依照指數大小排列
	void Simplify();							//將Linked List相同指數的相加減
	void Add(Poly& _poly, int count);			//將兩個多項式相加並列印出來
	void Multiply(Poly& _poly);					//將兩個多項式相乘並列印出來
};

Poly::Poly() {		
	first = new Term;							//建立一個新Linked List並指向NULL
	first->next = NULL;
}

void Poly::Create(int num) {					
	Term* c = first;							//創建一個指向目前的Linked List
	int count = num;
	while (count--) {							//一共創建num次數的Linked List
		Term* s = new Term;						
		cin >> s->coef >> s->exp;				//讀取使用者所輸入的係數以及指數
		s->next = c->next;						//將這個新的Linked List指向NULL
		c->next = s;							//移動至目前的Linked List
		c = s;
 	}
	if (num > 1) {								//若是此二項式少於兩項則不用進行排列及簡化
		Sort();
		Simplify();
	}
}

void Poly::Sort() {				
	Term *c = first->next, *s = c->next;
	while (c) {									//依序與開頭比大小
		s = c->next;
		while (s) {
			if (c->exp < s->exp) {				//指數若是比開頭的大則相交換
				int x, y;
				x = c->coef;
				c->coef = s->coef;
				s->coef = x;
				y = c->exp;
				c->exp = s->exp;
				s->exp = y;
			}
			s = s->next;						
		}
		c = c->next;							//比完一輪後再從下一個繼續比大小直到C==NULL
	}
}

void Poly::Simplify() {
	Term* p = first->next;
	while (p && p->next) {							//自己與下一個Linked List比較指數若是相同則將係數加到P並把p->next刪除
			if (p->exp == p->next->exp) {
				p->coef = p->coef + p->next->coef;
				Term* del = new Term;
				del = p->next;
				p->next = del->next;
				delete del;
			}
			else
				p = p->next;						//若是不同則繼續走訪下去直到p == NULL
		}
}

void Poly::Add(Poly & poly, int count) {
	Poly polyc;										//建立新的二項式用於儲存運算完的結果
	Term* a = first, *b = poly.first, *c = polyc.first;
	Term* pa = first->next, *pb = poly.first->next;
	Term* current;
	int sum;
	while (pa != NULL && pb != NULL) {				//跑迴圈直接兩個多項式都為NULL
		if (pa->exp == pb->exp) {					//若是指數相同則係數相加
			sum = pa->coef + pb->coef;
			if (sum != 0) {							//若相加不等於0則將結果儲存至新的class中(polyc)
				Term* pc = new Term;
				pc->coef = sum;
				pc->exp = pa->exp;
				pc->next = c->next;
				c->next = pc;
				c = pc;
			}
			pa = pa->next;							//兩個多項式繼續走訪下去
			pb = pb->next;
		}
		else if (pa->exp < pb->exp) {				//若是b多項式指數較大則將b的數值儲存至新的class
			Term* pc = new Term;
			pc->coef = pb->coef;
			pc->exp = pb->exp;
			pc->next = c->next;
			c->next = pc;
			c = pc;
			pb = pb->next;							//b多項式往下走與a繼續比較
		}
		else {										//若是a多項式指數較大則將a的數值儲存至新的class
			Term* pc = new Term;
			pc->coef = pa->coef;
			pc->exp = pa->exp;
			pc->next = c->next;
			c->next = pc;
			c = pc;
			pa = pa->next;							//a多項式往下走與b繼續比較
		}	
	}
	if (pa != NULL)
		c->next = pa;								//將剩餘結點加入到新的class
	else if (pb != NULL)
		c->next = pb;
	cout << "Case" << count << ":\n" << "ADD\n";
	current = polyc.first->next;
	if (current == NULL)							//若新的二項式結果為0則列印0 0
		cout << "0 0" << endl;						
	while (current) {
		cout << current->coef << " " << current->exp << endl;	//將結果列印出來
		current = current->next;
	}
}

void Poly::Multiply(Poly& poly) {
	Poly polyc;												//建立新的二項式用於儲存運算完的結果
	Term* a = first, * b = poly.first, * c = polyc.first;
	Term* pa = first->next, * pb = poly.first->next;
	Term* current;
	while (pa) {
		while (pb) {										//從a多項式第一項開始與b的多項式相乘
			Term* pc = new Term;
			pc->coef = pa->coef * pb->coef;					//將結果儲存至新的多項式
			pc->exp = pa->exp + pb->exp;
			pc->next = c->next;
			c->next = pc;
			c = pc;
			pb = pb->next;
		}	
		pa = pa->next;										//a多項式走訪到下一個Linked List						
		pb = poly.first->next;								//b多項式從頭重新相乘
	}
	cout << "MULTIPLY\n";
	current = polyc.first->next;
	if (current == NULL)
		cout << "0 0" << endl;								//若是相乘等於0則列印 0 0
	else {
		polyc.Sort();										//若是相乘結果不等於0則進行排序與簡化
		polyc.Simplify();
	}
	while (current) {
		cout << current->coef << " " << current->exp << endl;		//將結果列印出來
		current = current->next;
	}
	cout << endl;
}

int main() {
	int num1, num2, count = 1;								//count用來儲存跑過幾次資料
	while (1) {
		Poly polyA, polyB;
		cin >> num1;
		polyA.Create(num1);									//創造新的二項式(Linked List)
		cin >> num2;
		if (num1 == 0 && num2 == 0)							//當連續讀取兩次0則結束迴圈
			break;
		polyB.Create(num2);
		polyA.Add(polyB, count);
		polyA.Multiply(polyB);
		count++;
	}
}