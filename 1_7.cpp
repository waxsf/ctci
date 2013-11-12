#include<iostream>
#include<vector>
#include<fstream>
#include<set>
using namespace std;

void toZero(vector<vector<int> > &matrix,int m,int n)
{
	set<int> rows,col;

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == 0)
			{
				rows.insert(i);
				col.insert(j);
			}
		}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(rows.count(i) || col.count(j))
			{
				matrix[i][j] = 0;
			}
		}
	}

}


int main(int argc, char *argv[])
{
	int n,m,num;
	vector<vector<int> > matrix;
	vector<int> numSet;
		ifstream fin(argv[1]);
	fin>>m>>n;
	for(int i=0;i<m;i++)
	{
		numSet.clear();
		for(int j=0;j<n;j++)
		{
			fin >> num;
			numSet.push_back(num);
		}
		matrix.push_back(numSet);
	}

	toZero(matrix,m,n);

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
