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
	vector<int> v2(4); //4 element,each element value equals 0
	vector<int> v3; //an empty vector 
	vector<int> v4(array, array + 5); //declare by array based, interval:[) in this example v4 will have 1,2,3,4,5 ,vector的範圍也行
	vector<int> v5 = { 9,8,7,6,5 };
	vector<vector<int>> array_2D(3,v5); //an 2D array with  3 row and each row has the same value with v5
	vector<int>::iterator it; //an  iterator
	
	/*  iterator
	//  迭代器(iterator)是一中检查容器内元素并遍历元素的数据类型。
	//  使用方法和pointer一樣,通过迭代器可以指向容器中的某个元素，如果需要，还可以对该元素进行读/写操作。
	//  每种容器类型都定义了自己的迭代器类型
	//  list<int>::iterator iter;这条语句定义了一个名为iter的变量，它的数据类型是由list<int>定义的iterator类型。
	//  const_iterator只能只能對容器中資料進行「讀取」的動作，而無法存入或更改其值。
	//  共有5種iterator:
	//  (1)输入迭代器(Input Iterator):只能向前单步迭代元素，不允许修改由该迭代器所引用的元素
	//  (2)输出迭代器(Output Iterator):只能向前单步迭代元素，对由该迭代器所引用的元素只有写权限
	//  (3)向前迭代器(Forward Iterator):该迭代器可以在一个区间中进行读写操作，它拥有输入迭代器的所有特性和输出迭代器的部分特性，以及向前单步迭代元素的能力
	//  (4)双向迭代器(Bidirectional Iterator):在向前迭代器的基础上增加了向后单步迭代元素的能力
	//  (5)随机访问迭代器(Random Access Iterator):不仅综合以后4种迭代器的所有功能，还可以像指针那样进行算术计算
	//
	//  定義方式:
	//  (該容器提供的)迭代器     容器类名::iterator  迭代器名;
	//  常量正向迭代器           容器类名::const_iterator  迭代器名;	
	//  反向迭代器              容器类名::reverse_iterator  迭代器名;
	//  常量反向迭代器           容器类名::const_reverse_iterator  迭代器名;
	//	
	//  iterator的相等:The two iterators are equal only when both the iterators point to the same position.
	//  list提供的是双向迭代器,所以list<int>::iterator iter為bidirectional的
	//  而雙向迭代器不支援 p1[i](不能通过下标访问 list 容器中指定位置处的元素), p1-=i ,p1+i(不支持使用 -=、+=、+、- 运算符), 不支持使用 <、 >、 <=、 >= 比较运算符
	*/

	//list的iterator的例子
	it = v1.begin(); //v1.begin()返回指向容器中第一个元素的双向迭代器（正向迭代器）
	it = v1.end();//指向尾端的下一個位置的iterator
	v1.rbegin(); //Returns a reverse iterator pointing to the last element in the container
	v1.rend(); //返回指向第一个元素所在位置前一个位置的反向双向迭代器
	v1.cbegin() //和 begin() 功能相同，只不过在其基础上，正向迭代器增加了 const 属性，即不能用于修改元素。
	
	//get the element
	v1[0]; //just like array
	v1.front(); //first element 
	v1.back(); //last element
	

	//add or remove element
	v2.push_back(1); //add an element at the vector end
	v2.pop_back();//delete an element at the vector end
	v2.insert(v2.begin(), 999); //add an(some) elements before the specific position,position needs to be a iterator (in this example add 999 at the begining of v2) 
	it = v1.begin();
	v1.insert(it, 5, 66); //add 5 個 66 to the begining of v1 (填入多個相同數字)
	v1.insert(v1.begin() + 1, v2.begin(), v2.end()); //將另一獨立的vector或陣列插入舊有的vector
	v1.insert(v1.begin(), { 30,40,50,60 }); //insert multiple element
	v1.erase(v1.begin()); //delete a single value at specific position
	v1.erase(v1.begin(), v1.begin() + 3); //delete a range,interval{)
	v1.clear(); //delete all element in list
	
	//operator = == != < > <= >=
	v1==v2; //v1 equals v2
	
	//get the range/size 
	v1.empty(); //see if the vector is empty (empty->true)
	v1.size(); //vector have how many elements
	v1.resize(20); //change the size (smaller->delete end;bigger->padding 0)

	//traversal
	for (int i = 0; i < v2.size(); ++i) cout << v2[i] << endl; //
	for (auto it2 = v2.begin(); it2 != v2.end(); ++it2) cout << *it2 << endl; //by iterator 前到後
	//by iterator 後到前 (只用iterator的話會報錯!要用reverse iterator)
	for (vector<int>:: reverse_iterator it = v2.rbegin(); it != v2.rend(); it ++) cout << *it << endl; 
	

	system("pause");
	return 0;
}
