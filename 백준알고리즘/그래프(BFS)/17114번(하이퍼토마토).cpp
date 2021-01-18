#include<iostream>
#include<queue>
#include<numeric>
#include<algorithm>
using namespace std;

namespace __I11__
{
	struct i11
	{
		int i[11];
		int& operator [] (int idx) { return i[idx]; }
	}I;

	istream& operator >> (istream& in, i11& x)
	{
		for (int i = 0; i < 11; i++)
			in >> x[i];
		return in;
	}

	int to_int(i11& x)//1차원으로 다시 
	{
		int ret = 0;
		for (int i = 0; i < 11; i++)
		{
			ret *= I[i];
			ret += x[i];
		}
		return ret;
	}

	i11 to_i11(int x) //11차원으로 다시 바꿔주는 경우
	{
		i11 ret;
		for (int i = 10; i >= 0; i--)
		{
			ret[i] = x % I[i];
			x /= I[i];
		}
		return ret;
	}
}
using namespace __I11__;

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	cin >> I;
	reverse(I.i, I.i + 11);
	int n = accumulate(I.i, I.i + 11, 1, multiplies<int>());
	vector<int> board(n);
	queue<int> Q;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		if (board[i] == 1)
			Q.push(i);
	}
	//bfs

	while (!Q.empty())
	{
		auto cur = to_i11(Q.front());
		Q.pop();
		for (int i = 0; i < 11; i++)
		for (int t = 0; t < 2; t++)
		{
			auto next = cur;
			next[i] += t ? 1 : -1; //+1인경우, -1인경우
			if (next[i] < 0 || next[i] >= I[i])
				continue;
			if (board[to_int(next)]) //이미 토마토라면 건너 뛰어야함
				continue;
			board[to_int(next)] = board[to_int(cur)] + 1;
			Q.push(to_int(next));
		}
	}

	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		if (board[i] == -1)
			continue;
		if (board[i] == 0)
		{
			cout << -1 << "\n";
			return 0;
		}
		ret = max(ret, board[i]);
	}
	cout << ret - 1 << "\n";

	return 0;
}
/*
vector<pair<int, int>> adj[100][100];
vector<int> adj[100 * 100];

adj[i][j].push_back({ nx, ny });

adj[i * m + j].push_back({ nx * m + ny }); 
cur;

11차원인 경우 찾아주는 구현법
x = cur / m;
y = cur % m;

1차원으로 만들었을 경우 찾아주는 구현법
i * m +j
*/

