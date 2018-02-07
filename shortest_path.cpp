
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

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
		int w = 0;
		fin >> t1 >> t2 >> w;
		mat[t1][t2] = w;
		
	}

	vector<int> Q(nv);//distances
	vector<string> P(nv);//paths
	vector<bool> visited(nv); //visited
	int num_visited = 0;

	for (int i = 0; i < nv; i++)
	{
		Q[i] = 9999999;
		P[i] = "";
		visited[i] = false;
	}
	//different sources
	int source = 2;

	Q[source] = 0;
	P[source] = vert_names[2];

	while(num_visited < nv)
	{
		//find the lowest weighted vertex
		int idx = 0;

		for (; idx < nv; idx++)
		{
			if(!visited[idx])
				break;
		}

		int min_weight = Q[idx];

		for (int i = 0; i < nv; i++)
		{
			if(!visited[i] && Q[i] < min_weight)
			{
				idx = i;
				min_weight = Q[i];
			}
		}

		//get the neighbors of the vertex
		//compute distance to neighbors
		//compare distances
		//repalce distance if possible
		for (int i = 0; i < nv; i++)
		{
			if(mat[idx][i] > 0)
			{
				if(Q[idx] + mat[idx][i] < Q[i])
				{
					Q[i] = Q[idx] + mat[idx][i];
					P[i] = P[idx] + vert_names[i]; 
				}
			}
		}

		//mark the vertex as visited
		visited[idx] = true;
		num_visited++;
	}

	for (int i = 0; i < nv; i++)
	{
		for (int j = 0; j < P[i].length(); j++)
		{
			cout << vert_names[P[i][j] - '0'] << " ";
		}
		cout << endl;
	}

	return 0;
}
