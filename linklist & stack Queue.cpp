#include <iostream>
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
};

int main() {
	stack obj;
	obj.Push(1);
	obj.Push(2);
	obj.Push(3);
	obj.Push(4);
	obj.print1();
	obj.pop();
	obj.print1();
}
