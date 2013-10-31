#include<iostream>

using namespace std;

bool isSubstring(string s, string sub)
{
	return s.find(sub) != string::npos;

}

bool isRotation(string s1, string s2)
{
	int len = s1.length();
	
	if(len == 0) return false;
	else if(len != s2.length()) return false;
	
	s1 = s1+s1;
	return isSubstring(s1,s2);
	
}

int main()
{
	string s1,s2;
	string result;
	cin>>s1>>s2;
	result = isRotation(s1,s2) ? "True" : "False";
	cout<<result<<endl;
	return 0;
}
