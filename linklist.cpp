#include <iostream>
using namespace std;

class node {
	public:
	int data;
	node * next;
};

class LL {
	private:
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

int main() {
	LL obj;
	obj.insert(6);
	obj.insert(7);
	obj.insert(8);
	obj.insert(9);
	obj.deletes(8);
	obj.print1();
	
	
}
