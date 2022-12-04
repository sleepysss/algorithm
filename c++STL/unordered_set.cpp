#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    //unordered_set 裡的元素是唯一的,且為無排序的,值不可修改
    
    unordered_set<int> s1;
    int arr[]={1,2,3,4,5};
    unordered_set<int> s2(arr,arr+5);
    unordered_set<int> s3(s1);
    unordered_set<int> s4 {8,9,10};
    
    s1.insert(1); //插入元素 (不在set裡才會插入)
    s1.insert({6,7,8}); //initializer list insertion
    s1.insert(arr,arr+5); //range insertion
    vector<int> v1 {11,12,13}; //range insertion
    s1.insert(v1.begin(),v1.begin()+2); //加11,12
    s1.erase(2); //刪除指定元素,會回傳刪除的元素個數(0or1)
    s1.erase(s1.find(11)); //刪除iterator所在位置的值
    s1.clear();
    
    s1.find(60); //返回iterator
    s1.count(4); //該元素在set內的個數,可用來判斷該元素是否存在(1:存在,0:不存在)
    s1.empty(); //set is empty=>true
    
    for(auto iter=s1.begin();iter!=s1.end();++iter)
        cout<<*iter<<endl;
    
    return 0;
}
