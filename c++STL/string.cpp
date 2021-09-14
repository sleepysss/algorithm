#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//string:difference from C-style string,c++-style string does not need a NULL character

int main()
{
	//declare new string
	string str1;
	string str2 = "Hello";
	string str3("Halo");
	string str4(str2);
	string name[3] = { "Sleepy","Bear","qqq" };

	//operator = == + > < ........
	str1 + str2; //concatenate strings,
	str1 += str2; //string1=string1+string2
	str4 = str1; //easy to copy
	str4 > str1;//compare two strings character by character,if same->next char,else->by ASCII

	//length of the string
	str2.length();

	//empty or not
	str2.empty();

	//some member function
	str1.append(str2); //append str2 after str1
	str1.append(str2, 0, 2); //append str2 range[0,2) to str1  (ie:str1:"Hello" str2:"HelloHe")
	str2.erase(0,3); //delete char range: [0,3) 
	str1.swap(str3); //str1<->str3
	str1.clear(); //delete all char in the string
	str1.insert(2, str3); //from st1 second char,insert str3
	str1.find(str2); //find str2 in str1,find->return index,not find->return npos
	str1.find(str3, 2); //find str3 in str1(start from index 2),find->return index,not find->return npos
	//if (str1.find(str2) != string::npos) {............}
	str1.compare(str2); //same->0,difference->1

	//type in
	//cin will stop when there is enter or space
	getline(cin, str4); //can have space ! can continue typing
	(cin>>store).get(); //if continue typing,we can use this method to ignore enter

	system("pause");
	return 0;
}
