#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(6);

void initialize()
{
	for(int i = 0; i < 6; i++)
		parent[i] = i;

}

int find(int v)
{
	while(parent[v] != v)
		v = parent[v];

	return v;
}

void uni(int x, int y)
{
	int ux = find(x);
	int uy = find(y);

	parent[uy] = ux;
}
int main()
{
	int mat[6][6] = {
		{0, 1, 1, 0, 0, 0},
		{1, 0, 1, 0, 0, 0},
		{1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 0}
	};

initialize();

for(int i = 0; i < 6; i++)
{
	for(int j = 0; j <  6; j++)
	{
		if(mat[i][j] == 1)
			uni(i, j);
	}
}

for(int i = 0; i < 6; i++)
	cout << parent[i] << " ";
cout << endl;

sort(parent.begin(), parent.end());

parent.erase(unique(parent.begin(), parent.end()), parent.end());

cout << parent.size() << endl;

	return 0;
}