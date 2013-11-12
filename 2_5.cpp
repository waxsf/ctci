#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	int num;
	node *next;
};

node* createLinkList(int a[], int n)
{
	node *head,*p,*q;
	head = new node();
	head->num = a[0];
	p = head;
	q = head;
	int pos = 1;
	while(--n)
	{
		p = new node();
		p->num = a[pos];
		pos++;
		p->next  = NULL;
		q->next = p;
		q = p;
	}
	return head;
}

node* add(node *a, node *b)
{
	int c=0;
	node *tot,*head,*pre;
	head = NULL;
	pre = NULL;
	
	if(a == NULL) return b;
	else if(b == NULL) return a;
	
	if(a == NULL and b == NULL) return NULL;	

	while(a != NULL && b != NULL)
	{
		tot = new node();
		tot->num = a->num + b->num;
		tot->next = NULL;

		if(tot->num > 9)
		{
			c = 1;
			tot->num -= 10;
		}
		else c = 0;

		if(head == NULL)
		{
			head = tot;
			pre = head;
		}
		else
		{
			pre->next = tot;
			pre = pre->next;
		}

		a = a->next;
		b = b->next;
	}

	while( a != NULL)
	{
		tot = new node();
		tot->num = a->num + c;
		tot->next = NULL;
		if(tot->num > 9)
		{
			c = 1;
			tot->num -= 10;
		}
		else c = 0;

		if(head == NULL)
		{
			head = tot;
			pre = head;
		}
		else
		{
			pre->next = tot;
			pre = pre->next;
		}
		a = a->next;
	}

	while( b != NULL)
	{
		tot = new node();
		tot->num = b->num + c;
		tot->next = NULL;
		if(tot->num > 9)
		{
			c = 1;
			tot->num -= 10;
		}
		else c = 0;

		if(head == NULL)
		{
			head = tot;
			pre = head;
		}
		else
		{
			pre->next = tot;
			pre = pre->next;
		}
		b = b->next;
	}
	if(c != 0)
	{
		tot = new node();
		tot->num = 1;
		tot->next = NULL;
		pre->next = tot;
		pre = pre->next;

	}

	return head;
}

void print(node *head)
{
	node *p;
	p = head;
	while(p)
	{
		cout<<p->num<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	int a[] = {1,2,3};
	int b[] = {1,2};
	node *p,*q,*head;
	p = createLinkList(a,3);
	q = createLinkList(b,2);
	head = add(p,q);
	print(head);
	return 0;
}
