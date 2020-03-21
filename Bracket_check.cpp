#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class node {
	public:
	int data;
	node * next;
};

class LL {
	protected:
		node * head;
	public:
		LL() {
			head = NULL;
		}
	    void insert(int v) {
	    	node * nptr = new node();
	    	nptr->data = v;
	    	nptr->next = NULL; // Because next contain the garbage value so we make it NULL.
	    	if(head == NULL) {
	    		head = nptr;
			}
			else {
				node * tptr = head;
				while(tptr->next != NULL) {
					tptr = tptr->next;
				}
				tptr->next = nptr;
			}			
		}
		void print() {
			node * tptr = head;
			while(tptr->next != NULL) {
				cout << tptr->data << " ";
				tptr = tptr->next;
			}
			cout << tptr->data;
		}
		void print1() {
			node * tptr = head;
			while(tptr != NULL) {
				cout << tptr->data << " ";
				tptr = tptr->next;
			}
		}
		void deletes(int v) {
			node * ftpr = head;
			node * tptr = head;
			while(tptr->data != v) {
				ftpr = tptr;
				tptr = tptr->next;
			}
			ftpr->next = tptr->next;
		}
		
};

class Queue : public LL {
	public:
		void enQ(int x) {
			this->insert(x);
		}
		int deQ() {
			if(head != NULL) {
				int x;
				node * nptr = head;
				head = head->next;
				x = nptr->data;
				delete nptr;
				return x;
			}
		}
};

class stack : public LL {
	public:
		int pop() {
			int x;
			node * tptr = head;
			if(head == NULL) {
				return -1;
			}
			else if(head->next == NULL) {
				int x;
				x = head->data;
				head = NULL;
				return x;
			}
			else {
				while(tptr->next->next == NULL) {
					tptr = tptr->next;
				}
				int x;
				x = tptr->next->data;
				tptr->next = NULL;
				return x;
			} 	
		}
		void Push(int v) {
			node * nptr = new node();
	    	nptr->data = v;
	    	nptr->next = NULL; // Because next contain the garbage value so we make it NULL.
	    	if(head == NULL) {
	    		head = nptr;
			}
			else {
				node * tptr = head;
				while(tptr->next != NULL) {
					tptr = tptr->next;
				}
				tptr->next = nptr;
		    }
        }
        void bracketcheck() {
        	ifstream infile;
        	infile.open("a.txt");
        	char x[15];
        	char v;
        	int i = 0;
        	int count = 0;
        	if(!infile) {
        		cout << "There is no file to Open!!!\n";
			}
			else {
				infile >> v;
				while(!infile.eof()) {
					infile >> v;
					if(v == '{') {
						Push(i);
					}
					else if(v == '}') {
						pop();
					}
					i = i + 1;
				}
			    if(head == NULL) {
					cout << "Your Program Brackets are Good!!!\n";
				}
				else {
					cout << "Your Program missing the Bracket Check it or its a false sequence of brackets!!\n";
				}
			}
		}
};

int main() {
	stack obj;
	obj.bracketcheck();
}
