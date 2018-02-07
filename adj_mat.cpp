#include<iostream>
#include <vector>
using namespace std;

int main(){
	vector< vector<int> > mat;
	for(int i = 0; i <7; i++)
	{
		vector<int> temp;
		for(int j = 0; j < 7; j++)
			{
				temp.push_back(0);
			}
		mat.push_back(temp);
	}
	
	mat[3-1][4-1] = 1;	
	mat[4-1][3-1] = 1;	
	mat[4-1][2-1] = 1;	
	mat[2-1][4-1] = 1;	
	mat[2-1][1-1] = 1;	
	mat[1-1][2-1] = 1;	
	mat[6-1][5-1] = 1;	
	mat[5-1][6-1] = 1;	
	mat[2-1][5-1] = 1;	
	mat[5-1][2-1] = 1;	
	mat[1-1][7-1] = 1;	
	mat[7-1][1-1] = 1;	
	
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;	
}
