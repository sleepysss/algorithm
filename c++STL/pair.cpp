#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

pair<int,string> getPreson()
{
    return make_pair(10,"ttyy");
}

int main()
{
    //pair的意思就是把兩個物件裝在一起的東西，而第1個物件的type就是T1, 第二個就是T2, 
    //分別是你傳入的第1和第二個類別
    //舉例而言pair<int, bool>就是把一個int和一個bool裝在一起
    //使用pair需 #include <utility>
    
    pair<int,string> p1; //pair<T1,T2> p1 (T1,T2可以為任何類別)
    pair<int,string> p2(10,"hello");
    pair<int,string> p3(p1);
    p1=make_pair(60,"cvbn"); //回傳一個以x為first, 以y為second的pair。
    pair<int,string> p4(make_pair(66,"eeee"));
    vector<pair<string, int> > vp;
    vp.push_back(make_pair("favorite game", 9800));
    
    p1.first=99; //first、second分別是pair的第一、二個物件。
    p1.second="qwer";
    
    string name;
    int num;
    tie(num,name)=getPreson();  //批量赋值, 需 #include <tuple>
    cout<<name<<" "<<num<<endl;
    
    return 0;
}
