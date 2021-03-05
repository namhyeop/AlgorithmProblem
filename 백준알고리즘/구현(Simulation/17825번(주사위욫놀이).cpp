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
