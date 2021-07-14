#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
using namespace std;

//unorder_map: a map made by hash table

int main()
{
	//declare new map
	unordered_map<string, int> m1;
	unordered_map<string, int>m2 = { {"RED",10},{"GREEN",20} };

	//add or remove element
	m1["BLUE"] = 30; //add
	m1.erase(m1.begin()); //remove by position
	m1.erase("BLUE");
	m1.clear();

	//traversal
	for (auto it = m1.begin(); it != m1.end(); ++it) cout << it->first << "  " << it->second;

	//get the range/size...
	m1.size(); //how many elements in the map
	m1.empty(); //empty->true

	////operator = == != 

	system("pause");
	return 0;
}
