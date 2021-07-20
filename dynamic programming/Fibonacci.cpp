#include <cstdlib>
#include <iostream>
using namespace std;

int store[1000] = { 0 };

int f_dp(int n)
{
	if (store[n]||n==0)      //because store[0]=0 and we initial store array to 0
		return store[n];
	else
	{
		store[n] = f_dp(n-1)+f_dp(n-2);
		return store[n];
	}
}

int main()
{
	store[0] = 0;
	store[1] = 1;
	cout << f_dp(14)<<endl;

	system("pause");
	return 0;
}
