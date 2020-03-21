#include <iostream>
#include "DoublyLinkedList.cpp"

using namespace std;

class Polynomial
{
	private:
		DoublyLinkedList poly1;
		DoublyLinkedList poly2;
		DoublyLinkedList res;
	public:
	  	DoublyLinkedList Input(int d1) {	
			DoublyLinkedList l1;
			int c;
			for (int i = d1; i >= 0; i--) {
				cout << "X^" << i << ":";
				cin >> c;
				l1.getnode(i, c);		
			}
		    return l1;
		}
	  	
	  	
};

int main()
{
	Polynomial p;
	int d1, d2;
	DoublyLinkedList a, s, m;
	DoublyLinkedList p3, p4, p5;
	cout << "Enter Degree:";
	cin >> d1;
	DoublyLinkedList p1=p.Input(d1);
	p1.Print();
	cout << "\nEnter Degree:";
	cin >> d2;
	DoublyLinkedList p2 = p.Input(d2);
	p2.Print(); 
	cout << "\nResult of Sum: ";
	p3 = p1 + p2;
	p3.Print();
	cout << "\nResult of Subtraction: ";
	p4 = p1 - p2;
	p4.Print();
	cout << "\nResult of Multiplication: ";
	p5 = p1 * p2;
	p5.Print();	 

}
