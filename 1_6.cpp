#include<iostream>
#include<vector>
#include<fstream>
#include<set>
using namespace std;

void rotate(vector<vector<int> > &m,int n)
{
	int t;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			t = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = t;
		}

	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n;j++)
		{
			t = m[i][j];
			m[i][j] = m[n-1-i][j];
			m[n-1-i][j] = t;
		}
	}

}


int main(int argc, char *argv[])
{
	int n,num;
	vector<vector<int> > matrix;
	vector<int> numSet;
	ifstream fin(argv[1]);
	fin>>n;
	for(int i=0;i<n;i++)
	{
		numSet.clear();
		for(int j=0;j<n;j++)
		{
			fin >> num;
			numSet.push_back(num);
		}
		matrix.push_back(numSet);
	}

	rotate(matrix,n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
