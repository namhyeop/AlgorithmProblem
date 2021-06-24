#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 33;

vector<int> arr[MAX];
int board[MAX] = {
//0~20:외부 사이클
0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
//21~23:왼쪽
13,16,19,
//24~25: 아래쪽
22,24,
//26~28: 오른쪽
28,27,26,
//29: 중간
25,
//30 ~ 31: 위
30,35,
//32 : 도착
0
};

int nxt[MAX][6];

int main(void)
{
	fastio;
	for (int i = 1; i <= 20; i++)
		arr[i - 1].push_back(i);
	arr[5].push_back(21);
	arr[21].push_back(22);
	arr[22].push_back(23);
	arr[23].push_back(29);
	arr[10].push_back(24);
	arr[24].push_back(25);
	arr[25].push_back(29);
	arr[15].push_back(26);
	arr[26].push_back(27);
	arr[27].push_back(28);
	arr[28].push_back(29);
	arr[29].push_back(30);
	arr[30].push_back(31);
	arr[31].push_back(20);
	arr[20].push_back(32);
	arr[32].push_back(32);

	vector<int> v(10);
	for (int i = 0; i < 10; i++)
		cin >> v[i];

	auto calculator = [&](int i, int cnt)
	{
		i = arr[i][i == 5 || i == 10 || i == 15];
		cnt--;
		while (cnt)
		{
			i = arr[i][0];
			cnt--;
		}
		return i;
	};

	for (int i = 0; i <= 32; i++)
	for (int j = 1; j <= 5; j++)
		nxt[i][j] = calculator(i, j);

	function<int(int, int, int, int, int)> DFS = [&](int a, int b, int c, int d, int idx) -> int
	{
		if (idx == 10)
			return 0;
		int ret = 0;
		int nextA = nxt[a][v[idx]];
		int nextB = nxt[b][v[idx]];
		int nextC = nxt[c][v[idx]];
		int nextD = nxt[d][v[idx]];
		if (a != 32 && (nextA == 32 || nextA != b && nextA != c && nextA != d))
			ret = max(ret, DFS(nextA, b, c, d, idx + 1) + board[nextA]);
		if (b != 32 && (nextB == 32 || nextB != a && nextB != c && nextB != d))
			ret = max(ret, DFS(a, nextB, c, d, idx + 1) + board[nextB]);
		if (c != 32 && (nextC == 32 || nextC != a && nextC != b && nextC != d))
			ret = max(ret, DFS(a, b, nextC, d, idx + 1) + board[nextC]);
		if (d != 32 && (nextD == 32 || nextD != a && nextD != b && nextD != c))
			ret = max(ret, DFS(a, b, c, nextD, idx + 1) + board[nextD]);
		return ret;
	};
	cout << DFS(0, 0, 0, 0, 0) << "\n";
}
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dice[10];

int jump[33][6] = {
	{ 0, 1, 2, 3, 4, 5 },
	{ 2, 2, 3, 4, 5, 9 },
	{ 4, 3, 4, 5, 9, 10 },
	{ 6, 4, 5, 9, 10, 11 },
	{ 8, 5, 9, 10, 11, 12 },
	{ 10, 6, 7, 8, 20, 29 },
	{ 13, 7, 8, 20, 29, 30 },
	{ 16, 8, 20, 29, 30, 31 },
	{ 19, 20, 29, 30, 31, 32 },
	{ 12, 10, 11, 12, 13, 14 },
	{ 14, 11, 12, 13, 14, 15 },
	{ 16, 12, 13, 14, 15, 16 },
	{ 18, 13, 14, 15, 16, 17 },
	{ 20, 18, 19, 20, 29, 30 },
	{ 22, 15, 16, 17, 24, 25 },
	{ 24, 16, 17, 24, 25, 26 },
	{ 26, 17, 24, 25, 26, 27 },
	{ 28, 24, 25, 26, 27, 28 },
	{ 22, 19, 20, 29, 30, 31 },
	{ 24, 20, 29, 30, 31, 32 },
	{ 25, 29, 30, 31, 32, 32 },
	{ 26, 20, 29, 30, 31, 32 },
	{ 27, 21, 20, 29, 30, 31 },
	{ 28, 22, 21, 20, 29, 30 },
	{ 30, 23, 22, 21, 20, 29 },
	{ 32, 26, 27, 28, 31, 32 },
	{ 34, 27, 28, 31, 32, 32 },
	{ 36, 28, 31, 32, 32, 32 },
	{ 38, 31, 32, 32, 32, 32 },
	{ 30, 30, 31, 32, 32, 32 },
	{ 35, 31, 32, 32, 32, 32 },
	{ 40, 32, 32, 32, 32, 32 },
	{ 0, 32, 32, 32, 32, 32 }
};

int	ret;

void check(int bit)
{
	int score = 0;
	int occupation[35];
	int pos[4];
	memset(occupation, 0, sizeof(occupation));
	memset(pos, 0, sizeof(pos));
	occupation[0] = 4;

	for (int turn = 0; turn < 10; turn++)
	{
		int horse = (bit >> (turn * 2)) & 0x3;
		int move = dice[turn];
		int &current_pos = pos[horse];
		int next_pos = jump[current_pos][move];
		int get_score = jump[next_pos][0];
		if (occupation[next_pos] > 0 && next_pos && next_pos != 32)
			return;
		else
		{
			score += get_score;
			occupation[next_pos]++;
			occupation[current_pos]--;
			current_pos = next_pos;
		}
	}
	ret = max(ret, score);
}
int main()
{
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	for (int bit = 0; bit < (1 << 20); bit++)
		check(bit);

	cout << ret << "\n";
}
*/
