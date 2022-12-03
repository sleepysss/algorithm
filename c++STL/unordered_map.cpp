#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
using namespace std;

//unorder_map: a map made by hash table(雜湊表),An unordered_map maintains a 1:1 mapping of key to value
//雜湊表的特點就是搜尋效率高，利用鍵值與雜湊函數(hash function)計算出雜湊值而快速的查找到對應的元素，
//時間複雜度為常數級別O(1)， 而額外空間複雜度則要高出許多。

int main()
{
	//declare new map
	unordered_map<string, int> m1;
	unordered_map<string, int>m2 = { {"RED",10},{"GREEN",20} };  //key-value pair(ex:sleepy為key,他的電話號碼為value)

	//add or remove element
	m1["BLUE"] = 30; //add . 如果 key 值已經存在的話，使用中括號 [] 的方式會將新資料覆蓋舊資料(Hashtable do not accept duplicate keys)
	m1.erase(m1.begin()); //remove by position
	m1.erase("BLUE"); //remove by key
	m1.clear();
	m2["GREEN"] //取得某 key 鍵值元素
	m1.insert({"PURPLE",90});  //Each element is inserted only if its key is not equivalent to the key of any other element already in the container 
	//insert 的return value
	//如果 insert() 方法成功添加键值对，该迭代器指向新添加的键值对；
	//如果 insert() 方法添加键值对失败，则表示容器中本就包含有相同键的键值对，该方法返回的迭代器就指向容器中键相同的键值对
	//插入前用find或count去判斷應該是最簡易的方法
	/*
	std::pair<std::string,double> myshopping ("baking powder",0.3);
  	myrecipe.insert (myshopping);                        // copy insertion
  	myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
  	myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
 	myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion
	*/

	//traversal
	for (auto it = m1.begin(); it != m1.end(); ++it) 
		cout << it->first << "  " << it->second;

	//get the range/size...
	m1.size(); //how many elements in the map
	m1.empty(); //empty->true
	
	//find
	
	//return an iterator,find->return first find element's position(can use search->first,search->second to show);not find->return m1.end()
	auto search = m1.find("BLACK"); 
	
	if (m.find(key) == m.end()) {...} //key-value pair不在map裡
       	
	//returns the number of elements with the key k,
	//An unordered_map maintains a 1:1 mapping of key to value, so count will always return zero or one.
	m1.count("BLUE"); 
	
	if (m.count(key) == 0) {...} ////key-value pair不在map裡
	
	
	system("pause");
	return 0;
}
