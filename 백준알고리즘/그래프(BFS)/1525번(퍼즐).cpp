#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

#define TARGET 123456789

int start = 0;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
map<int, int> visited;

void bfs()
{
	queue<int> q;
	q.push(start);
	visited[start] = 0;
	 
	while (!q.empty())
	{
		int cur = q.front();
		string s = to_string(cur);
		q.pop();

		if (cur == TARGET)
			break;

		int z = s.find('9');
		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (0 <= nextY && nextY < 3 && 0 <= nextX && nextX < 3)
			{
				string tmp = s;
				swap(tmp[3 * y + x], tmp[3 * nextY + nextX]);
				
				int next = stoi(tmp);
				if (!visited.count(next))
				{
					visited[next] = visited[cur] + 1;
					q.push(next);
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		int num;
		cin >> num;

		if (num == 0)
			num = 9;
		start = start * 10 + num;
	}
	
	bfs();

	if (!visited.count(TARGET))
		cout << -1 << "\n";
	else
		cout << visited[TARGET] << "\n";
	return 0;
}
