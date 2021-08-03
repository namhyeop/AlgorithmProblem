#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 2222;

int board[MAX][MAX];
int parent[100001];

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

queue<pair<int, int>> union_q;
queue<pair<int, int>> bfs_q;
int row, col, num;

int find(int idx)
{
	if (idx == parent[idx])
		return idx;
	else
		return parent[idx] = find(parent[idx]);
}

void merge(int a, int b)
{
	int parentA = find(a);
	int parentB = find(b);
	if (parentA != parentB)
		parent[parentA] = parentB;
}

bool is_same_parent(int a, int b)
{
	int parentA = find(a);
	int parentB = find(b);

	return parentA == parentB;

}
int main(void)
{
	fastio;
	cin >> row >> num;
	col = row;

	for (int i = 0; i < num; i++)
	{
		int y, x;
		cin >> y >> x;
		union_q.push({ x - 1, y - 1 });
		board[x - 1][y - 1] = i + 1;
	}

	for (int i = 0; i < 100001; i++)
		parent[i] = i;

	int count = 0;

	while (num > 1)
	{
		auto merge_civil = [&]()
		{
			while (!union_q.empty())
			{
				int curX = union_q.front().first;
				int curY = union_q.front().second;
				bfs_q.push({ curX, curY });
				union_q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextX = curX + moveX[i];
					int nextY = curY + moveY[i];
					int cur_civil = board[curX][curY];
					int neighbor_civil = board[nextX][nextY];
					
					//다음 탐색지역이 범위가 초과되거나 다음 탐색지역이 문명도 없는 지역이라면 탐색을 안한다.
					if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || !board[nextX][nextY])
						continue;

					//인접한 문명이 현재 문명과 같고 이미 같은 문명이라면 결합할 의미가 없다.
					//인접한 문명이 다른 번호이고 다른 문명에 속해 있어야만 결합한다.
					//밑의 BFS탐색을 해도 결합을 한 뒤에 퍼진녀석들은 결합이 안된다, 왜냐하면 이미 부모정보에 같은 값으로 갱신이되어 is_same_parent에서 걸러진다
					if (cur_civil == neighbor_civil || is_same_parent(cur_civil, neighbor_civil))
						continue;
					merge(cur_civil, neighbor_civil);
					num--;
				}
			}
		};

		merge_civil();

		if (num == 1)
		{
			cout << count << "\n";
			return 0;
		}

		auto bfs_civil = [&]()
		{
			while (!bfs_q.empty())
			{
				int curX = bfs_q.front().first;
				int curY = bfs_q.front().second;
				bfs_q.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextX = curX + moveX[i];
					int nextY = curY + moveY[i];

					if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || board[nextX][nextY] != 0)
						continue;

					board[nextX][nextY] = board[curX][curY];
					union_q.push({ nextX, nextY });
				}
			}
		};
		bfs_civil();
		count++;
	}
}
