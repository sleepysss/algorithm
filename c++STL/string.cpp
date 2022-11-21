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
	str1 + str2; //concatenate strings(串接字串)  String birthday = "Happy" + " " + "Birthday";  -> 輸出 Happy Birthday
	str1 += str2; //string1=string1+string2
	str4 = str1; //easy to copy
	str4 > str1;//compare two strings character by character,if same->next char,else->by ASCII

	//length of the string (Both string::size and string::length are synonyms and return the exact same value.)
	str2.length();  //The method string::length returns the length of the string, in terms of bytes.
	str2.size();    //The method string::size returns the length of the string, in terms of bytes.

	//empty or not
	str2.empty();

	//some member function
	str1.append(str2); //(拼接)append str2 after str1 (Extends the string by appending additional characters at the end of its current value)
	str1.append(str2, 0, 2); //append str2 range[0,2) to str1  
	/*
	//ex:string reptile = "catapillar"; string mammal = "whale"; 
	//   reptile.append(mammal,0,5); -> catapillarwhale
	*/
	str2.erase(0,3); //delete char range: [0,3) 
	str1.swap(str3); //str1<->str3
	str1.clear(); //delete all char in the string
	str1.insert(2, str3); //(插入)from st1 second char,insert str3   ex:string animal = "catapillar"; animal.insert(5,"****");  -> catap****illar
	str1.find(str2); //find str2 in str1,find->return index,not find->return npos
	str1.find(str3, 2); //find str3 in str1(start from index 2),find->return index,not find->return npos
	//if (str1.find(str2) != string::npos) {............}
	str1.compare(str2); //same->0,difference->1

	//type in
	//cin will stop when there is enter or space, so we need getline
	/*
	//istream& getline(istream& is, string& str, char delim);
	//is:它是istream類的對象，它告訴函數有關從何處讀取輸入的流。
	//str:這是一個字符串對象，從流中讀取輸入後，將輸入存儲在此對象中。
	//delim:它是定界字符，它告訴函數在達到該字符後停止讀取進一步的輸入。(default:'\n')
	//If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).
	//当 cin 读取数据时，它会传递并忽略任何前导白色空格字符（空格、制表符或换行符）。一旦它接触到第一个非空格字符即开始阅读，当它读取到下一个空白字符时，它将停止读取
	//return value:只要可以读到文件内容，返回值就一直是True. 如果读取失败，那么会抛出相对应的异常。
	*/
	getline(cin, str4); //can have space ! can continue typing
	(cin>>store).get(); //if continue typing,we can use this method to ignore enter

	system("pause");
	return 0;
}
