#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int nextY[] = {-1,-1,0,1,1,1,0,-1};
int nextX[] = {0,1,1,1,0,-1,-1,-1};

int solution(vector<int> arrows) 
{
	int answer = 0;
	map<pair<int, int>, bool > node_visited;
	map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;

	int y = 0;
	int x = 0;
	node_visited[{y, x}] = true;
	for (int dir : arrows) //1.방향의 크기만큼 이동한다.
	{
		for (int j = 0; j < 2; j++)//2.교차하는 도형의 예외처리를 위해 2칸씩 이동한다.
		{
			int dY = y + nextY[dir]; //이동할 위치
			int dX = x + nextX[dir];

			//이동할 위치가 방문했던 노드이면서 방문하지 않은 간선이라면 그것은 사이클을 이루는 하나의 도형이다.
			if (node_visited[{dY, dX}] && !edge_visited[{{ y, x }, { dY, dX }}])
			{
				edge_visited[{{ y, x }, { dY, dX }}] = true;
				edge_visited[{{ dY, dX }, { y, x }}] = true;
				y = dY;
				x = dX;
				answer++;
				continue;
			}
			node_visited[{dY, dX}] = true;
			edge_visited[{{ y, x }, { dY, dX }}] = true;
			edge_visited[{{dY, dX}, { y, x }}] = true;
			y = dY;
			x = dX;
		}
	}
	return answer;
}
