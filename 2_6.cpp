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

node* removeDup0(node *head)
{
	node *p,*q,*r;
	p = head;
	while(p != NULL)
	{
		r = p;
		q = p->next;
		while(q != NULL)
		{
			if(p->c == q->c)
			{
				r->next = q->next;
				delete[] q;
				q = r;
			}
			else r = r->next;

			q = q->next;
		}
		p = p->next;
	}
	return head;
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
	char s[] = "Hello word";
	node *head;
	head = createLinkList(s,strlen(s));
	head = removeDup0(head);
	//cout<<"remove!"<<endl;
	print(head);
	return 0;
}
