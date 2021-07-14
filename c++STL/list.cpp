#include<iostream>
#include <cstdlib>
#include <list>
using namespace std;

//list: a doubly linked list,does not support random access(ie:cant use l1[3])

int main()
{
	//declare new list
	list<int> l1; //empty list
	list<int> l2(3); //3 elements,all of them are 0
	list<int> l3(5, 1); //5 elements,all of them are 1
	list<int> l4(l1); //l4 is a copy of l1 (equals l4=l1)
	list<int> l5(l2.begin(), l2.end()); //interval{)
	list<int>::iterator it;

	//iterator
	it = l3.begin(); //a place of list first element
	it = l3.end(); //a place of list last+1 element (not last element)

	//get the element
	l2.front(); //first element
	l2.back(); //last element

	//add or remove element
	l1.push_back(10); //add an element at the list end
	l1.push_front(20);//                                           front
	l1.pop_back();  //delete                                     end
	l1.pop_front(); //                                                front
	l2.insert(l2.begin(), { 9,8,7 }); //insert multiple elements
	l1.insert(l1.begin(), 6); // insert a single element
	l1.insert(l1.begin(), l2.begin(), l2.end()); //interval{)
	l1.insert(l1.begin(), 5, 3); //insert five 3 
	l1.erase(l1.begin()); //delete an element
	it = l1.begin();
	it++;
	it++;
	l1.erase(l1.begin(),it); //delete a range of element ,interval:{),cant l1.begin()+2 because it is a list
	l1.remove(99); //remove all elements that are 99

	//operator = == != < > <= >=

	//get the range/size...
	l2.size(); //how many elements in the list
	l2.empty(); //empty->true
	l3.resize(30);

	//special
	l1.sort(); //sorting
	l2.sort();
	l1.merge(l2); //combine the list (l2 will be empty and l1 will get all the element of l2 with sorted) (two list need to be sorted first!)
	l1.reverse(); //reverse the list
	l1.splice(l1.end(), l3); //move all of the elements in l3 to pos (l3 will be empty)
	l2.splice(l2.end(), l1, l1.begin(), it); //move a range of elements frome l1 to l2.end() ,interval:[)

	//traversal
	for (auto it2 = l5.begin(); it2 != l5.end(); ++it2) cout << *it2;

	system("pause");
	return 0;
}
