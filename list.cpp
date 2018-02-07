#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.in");
	int nv;
	
	vector<char> vert_names;

	fin >> nv;

	for(int i = 0; i < nv; i++)
	{
		char t = 't';
		fin >> t;
		vert_names.push_back(t);
	}

	int ne;

	fin >> ne;

	vector<vector <int> > adjlist;

	for(int i = 0; i < nv; i++)
	{
		vector<int> p;
		adjlist.push_back(p);
	}

	for(int i = 0; i < ne; i++)
	{
		int t1 = 0;
		int t2 = 0;
		fin >> t1 >> t2;

		adjlist[t1].push_back(t2);
		adjlist[t2].push_back(t1);
	}

	for(int i = 0; i < nv; i++)
	{
		cout << vert_names[i]  << " ->  ";
		for(int j = 0; j < adjlist[i].size(); j++)
			cout << vert_names[ adjlist[i][j]] << " ";
		cout << endl;
	}
	return 0;
}
