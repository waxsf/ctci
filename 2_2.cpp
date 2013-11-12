#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	char c;
	node *next;
};

node* createLinkList(char s[], int n)
{
	node *head,*p,*q;
	head = new node();
	head->c = s[0];
	p = head;
	q = head;
	int pos = 1;
	while(--n)
	{
		p = new node();
		p->c = s[pos];
		pos++;
		p->next  = NULL;
		q->next = p;
		q = p;
	}
	return head;
}

node* findKth(node *head, int k)
{
	node *p,*q;
	p = head;
	q = head;
	while(k--) q = q->next;
	while(q != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}


int main()
{
	char s[] = "123456789";
	node *head, *p;
	head = createLinkList(s,strlen(s));
	p = findKth(head,4);
	cout<<p->c<<endl;
	
	return 0;
}
