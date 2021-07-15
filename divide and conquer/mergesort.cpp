#include <cstdlib>
#include <iostream>
using namespace std;
#define MAX 999

//將兩個排序好的array合併,來得到另一個排序好的array

void merge(int nums[],int front_index,int end_index,int mid_index)  //merge two subarray into one (two subarray are both sorted because of recursive structure)
{
	int i,j;
	int *left_subarray = new int[mid_index - front_index + 1 + 1];  //front~mid + 1 bit INF to show that all the value in subarr have been taken
	int *right_subarray = new int[end_index - mid_index + 1];     //mid+1~end + 1 bit INF
	int left_subarray_index=0, right_sub_array_index=0;  //can know which value has not been choosen to nums array yet

	for ( i = 0,j=front_index; i < (mid_index - front_index + 1); ++i,++j) left_subarray[i] = nums[j];  //assignment
	left_subarray[i] = MAX;
	for (i = 0,j=mid_index+1; i < end_index-mid_index; ++i,++j) right_subarray[i] = nums[j];   
	right_subarray[i] = MAX;

	for (int i = front_index; i <= end_index; ++i)   //choose smaller subarray value and put it into original array(nums[])
	{
		if (left_subarray[left_subarray_index] < right_subarray[right_sub_array_index])
			nums[i] = left_subarray[left_subarray_index++];
		else
			nums[i] = right_subarray[right_sub_array_index++];
	}
}

void mergesort(int nums[],int front_index,int end_index)
{
	if (end_index > front_index)
	{
		int mid_index = (end_index + front_index) / 2;
		mergesort(nums,front_index,mid_index);                              //divide (front~mid)
		mergesort(nums, mid_index + 1, end_index);                     //divide  (mid+1~end)
		merge(nums, front_index, end_index,mid_index);                //conquer          
	}
}

int main()
{
	int nums[] = { 5,3,8,6,2,7,1,4,9,0};
	mergesort(nums, 0, 9);
	for (int i = 0; i < 10; ++i) cout << nums[i] << "　";
	cout << endl;
	system("pause");
	return 0;
}
