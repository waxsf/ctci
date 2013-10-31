#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void myInsert(string& s,int len){
	size_t found;
	found = s.find(" ");
	while(found != string::npos){
		s.erase(found,1);
		s.insert(found,"%20");
	}
}

int main(){
	string s;
	ifstream in("1.txt");
	while(getline(in,s));	
	myInsert(s,s.length());
	cout<<s<<endl;
	return 0;		
}
