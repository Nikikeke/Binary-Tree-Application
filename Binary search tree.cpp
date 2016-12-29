# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
int cnt;
int a[1000];
struct node{
	int data;
	node *l, *r;
};
node *newnode(){
	node *t;
	t = (node *)malloc(sizeof(node));
	t->l = t->r = NULL;
	return t;
}
void jianshu(node *T, int d){
	if (d>T->data){
		if (!T->r){
			T->r = newnode();
			T->r->data = d;
			return;
		}
		else{
			jianshu(T->r, d);
		}
	}
	else if (d<T->data){
		if (!T->l){
			T->l = newnode();
			T->l->data = d;
			return;
		}
		else{
			jianshu(T->l, d);
		}
	}
	else
		return;
}
void bianli(node *T){
	if (T){
		a[cnt++] = T->data;
		bianli(T->l);
		bianli(T->r);
	}
}
int main(){
	char flage;
	int num, i;
	node *T;
	T = newnode();
	cin >> num;
	flage = getchar();
	T->data = num;
	while (flage == ' '){
		cin >> num;
		jianshu(T, num);
		flage = getchar();
	}
	cnt = 0;
	bianli(T);
	for (i = 0; i <= cnt - 1; i++){
		if (i != cnt - 1){
			cout << a[i] << ' ';
		}
		else{
			cout << a[i];
		}
	}
	return 0;
}