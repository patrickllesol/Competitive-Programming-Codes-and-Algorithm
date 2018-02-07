
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.in");
	int nv = 0;
	fin >> nv;	
	vector< vector<int> > mat;
	
	for(int i=0; i<nv; i++)
		{
		vector<int> tmp;
		for(int j = 0; j < nv; j++)
			tmp.push_back(0);
		mat.push_back(tmp);
		}
	
	vector<char> vert_names;
	for(int i = 0; i < nv; i++)
	{
		char tmp = 'q';
		fin >> tmp;
		vert_names.push_back(tmp);
	}
	
	int ne = 0;

	fin >> ne;

	for(int i = 0; i < ne; i++)
	{
		int t1 = 0;
		int t2 = 0;
	
		fin >> t1 >> t2;
		mat[t1][t2] = 1;
		mat[t2][t1] = 1;
	}
	
	for(int i=0; i<nv; i++)
	{
		for(int j=0; j<nv; j++)
			cout << mat[i][j] << " ";
		cout << endl;	
	}
	return 0;
}
