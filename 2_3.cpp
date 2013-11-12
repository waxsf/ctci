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

node* findKthNode(node *head, int k)
{
	node *p;
	p = head;
	while(k--) p = p->next;
	return p;

}

void removeEle(node *p)
{
	node *q;
	q = p->next;
	p->c = q->c;
	p->next = q->next;
	delete[] q;
}

void print(node *head)
{
	node *p;
	p = head;
	while(p)
	{
		cout<<p->c<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main()
{
	char s[] = "Helloword";
	node *head, *p;
	head = createLinkList(s,strlen(s));
	p = findKthNode(head, 5);
	removeEle(p);
	//cout<<"remove!"<<endl;
	print(head);
	return 0;
}
