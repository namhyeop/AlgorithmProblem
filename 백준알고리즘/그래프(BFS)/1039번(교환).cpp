#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
int k;
string input;
queue<string> q;

int main(void)
{
	fastio;
	cin >> input >> k;
	int M = input.size();

	if (M == 1 || (M == 2 && stoi(input) % 10 == 0))
	{
		cout << -1 << "\n";
		return 0;
	}

	auto BFS = [&]() -> int
	{
		q.push(input);
		int cnt = 0;
		int max_ret = 0;

		while (!q.empty() && cnt < k)
		{
			int qSize = q.size();
			set<string> visited;
			for (int i = 0; i < qSize; i++)
			{
				string cur = q.front();
				q.pop();

				for (int i = 0; i < M - 1; i++)
				{
					for (int j = i + 1; j < M; j++)
					{
						//바꾸려는 숫자가 0인데 그게 첫 번째 자리로 오면 안되므로 continue
						if (i == 0 && cur[j] == '0')
							continue;
						swap(cur[i], cur[j]);
						if (!visited.count(cur)) //방문한 숫자가 아니라면
						{
							if (cnt == k - 1)
								max_ret = max(max_ret, stoi(cur));
							q.push(cur);
							visited.insert(cur);
						}
						swap(cur[i], cur[j]);
					}
				}
			}
			cnt++;
		}
		if (cnt != k)
			return -1;
		else
			return max_ret;
	};
	cout << BFS() << "\n";
}
/*
#include<iostream>
#include<queue>

using namespace std;
#define MAX 1000001

int N; //문제의 숫자
int K; //연산 횟수
int M; //정수 N의 자릿수를 의미


// 정수 n의 10^i자리의 숫자 리턴
int digit(int n, int i)
{
	for (int k = 0; k < i; k++)
		n /= 10;
	return n % 10;
}

int swapDigit(int n, int i, int j)
{
	char S[8];
	sprintf(S, "%d", n);
	swap(S[M - i - 1], S[M - j - 1]);
	sscanf(S, "%d", &n);
	return n;
}

int bfs()
{
	int ret = -1;
	queue<int> q;
	q.push(N);

	for (int i = 0; i < K; i++)
	{
		int qSize = q.size();
		bool visited[MAX] = { 0 };

		for (int j = 0; j < qSize; j++)
		{
			int curr = q.front();
			q.pop();

			for (int k = 0; k < M - 1; k++)
			for (int l = k + 1; l < M; l++)
			{
				if (l < M - 1 || digit(curr, k))
				{
					int next = swapDigit(curr, k, l);
					if (!visited[next])
					{
						visited[next] = true;
						q.push(next);
					}
				}
			}
		}
	}

	while (!q.empty())
	{
		ret = max(ret, q.front());
		q.pop();
	}

	return ret;
}
int main(int argc, char *argv[])
{
	cin >> N >> K;

	//N의 자릿수를 알기 위한 연산이다, 나누기를 진행한만큼 카운팅을 진행.
	int tmp = N;
	while (tmp)
	{
		M++;
		tmp /= 10;
	}

	int ret = bfs();

	cout << ret << "\n";
}
*/
