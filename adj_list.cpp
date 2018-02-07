#include <iostream>
#include <vector>


using namespace std;

int main(){
	vector< vector<int> > adjl (7+1);
	
	adjl[1].push_back(2);
	adjl[1].push_back(7);
	adjl[1].push_back(6);	
	adjl[2].push_back(1);	
	adjl[2].push_back(4);	
	adjl[2].push_back(5);	
	adjl[3].push_back(4);	
	adjl[4].push_back(2);	
	adjl[4].push_back(3);	
	adjl[5].push_back(2);	
	adjl[5].push_back(6);	
	adjl[6].push_back(1);	
	adjl[6].push_back(5);	
	adjl[7].push_back(1);
	
	//cout << adjl[1][0];
	for(int i = 1; i <= 7; i++)
	{
		cout << i << " -> ";
		for(int j = 0; j < adjl[i].size(); j++)
			cout << adjl[i][j] << " ";
		cout << endl;
	}

	return 0;	
}
