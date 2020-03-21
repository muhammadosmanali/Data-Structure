#include <iostream>
using namespace std;

class node
{
public:
  int data;
  int exp;
  int coeff;
  node * Left;
  node * Right;
  node()
  {
  	exp = 0;
  	coeff = 0;
  	Left = NULL;
  	Right = NULL;
  }


};

class DoublyLinkedList
{
public:
  int count;
  node * LeftHead;
  node * RightHead;

  DoublyLinkedList()
  {
    count = 0;
    LeftHead = NULL;
    RightHead = NULL;
  }

  void insertR(int v)
  {
    node * temp = new node();
    temp->data = v;
    temp->Left = NULL;
    temp->Right = NULL;
    if (LeftHead == NULL && RightHead == NULL)
    {
      RightHead = temp;
      LeftHead = temp;
    }
    else
    {
      node *ptr = RightHead;
      ptr->Right = temp;
      temp->Left = ptr;
      RightHead = temp;
      temp = NULL;
    }
    count++;
  }
  
  void insertL(int v)
  {
    node * temp = new node();
    temp->data = v;
    temp->Left = NULL;
    temp->Right = NULL;
    if (LeftHead == NULL && RightHead == NULL)
    {
      RightHead = temp;
      LeftHead = temp;
    }
    else
    {
      node *ptr = LeftHead;
      ptr->Left = temp;
      temp->Right = ptr;
      LeftHead = temp;
      temp = NULL;
    }
    count++;
  }


  void insertAt(int v, int index)
  {
    if (index <= 0)
    {
      insertL(v);
    }
    else if (index >= count)
    {
      insertR(v);
    }
    else
    {
      node * temp = new node();
      temp->data = v;
      node * ptr = LeftHead;
      for (int i = 0; i < index - 1; i++)
      {
        ptr = ptr->Right;
      }
      temp->Right = ptr->Right;
      ptr->Right->Left = temp;
      temp->Left = ptr;
      ptr->Right = temp;
      count++;
    }
  }

  void del(int v)
  {
    node * temp = LeftHead;
    if (temp->data == v)
    {
      temp = temp->Right;
      temp->Left->Right = NULL;
      temp->Left = NULL;
      LeftHead = temp;
      temp = NULL;
      count--;                                     
      return;
    }
    temp = RightHead;
    if (temp->data == v)
    {
      temp = temp->Left;
      RightHead = temp;
      temp->Right->Left = NULL;
      temp->Right = NULL;
      count--;
      return;
    }
    else
	    {
        temp = LeftHead->Right;
      //cout << "data = " << temp->data << endl;
      while (temp)
      {
        if (temp->data == v)
        {
          temp->Left->Right = temp->Right;
          temp->Right->Left = temp->Left;
          temp->Right = NULL;
          temp->Left = NULL;
          count--;
          return;
        }
        else
        {
          temp = temp->Right;
        }
      }
    }
  }

  node * Search(int v)
  {
    node * temp = LeftHead;
    //int i = 0;
    for (int i = 0; i < count; i++)
    {
      if (temp->data == v)
      {
        //cout << i << endl;
        return temp;
      }
      else
      {
        temp = temp->Right;
      }
    }
    temp = NULL;
    return NULL;
  }
  
   void Print()
  {
    if (LeftHead != NULL && RightHead != NULL)
    {
      node * temp = LeftHead;
      cout << "+" << temp->coeff << "X^" << temp->exp ;
      while (temp->Right != NULL)
      {
        temp = temp->Right;
        cout << "+" << temp->coeff << "X^" << temp->exp ;
        
      }
      cout<< endl;
    }
    else
    {
      cout << "Zero nodes" << endl;
    }
    //cout << count;
  }
  
 void getnode(int e, int c)
  {
  	{
    node * temp = new node();
    temp->exp = e;
    temp->coeff = c;
    temp->Left = NULL;
    temp->Right = NULL;
    if (LeftHead == NULL && RightHead == NULL)
    {
      RightHead = temp;
      LeftHead = temp;
    }
    else
    {
      node *ptr = RightHead;
      ptr->Right = temp;
      temp->Left = ptr;
      RightHead = temp;
      temp = NULL;
    }
    count++;
  }
  }
  
  
  DoublyLinkedList operator+(const DoublyLinkedList poly2)
  {
  	DoublyLinkedList result;
  		node *res = new node();
		node *temp1 = this->RightHead;
		node *temp2 = poly2.RightHead;
		while(temp1 != NULL && temp2 != NULL)
		{

			if(temp1->exp == temp2->exp)
			{
			res->coeff = temp1->coeff + temp2->coeff;
			res->exp = temp1->exp;
			result.getnode(res->exp, res->coeff);
			temp1 = temp1->Left;
			temp2 = temp2->Left;
			}
		}
		while(temp1)
		{
			res->coeff = temp1->coeff;
			res->exp = temp1->exp;
			result.getnode(res->exp, res->coeff);
			temp1 = temp1->Left;
		}
		while(temp2)
		{
			res->coeff = temp2->coeff;
			res->exp = temp2->exp;
			result.getnode(res->exp, res->coeff);
			temp2 = temp2->Left;
		}
	    return result;
	}
	
	DoublyLinkedList operator-(const DoublyLinkedList poly2)
  {
  	DoublyLinkedList result;
  	node *res = new node();
	node *temp1 = this->RightHead;
	node *temp2 = poly2.RightHead;
	while(temp1 != NULL && temp2 != NULL)
	{

	    if(temp1->exp == temp2->exp)
		{
		  	res->coeff = temp1->coeff - temp2->coeff;
		  	res->exp = temp1->exp;
			result.getnode(res->exp, res->coeff);
			temp1 = temp1->Left;
			temp2 = temp2->Left;
		}
	}
	while(temp1)
	{
		res->coeff = temp1->coeff;
		res->exp = temp1->exp;
		result.getnode(res->exp, res->coeff);
		temp1 = temp1->Left;
	}
	while(temp2)
	{
		res->coeff = temp2->coeff;
		res->exp = temp2->exp;
		result.getnode(res->exp, res->coeff);
		temp2 = temp2->Left;
	}
	return result;
}

	DoublyLinkedList operator*(const DoublyLinkedList poly2)
	{
	  	DoublyLinkedList result;
		node *res = new node();
		node *temp1 = this->RightHead;
		while(temp1)
		{
			node *temp2 = poly2.RightHead;
			while(temp2)
			{
				res->exp = temp1->exp + temp2->exp;
				res->coeff = temp1->coeff * temp2->coeff;
				result.getnode(res->exp, res->coeff);
				temp2 = temp2->Left;
			}
		temp1 = temp1->Left;
		}
	return result;
	  	
	}
	
	
  
  
};

/*int main()
{
  DoublyLinkedList l1;
  //l1.Print();
  l1.insertR(2);
  l1.insertR(3);
  l1.insertR(4);
  l1.insertR(5);
  l1.insertR(6);
  l1.insertR(7);
  l1.insertAt(11, 3);
  l1.insertL(12);
  l1.insertL(10);
  l1.del(12);
  l1.del(2);
  //cout << "Count = " << l1.count << endl;
  l1.Print();
  //cout << "Searched node is at index = " << l1.Search(11) << endl;
  l1.Search(11);
}*/
