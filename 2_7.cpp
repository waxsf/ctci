#include<iostream>
#include<cstring>
using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

node* init(int a[], int n)
{
	node *head,*p;
	for(int i=0; i<n; i++)
	{
		node *newNode = new node();
		
		newNode->data = a[i];
		
		if(i == 0)
		{
			head = newNode;
			p = newNode;
		}
		else
		{
			p->next = newNode;
			p = newNode;
		}
	}
	return head;
}

void print(node *head)
{
	node *p;
	p = head;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

node* partition(node *head, int x)
{
	node *beforeStart=NULL;
	node *afterStart=NULL;
	node *beforeEnd = NULL;
	node *afterEnd=NULL;
	node *p;
	p = head;
	while(p)
	{
		node *nd = new node();
		nd->data = p->data;
		if(p->data < x )
		{
			if(beforeStart == NULL)
			{
				beforeStart = nd;
				beforeEnd = nd;
			}
			else
			{
				beforeEnd->next = nd;
				beforeEnd = nd;
			}
		}
		else
		{
			
			if(afterStart == NULL)
			{
				afterStart = nd;
				afterEnd = nd;
			}
			else
			{
				afterEnd->next = nd;
				afterEnd = nd;
			}
		}
		p = p->next;
	}
	beforeEnd->next = afterStart;
	return beforeStart;
}

int main()
{
	int n = 10;
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 3, 1 };
	node *head = init(a,n);
	head = partition(head,4);
	print(head);
	return 0;
}
