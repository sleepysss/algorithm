#include <cstdlib>
#include <iostream>
using namespace std;
#define MAX 999

//首先以某一vertex為出發點,在尚未被選取的vertex裡,選擇加入離出發點距離最近的vertex,並且透過新增的vertex更新到達其他vertex的距離,重複這步驟,直到所有vertex都被加入
//任兩點之間的最短路徑有兩種情況：1.此兩點之間有邊相連，是相鄰的兩點(列出所有的邊就可得到答案) 2.此兩點會經過其它點，產生最短路徑(需要先找出指定點與
//另一點的最短路徑，畢竟只有最短路徑才能讓另一個路徑也是最短的)


int G[6][6] = { {MAX,1,12,MAX,MAX,MAX},{MAX,MAX,9,3,MAX,MAX},{MAX,MAX,MAX,MAX,5,MAX},{MAX,MAX,4,MAX,13,15},{MAX,MAX,MAX,MAX,MAX,4},{MAX,MAX,MAX,MAX,MAX,MAX} };
int Distance[6] = { 0 ,MAX ,MAX ,MAX ,MAX ,MAX }; //distance from start to other vertex //we dont know the distance at the begining
bool choosen[6] = { 0 }; //vertex is choosen or not
int pre[6]={ -1 ,-1 ,-1 ,-1 ,-1 ,-1 }; //pre-node


void printPath(int start_vertex)
{
    if(pre[start_vertex]==-1)
    {
        cout<<start_vertex<<" ";
        return;
    }
    printPath(pre[start_vertex]);
    cout<<start_vertex<<" ";
}


void ShortestPath(int start_vertex)
{
	int smallest,smallest_vertex;
	for (int round = 0; round < 6; ++round)
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
			{
			    pre[i]=smallest_vertex;
			    Distance[i] = (Distance[smallest_vertex] + G[smallest_vertex][i]);
			}
		}
	}
}

int main()
{
	ShortestPath(0);
	cout << "shortest path from 0 to " << endl<<endl;
	for (int i = 0; i < 6; ++i)
	{
	    cout << i << " " <<"Distance: "<< Distance[i] << endl;
	    cout << "Path: ";
	    printPath(i);
	    cout<<endl<<endl;
	}
	
	//shortest path from 0 to 

	//0 Distance: 0
	//Path: 0 

	//1 Distance: 1
	//Path: 0 1 

	//2 Distance: 8
	//Path: 0 1 3 2 

	//3 Distance: 4
	//Path: 0 1 3 

	//4 Distance: 13
	//Path: 0 1 3 2 4 

	//5 Distance: 17
	//Path: 0 1 3 2 4 5 
	
	return 0;
}
