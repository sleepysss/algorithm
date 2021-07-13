#include <iostream>
#include <cstdlib>
#include <stack>

//stack:first in last out,FILO,there is only one exit/entrance at the top

using namespace std;
int main()
{
	//declare new stack
	stack<int>stk;
	//add element(push)
	stk.push(5);
	//delete element(pop)
	stk.pop();
	//get top element
	auto x = stk.top();
	//empty 
	stk.empty(); //empty->true
	//size
	stk.size();//the amount of elements in the stack

	system("pause");
	return 0;
}
