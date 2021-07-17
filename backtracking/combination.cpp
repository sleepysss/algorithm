#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

//Given two integers n and k, return all possible combinations of k numbers out of the range[1, n].

void combination(int n, int k,vector<int> store,int start)
{
	if (store.size() == k)
	{
		for (int i = 0; i < store.size(); ++i) cout << store[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i <= n; ++i)       //not from 1 because it is combination(in combination,1,2 and 2,1 are same),needs "special method":
	{                                                   //Take the number from left to right, and don’t repeat it for those who have been taken
		                                                //we can let i start from 1 and select the candidate  also
		if ((store.size()+n-i+1)>=k)  //cant full store array(does not have enough candidate,we need k candidate)
		{
			store.push_back(i);  //add
			combination(n, k, store, i + 1);  //discover
			store.pop_back();  //revert
		}
	}
}

int main()
{
	vector<int> store;
	combination(5,3,store,1);
	system("pause");
	return 0;
}
