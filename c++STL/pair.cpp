#include <cstdlib>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

//pair:couples together a pair of values,which may be different type

int main()
{
	//declare new pair
	pair<int, string>p1(10,"ten");
	pair<int, vector<int>>p2;
	pair<int, string>p3 = { 20, "twenty" };
	pair<int, string>p4 = p3; //p4 set to p3
	pair<int, string>p5(p3); //p5 set to p3

	//member in pair
	cout << p1.first << p1.second;  //first:pair first member;seconf:pair second member

	//operator = == != >= <=

	system("pause");
	return 0;
}
