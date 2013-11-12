#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

typedef struct node
{
	string data;
	node *next;
}node;

node* init(string s, int n)
{
	node *head,*p;
	for(int i=0; i<n; i++)
	{
		node *newNode = new node();
		
		newNode->data = s[i];
		newNode->next = NULL;
		
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

bool isPalindrome(node *head)
{
	node *p,*q;
	stack<string> content;
	p = head;
	q = head;	

	while(q && q->next)
	{
		content.push(p->data);
		p = p->next;
		q = q->next->next;
	}
	
	if(q != NULL)
	{
		p = p->next;
	}
	
	while(p)
	{
		if(content.top() != p->data)
			return false;
		p = p->next;
		content.pop();
	}
	
	return true;

}

int main()
{
	string s;
	cin>>s;
	node *head = init(s,s.length());
	cout<<"bulid the linklist successfully"<<endl;
	s = (isPalindrome(head))? "True" : "False";
	cout<<s<<endl;
	return 0;
}
