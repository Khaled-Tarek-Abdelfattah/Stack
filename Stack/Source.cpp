#include<iostream>
#include<string>
#include"string.h"
using namespace std;
class node {
private:
	char data;
	node* next;
public:
	node() { data = 0; next = NULL; }//constructor
	node(char d) { data = d; next = NULL; }//constructor
	void setdata(char d) { data = d; }
	void setnext(node* n) { next = n; }
	char getdata() { return data; }
	node* getnext() { return next; }
	friend class list;
};
class list {
public:
	node* chain;
public:
	list() { chain = new node(); }
	list(char d) { chain = new node(d); }//constructor
	void add_front(char d) {
		node* temp = new node(d);
		temp->next = chain;
		chain = temp;
	}
	char remove_front() {
		node* temp;
		temp = chain;
		chain = chain->next;
		char r = temp->data;
		delete temp;
		return r;
	}
	node* get_chain() { return chain; }
	char get_first_data() {
		return chain->data;
	}
};
class stack:public list {
private:
	int length=0;
public:
	stack() {*chain = NULL;}
	stack(char d) {
		length = 1;
		chain = NULL;
		add_front(d);
	}
	void push(char d){
		length++;
		add_front(d);
	}
	char pop() {
		if (length == 0)
			return '~';
		else {
			length--;
			remove_front();
		}
	}
	int isempty(){
		if (length == 0)
			return 1;
	return 0;
	}
};
int er = 0;
int error(string f) {
	int ans;
	stack s;
	int flag = 1;
	bool flag2;
	int l;
	char x;
	l = f.length();
	for (int i = 0; i < l; i++)
	{
		if (f[i] == '<') {
			s.push(f[i]);
		}
		switch (f[i]) {
		case '>':
			x = s.pop();
			break;
		}
	}
	flag2 = s.isempty();
	if (flag == 1 && flag2 == 1)
	{
		ans = 1;
	}
	else
	{
		ans = 0;
		er++;
	}
	return ans;
}
int nu_error() {
	return er;
}
int main() {
	while (1) {
		string g;
		getline(cin, g);
		if (g == "0")
			break;
		cout<<error(g)<<endl;
	}
	cout << nu_error() << endl;
	return 0;
}