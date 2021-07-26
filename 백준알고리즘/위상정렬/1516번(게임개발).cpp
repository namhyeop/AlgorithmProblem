#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 501;
int n;
//걸리는시간, 지을건물
vector<int> board[MAX];
int b_time[MAX];
int inDegree[MAX];

int main(void)
{
	fastio;
	cin >> n;

	for (int t = 1; t <= n; t++)
	{
		int time;
		cin >> time;
		b_time[t] = time;
		while (1)
		{
			int num;
			cin >> num;
			if (num == -1)
				break;
			//num건물들이 필요한 건물들의 리스트를 추가
			board[num].push_back(t);
			//지으려는 건물의 inDegree 설정
			inDegree[t]++;
		}
	}

	//위상 정렬을 만들기 위한 indegree 설정 count == 0이면 q에 삽입한다.
	queue<int> q;
	int ret[MAX] = { 0 };
	for (int i = 1; i <= n; i++)
	if (inDegree[i] == 0)
		q.push(i);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		ret[cur] += b_time[cur];
		for (auto next : board[cur])
		{
			inDegree[next]--;
			//건물을 짓기 위해서는 (해당 건물 건축 시간 + 건축 하는 건물 중에 가장 큰 시간)이다.
			ret[next] = max(ret[next], ret[cur]);
			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ret[i] << "\n";
}
