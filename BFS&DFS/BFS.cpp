#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

//Breadth-First-Search,BFS

int G[5][5] = { {0,1,0,1,0},{1,0,1,0,0},{0,1,0,0,0},{1,0,0,0,1},{0,0,0,1,0} };  //graph
bool Visited[5] = { 0 }; //initial to 0(havent visit)
queue<int> q;

void BFS(int vertex)
{
	q.push(vertex);
	Visited[vertex] = 1;

	while (!q.empty()) //next round
	{
		cout << q.front() << "  ";
		for (int i = 0; i < 5; ++i)
		{
			if (!Visited[i] && G[q.front()][i] == 1)  //put all connect and havent visit vertex to queue
			{
				q.push(i); //put into queue
				Visited[i] = 1;
			}
		}
		q.pop(); //pop the front
	}
}

int main()
{
	BFS(3);
	cout << endl;

	system("pause");
	return 0;
}
