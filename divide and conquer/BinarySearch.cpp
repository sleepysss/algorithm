#include <iostream>
#include <cstdlib>
using namespace std;

//before binarysearch,the value should be sorted
//interval:[]
void BinarySearch(int left_index, int right_index, int nums[], int target)   
{
	int mid_index = (left_index + right_index) / 2;
	if (left_index > right_index)
	{
		cout << "does not exit" << endl;
		return;
	}

	if (nums[mid_index] == target)
		cout << "find " << target << endl;
	else if (nums[mid_index] > target)
		BinarySearch(left_index, mid_index - 1, nums, target);
	else
		BinarySearch(mid_index + 1, right_index, nums, target);
}

/*
mid will cut the region into three

left                                right
|                                       |   
[left,mid-1]     [mid]      [mid+1,right]
______________|___________|______________
   region1       region2        region3

*/

int main()
{
	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
	BinarySearch(0, 9, nums, 10);

	system("pause");
	return 0;
}
