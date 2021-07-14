#include <cstdlib>
#include <iostream>
using namespace std;

//Depth-First-Search,DFS

int G[5][5] = { {0,1,0,1,0},{1,0,1,0,0},{0,1,0,0,0},{1,0,0,0,1},{0,0,0,1,0} };  //graph
bool Visited[5] = { 0 }; //initial to 0(havent visit)

void DFS(int vertex)
{
	Visited[vertex] = true; 
	cout << vertex << "  " ; //visit vertex
	for (int i = 0; i <5; ++i) //walk through all the vertex
	{
		if (G[vertex][i] == 1 && !Visited[i])  //connect and has not visit yet
			DFS(i);
	}
}

int main()
{
	DFS(1);
	cout << endl;
	system("pause");
	return 0;
}
