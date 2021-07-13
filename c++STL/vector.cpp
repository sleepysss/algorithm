#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//vector is  a dynamic array

int main()
{
	int array[5] = { 1,2,3,4,5 };

	//declare new vector
	vector<int> v1(3,5);  //3 element ,each element value equals 5
	vector<int> v2(4); //4 element,each element valuse equals 0
	vector<int> v3; //an empty vector 
	vector<int> v4(array, array + 5); //declare by array based, interval:[) in this example v4 will have 1,2,3,4,5
	vector<int> v5 = { 9,8,7,6,5 };
	vector<int>::iterator it; //an  iterator

	//iterator
	it = v1.begin(); //a place of vector first element
	it = v1.end();//a place of vector last+1 element (not last element)

	//get the element
	v1[0]; //just like array
	v1.front(); //first element 
	v1.back(); //last element

	//add or remove element
	v2.push_back(1); //add an element at the vector end
	v2.pop_back();//delete an element at the vector end
	v2.insert(v2.begin(), 999); //add an(some) elements at the specific position,position needs to be a iterator (in this example add 999 at the begining of v2 
	it = v1.begin();
	v1.insert(it, 5, 66); //add 5 66 to the begining of v1 
	v1.insert(v1.begin() + 1, v2.begin(), v2.end()); //add vector or array to another arrray interval{)
	v1.insert(v1.begin(), { 30,40,50,60 }); //insert multiple element
	v1.erase(v1.begin()); //delete a single value at specific position
	v1.erase(v1.begin(), v1.begin() + 3); //delete a range,interval{)
	v1.clear(); //delete all

	//get the range/size ....
	v1.empty(); //see if the vector is empty (empty->true)
	v1.size(); //vector have how many elements
	v1.resize(20); //change the size (smaller->delete end;bigger->padding 0)

	//traversal
	for (int i = 0; i < v2.size(); ++i) cout << v2[i] << endl;
	for (auto it2 = v2.begin(); it2 != v2.end(); ++it2) cout << *it2 << endl; //by iterator

	system("pause");
	return 0;
}
