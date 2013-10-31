#include<iostream>
#include<string>
using namespace std;

string int2Str(int n)
{
	string s;
	char c;
	int d;
	while(n)
	{
		d = n % 10;
		c = d+'0';
		s = c+s;
		n /= 10; 
	}
	return s;
}

string compress(string s)
{
	int len;
	string num;
	string res = "";
	len = s.length();
	string pre;
	pre = s[0];
	int cnt = 1;
	for(int i=1;i<len;i++)
	{
		if(s.substr(i,1) == pre)
		{
			cnt++;
		}
		else
		{
			num = int2Str(cnt);
			res += pre+num;
			cnt = 1;
			pre = s[i];
		}
	}
	
	num = int2Str(cnt);
	res += pre +num;
	
	if(res.length()>= len)
		return s;
	else return res;

}


int main()
{
	string s;
	cin>>s;
	cout<<compress(s);
	return 0;
}
