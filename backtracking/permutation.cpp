#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string s = "abcd";

//store:place for storing candidate we have right now
//count:the level we are in
//num:amount of elements in string s
//visited:elements in string s we have visited or not
void backtracking(string store,int count,int num,bool visited[]) 
{
	if (count == num)  //end condition
	{
		cout << store << endl;
		return;
	}
	count++;  //next level(count needs to be add outside for,because inside for,they are the same level,just like your brothers and sisters)
	for (int i = 0; i < num; ++i) //BFS all the possibility(in this case our choice is a,b,c)
	{
		if (!visited[i])  //before adding ,we needs to meet the condition
		{
			store.push_back(s[i]);  //add the candidate in
			visited[i] = true;
			backtracking(store, count, num, visited); //go DFS,"results"(visited[],store[],count) is based on ancestor
			store.pop_back();  //after DFS,we need to revert back,in order not to affect others(your brothers and sisters)
			visited[i] = false;  //after DFS,we need to revert back,in order not to affect others(your brothers and sisters)
		}
	}
}

int main()
{
	string store;
	bool visited[4] = { 0 };
	int num = s.size();
	backtracking(store,0,num,visited);

	system("pause");
	return 0;
}
