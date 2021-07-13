#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

//queue:first in first out,FIFO;an entrance at back,an exit at front

int main()
{
	//declare new queue
	queue<int>q;
	//add element(push)
	q.push(10);
	//delete element(pop)
	q.pop();
	//get the value
	q.front(); //get first element
	q.back(); //get last element
	//empty
	q.empty();//empty->true
	//size
	q.size(); //the amount of elements in the queue

	system("pause");
	return 0;
}
