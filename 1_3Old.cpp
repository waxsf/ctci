#include<iostream>
#include<cstring>
using namespace std;


string remove(string s)
{
	bool check[256];
	memset(check,false,256);
	int len = s.length();
	int c;
	for(int i=0; i<len; i++)
	{
		c = int(s[i]);
		if(check[c])
		{
			s.erase(i,1);
			i--;
		}
		else
		{
			check[c] = true; 
		}
	}
	return s;
}

int main()
{
	string s,result;
	cin>>s;
	result = remove(s); 
	cout<<result<<endl;
}
