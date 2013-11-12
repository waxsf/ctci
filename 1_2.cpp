#include<iostream>
#include<string>
using namespace std;

void reverse(char* str)
{
	int len=0;
	int i=0;
	while(str[i] != '\0') i++;
	len = i;
	char c;
	for(i=0;i<len/2;i++){
		c = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = c;
	}
	cout<<"end"<<endl;
}

int main()
{
	char* str;
	cin>>str;
//	reverse(str);
	return 0;
}
