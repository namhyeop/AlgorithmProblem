#include<bits/stdc++.h>
#define MAX 11
using namespace std;

int n;
int district[MAX]; //인구수를 저장하기 위한 배열
bool connect[MAX][MAX]; //데이터 값을 입력하고 연결관계를 저장하기 위한 배열
bool selected[MAX]; // 조합을 구현할 때 체크 여부를 위해 필요한 배열
bool visited[MAX]; //BFS 탐색시 방문 체크 여부를 위해 필요한 배열
int ret = INT_MAX;
void calculate()
{
	int pickNum = 0;
	int unPickNum = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (selected[i] == true)
			pickNum = pickNum + district[i];
		else
			unPickNum = unPickNum + district[i];
	}
	sum = abs(pickNum - unPickNum);

	if (ret > sum)
		ret = sum;
	
}
bool check_connection(vector<int> v, bool T)
{
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(v[0]);
	visited[v[0]] = true;
	int cnt = 1;

	while (q.empty() == 0)
	{
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (connect[x][i] == true && selected[i] == T && visited[i] == false)
			{
				visited[i] = true;
				cnt++;
				q.push(i);
			}
		}
	}

	if (v.size() == cnt)
		return true;
	return false;
}

bool check()
{
	vector<int> A, B;
	for (int i = 1; i <= n; i++)
	{
		if (selected[i] == true) //고른 경우와 고르지 않은 경우를 구분해서 백터값 A, B에 넣어준다.
			A.push_back(i);
		else
			B.push_back(i);
	}

	//뽑은 경우와 안 뽑은 경우 A, B 둘 중 하나가 모든 경우를 뽑은 경우를 예외처리 해주어야 한다.
	if (A.size() == 0 || B.size() == 0)
		return false;

	bool Astate = check_connection(A, true);
	if (Astate == false)
		return false;
	
	bool Bstate = check_connection(B, false);
	if (Bstate == false)
		return false;

	return true;
}

void DFS(int idx, int cnt)
{
	if (cnt >= 1)
	{
		if (check() == true)
			calculate();
	}

	for (int i = idx; i <= n; i++)
	{
		if (selected[i] == true)
			continue;
		selected[i] = true;
		DFS(i, cnt + 1);
		selected[i] = false;
	}
}
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> district[i];
	
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int tmp;
			cin >> tmp;
			connect[i][tmp] = true;
			connect[tmp][i] = true;
		}
	}

	DFS(1, 0);

	if (ret == INT_MAX)
		cout << -1 << "\n";
	else
		cout << ret << "\n";

	return 0;
}
