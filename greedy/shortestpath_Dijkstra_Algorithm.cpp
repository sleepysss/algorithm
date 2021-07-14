#include <cstdlib>
#include <iostream>
using namespace std;
#define MAX 999

//首先以某一vertex為出發點,在尚未被選取的vertex裡,選擇加入離出發點距離最近的vertex,並且透過新增的vertex更新到達其他vertex的距離,重複這步驟,直到所有vertex都被加入

int G[6][6] = { {MAX,1,12,MAX,MAX,MAX},{MAX,MAX,9,3,MAX,MAX},{MAX,MAX,MAX,MAX,5,MAX},{MAX,MAX,4,MAX,13,15},{MAX,MAX,MAX,MAX,MAX,4},{MAX,MAX,MAX,MAX,MAX,MAX} };
int Distance[6] = { 0 ,1 ,12 ,MAX ,MAX ,MAX }; //distance from start to other vertex
bool choosen[6] = { 0 }; //vertex is choosen or not

void ShortestPath(int start_vertex)
{
	int smallest,smallest_vertex;
	choosen[start_vertex] = true;
	for (int round = 0; round < 5; ++round) //not 6 because start_vertex round has finished by initial
	{
		smallest = MAX;
		smallest_vertex = -1;
		for (int i = 0; i < 6; ++i)   //get next vertex  by choosing the smallest distance 
		{
			if (Distance[i] < smallest && !choosen[i])
			{
				smallest = Distance[i];
				smallest_vertex = i;
			}
		}

		if (smallest_vertex == -1)  //smallest disitance is INF
		{
			cout << "does not exist shortest path" << endl;
			return;
		}

		choosen[smallest_vertex] = true; //add the vertex

		for (int i = 0; i < 6; ++i)   //update Distance,see if by adding a vertex can have shorter Distance to other vertex
		{
			if (choosen[i]) continue;  //we dont need to update the Distance of the vertex we have choosen
			if(Distance[i] > (Distance[smallest_vertex] + G[smallest_vertex][i]))  //have shorter Distance or not
				Distance[i] = (Distance[smallest_vertex] + G[smallest_vertex][i]);
		}
	}
}

int main()
{
	ShortestPath(0);
	cout << "shortest path from 0 to " << endl<<endl;
	for (int i = 0; i < 6; ++i)
		cout << i << " " <<"Distance: "<< Distance[i] << endl;
	system("pause");
	return 0;
}
