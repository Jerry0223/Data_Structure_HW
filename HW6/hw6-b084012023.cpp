// Author : B084012023 鄭鈺丞
// Date : Dec 12, 2021
// Purpose : 利用二元樹來儲存所有出現過奇數次的數字
#include<iostream>
using namespace std;

struct TreeNode {								//定義二元樹包含係數、左邊的節點以及右邊的節點
	int data;
	TreeNode* left;
	TreeNode* right;
};

class BinaryTree {
public:
	BinaryTree(int num);						//建立新的二元樹
    bool IsEmpty();								//判斷二元樹是否為空
	void add(int num);							//插入新的數字
	void del(int num);							//刪除數字
    bool Traversal(int num);					//走訪二元樹
	void show();								//將二元樹中數字列印出來
	void shownode(TreeNode* c);					//列印所有二元樹的num
	void showleft(TreeNode* c);					//列印左邊節點
	void showright(TreeNode* c);				//列印右邊節點
private:
    TreeNode* root;								//二元樹之根部
};

BinaryTree::BinaryTree(int num) {				//初始化二元樹將值代入根部
	root = new TreeNode;
	root->data = num;
	root->left = 0;
	root->right = 0;
}
void BinaryTree::add(int num) {					//增加新節點
	TreeNode* c = new TreeNode;
	TreeNode* s = new TreeNode;	
	s->left = 0;								//創立新的節點並代入num
	s->right = 0;
	s->data = num;
	c = root;
	if (IsEmpty())								//判斷是否為空的二元樹
		root->data = num;
	else if (Traversal(num)) {					//走訪二元樹若是二元樹中已經有num則刪除num值的節點
		del(num);
	}
	else {
		while (c != NULL) {						//若num不在二元樹中，則增加至二元樹中
			if (c->data > num) {				//若值小於目前節點的值則向左走訪
				if (c->left == NULL) {			//當節點為空則將num加入此節點
					c->left = s;
					c = s->left;
				}
				else							//若節點還有其他值則繼續走訪下去
					c = c->left;
			}
			else if (c->data < num) {			//若值大於目前節點的值則向右走訪
				if (c->right == NULL) {			//當節點為空則將num加入此節點
					c->right = s;
					c = s->right;
				}
				else
					c = c->right;				//若節點還有其他值則繼續走訪下去
			}
		}
	}
}

bool BinaryTree::IsEmpty() {					//判斷是否為空的二元樹
	if (root->data == -1)						//若root的值為-1則視為空的二元樹並return true
		return 1;
	else
		return 0;
}

bool BinaryTree::Traversal(int num) {			//走訪二元樹判斷是否有相同的值已存入二元樹中
	TreeNode* c = new TreeNode;
	c = root;	
	while (c) {									//跑迴圈直到節點為空集合
		if (c->data == num)						//當發現值相同時return true
			return 1;
		else if (c->data > num) {				//num值小於此節點則往左走訪
			c = c->left;
		}
		else {
			c = c->right;						//num值大於此節點則往右走訪
		}
	}
	return 0;
}

void BinaryTree::del(int num) {					//刪除節點
	TreeNode* p = new TreeNode;
	TreeNode* c = new TreeNode;
	c = root;
	while (c != NULL) {
		if (c->data == num) {					//當此節點等於num值時
			if (c->left == 0 && c->right == 0) {//且此節點為leaf node(為最後一個節點)
				if (root->data == num) {		//二元樹只有一個值時就刪除變成空集合
					root->data = -1;
				}
				else {							//此節點為右邊時
					if (p->right->data == c->data) {
						p->right = 0;			//將節點設為空集合
						c = NULL;
					}
					else {						//此節點為左邊時
						p->left = 0;			//將節點設為空集合
						c = NULL;
					}
				}
			}
			else if (c->left == 0 || c->right == 0) {	//當此節點只有一個孩子時
				if (c->left == 0) {						//只有右邊節點時
					if (root->data == num) 
						root = root->right;
					else if (p->right == c) {
						p->right = c->right;
						c = c->left;
					}
					else {							//將節點連結到下下個節點
						p->left = c->right;
						c = c->left;
					}
				}
				else {									//只有左邊節點時
					if (root->data == num)
						root = root->left;
					else if(p->right == c){
						p->right = c->left;
						c = c->right;
					}
					else {
						p->left = c->left;
						c = c->right;
					}
				}
			}
			else {										//當節點有兩個孩子時
				if (c->right->left != NULL) {			//當右節點還有左節點時
					p = c;				
					c = c->right;
					while (c->left != NULL) {			//跑回圈直到找到最左邊的節點
						c = c->left;
					}
					p->data = c->data;					//將此值取代到要刪除的值
					c = NULL;
				}
				else {									//當右節點沒有左節點時		
					p = c;								//將節點連結到下下個節點
					c->data = c->right->data;
					c = c->right;
					p->right = c->right;
					c = NULL;
				}
			}
		}
		else if (c->data > num) {						//走訪二元樹節點比num小則往右走訪
			p = c;
			c = c->left;
		}
		else {
			p = c;
			c = c->right;
		}
	}
}

void BinaryTree::show() {
	cout << "node: ";
	shownode(root);
	cout << endl << "left: ";
	showleft(root);
	cout << endl << "right: ";
	showright(root);
}

void BinaryTree::shownode(TreeNode* c) {				//列印二元樹(preorder)依照順序大小
	if (c) {
		shownode(c->left);
		cout << c->data << " ";
		shownode(c->right);
	}
}

void BinaryTree::showleft(TreeNode* c) {				//列印二元樹左邊節點
	if (c) {
		showleft(c->left);
		if (c->left == NULL)
			cout << "0 ";
		else
			cout << c->left->data << " ";
		showleft(c->right);
	}
}

void BinaryTree::showright(TreeNode* c) {				//列印二元樹右邊節點
	if (c) {
		showright(c->left);
		if (c->right == NULL)
			cout << "0 ";
		else
			cout << c->right->data << " ";
		showright(c->right);
	}
}


int main(){
	int num;
	TreeNode* c;
	cin >> num;
	BinaryTree Tree(num);
	cin >> num;
	while (num != -1) {				//跑回圈直到使用者輸入-1
		Tree.add(num);
		cin >> num;
	}
	Tree.show();					//列印二元樹
	return 0;
}

