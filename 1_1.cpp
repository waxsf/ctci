#include<iostream>
#include<string>

using namespace std;


bool isUniq(string s){
	bool hash_table[256];
	memset(hash_table,0,sizeof(hash_table));
	int n;
	for(int i=0;i<s.length();i++){
		n = s[i];
		if(hash_table[n] == true){
			return false;
		}
		else{
			hash_table[n] = true;
		}
	}
	return true;
}

int main(){
	string s;
	cin>>s;
	cout<<isUniq(s)<<endl;
	return 0;
}
