#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX 999

//以某一vertex當出發點,再與其相連且尚未被選取的vertex中,選擇weight最小的邊,並將新的vertex加入,重複此步驟

int G[7][7] = { { MAX,12, 8, 13, MAX, MAX, MAX},{12, MAX,21, MAX, 32,7,MAX},{ 8,21, MAX, MAX, MAX, 2, MAX},{ 13, MAX, MAX, MAX,MAX, MAX, 9},
                        { MAX, 32, MAX,MAX, MAX,MAX,MAX},{ MAX, 7, 2, MAX,MAX, MAX, MAX},{ MAX,MAX ,MAX, 9,MAX, MAX, MAX} };
vector<pair<int, int>> store; //store the adding edge of the MST
bool visited[7] = { 0 }; //in the justice legend or not
int Distance[7] = { 0, MAX , MAX , MAX , MAX , MAX , MAX };  //distance from justice lengend to other vertex
int total_cost = 0; //cost of the MST

void Prim(int start_vertex)
{
	Distance[start_vertex] = 0;
	int smallest, smallest_vertex;
	for (int round = 0; round < 7; ++round)
	{
		smallest = MAX;
		for (int i = 0; i < 7; ++i)  //get next vertex by choosing the smallest distance
		{
			if (Distance[i] < smallest&&!visited[i])
			{
				smallest = Distance[i];
				smallest_vertex = i;
			}
		}

		if (smallest_vertex == -1)  //smallest=INF,cant go(exist disconnected vertex)
		{
			cout << "error!does not have MST" << endl;
			break;
		}

		for (int i = 0; i < 7; ++i)  //store the adding edge  //traverse each vertex to find the vertex that its distance from vertex i to smallest_vertex equals smallest,and vertex i is in justice legend 
		{
			if (round == 0) break; //there is no edge adding at round 0
			if (G[i][smallest_vertex] == smallest && visited[i])   //find the adding edge of the MST  
				store.push_back({ i,smallest_vertex });
		}

		visited[smallest_vertex]=true;  //add the vertex
		total_cost += smallest;
		//cout << total_cost << endl;

		for (int i = 0; i < 7; ++i) //update the Distance
		{
			if (G[smallest_vertex][i] < Distance[i] && !visited[i])  //see if by adding smallest_vertex to justice legend,distance from legend to vertex i will be shorter or not
				Distance[i] = G[smallest_vertex][i];                         //we dont need to walk through all the legend member because new adding vertex(smallest_vertex) will only have effect on its neighbor 
		}                                                                                         //vertex !
	}
}

int main()
{
	Prim(0);
	cout << total_cost << endl;
	system("pause");
	return 0;
}

