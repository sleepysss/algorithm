#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string s = "ABCD";

//show the subset,a set with n elements will have 2^n subsets,because for each of the elements,we can choose/not choose

void subset(int index,string store)  //index:the index of string s we are going to add/not add to store
{
	if (index == 4)  //end condition
	{
		cout << store<<endl;
		return;
	}

	for (int i = 0; i <= 1; ++i)  //traverse candidate(in this problem we does not need to revert,because there are only 2 options:choose AND not choose,and we let not choose first(i=0),and
	{                             //because not choose wont add anything to store,so it does not need revert,and for i=1,because it is the end of the traverse,so we dont need to revert too
		if (i == 0)
			subset(index + 1, store);
		else
		{
			store.push_back(s[index]);
			subset(index + 1, store);
		}
	}
}

int main()
{
	string store;
	subset(0,store);

	system("pause");
	return 0;
}
