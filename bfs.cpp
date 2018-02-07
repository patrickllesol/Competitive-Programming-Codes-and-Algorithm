
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void bfs(vector<vector<int> > mat, int source)
{
	vector<bool> visited;

	for (int i = 0; i < mat.size(); ++i)
	{
		visited.push_back(false);
	}

	queue<int> t;

	t.push(source);

	while(!t.empty())
	{
		int tmp = t.front();
		t.pop();

		if(!visited[tmp])
		{
			cout << tmp << endl;

			for(int i = 0; i < mat.size(); i++)
				if(mat[tmp][i] == 1)
				{
					t.push(i);
				}
			visited[tmp] = true;
		}
	}

}

int main()
{
	ifstream fin("graph.in");
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
		
	}

	bfs(mat, 0);
	/*
	for(int i=0; i<nv; i++)
	{
		for(int j=0; j<nv; j++)
			cout << mat[i][j] << " ";
		cout << endl;	
	}
	*/
	return 0;
}
