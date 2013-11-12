#include<iostream>
#include<cstring>
using namespace std;


bool isUnique(string s)
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
			return false;
		}
		else
		{
			check[c] = true; 
		}
	}
	return true;
}

int main()
{
	string s,result;
	cin>>s;
	result = isUnique(s) ? "True" : "False";
	cout<<result<<endl;
}
