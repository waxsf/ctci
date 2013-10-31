#include<iostream>
using namespace std;

void reverse(char *s)
{
	char *p = s,*q = s;
	char c;
	
	while(*q)
	{
		q++;
	}
	q--;
		
	while(p < q)
	{
		cout<<c<<endl;
		c = *p;
		*p = *q;
		*q = c;
		q--;
		p++;
	}
}

int main()
{
	char s[] = "1234567";
	reverse(s);
	cout<<s<<endl;
}
