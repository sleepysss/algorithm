#include <cstdlib>
#include <iostream>
using namespace std;

//在數列中挑選一個數,稱為pivot,然後調整數列(using Partition()),使得"所有在pivot左邊的數都比pivot還小,所有在pivot右邊的數,
//都比pivot還大,這時原數列會分成3塊,<pivot pivot >pivot,而pivot固定住了(已排完),將<pivot和>pivot的數列視為新的
//數列,重複前面的步驟,直到分不出新的數列為止

int Partition(int nums[],int front_index, int end_index)
{
	int pivot = nums[end_index];
	int smaller_than_pivot_num_last_index = front_index - 1;  //The last index of the sequence formed by all numbers less
	int temp;                                                 //than pivot(front-1 because maybe all the nums are bigger than pivot)

	for (int i = front_index; i < end_index; ++i)  //traverse through the range of the nums array
	{
		if (nums[i] < pivot) //if smaller than pivot,change place
		{
			temp = nums[i];
			nums[i] = nums[++smaller_than_pivot_num_last_index];
			nums[smaller_than_pivot_num_last_index] = temp;
		}
	}
	
	temp = pivot;     //change pivot place from <pivot >pivot pivot to  <pivot pivot >pivot
	nums[end_index]=nums[++smaller_than_pivot_num_last_index];
	nums[smaller_than_pivot_num_last_index] = temp;
	return smaller_than_pivot_num_last_index;  //return pivot index
}

void quicksort(int nums[],int front_index,int end_index)
{
	if (front_index < end_index) //數列有>1個數且"合理"才需排
	{
		int pivot_index=Partition(nums,front_index,end_index);
		quicksort(nums, pivot_index + 1, end_index);
		quicksort(nums, front_index, pivot_index - 1);
	}
}

int main()
{
	int nums[] = { 15,22,13,27,12,10,20,25 };
	quicksort(nums,0,7);

	system("pause");
	return 0;
}
