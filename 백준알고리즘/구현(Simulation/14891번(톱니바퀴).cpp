#include<bits/stdc++.h>

using namespace std;
#define TOBIN_NUM 4
#define TIME 8

int tobni[TOBIN_NUM][TIME] = { 0 };
int way[2] = { -1, 1 };
int k;

int print_answer()
{
	int answer = 0;
	for (int i = 0; i < TOBIN_NUM; i++)
		answer += (tobni[i][0] == 1 ? pow(2, i) : 0);
	return answer;
}
void change_tobni_num(int rotate_tobni, int rotate_way)
{
	if (rotate_way == 1)
	{
		int sub = tobni[rotate_tobni][TIME - 1];
		for (int i = TIME - 1; i > 0; i--)
			tobni[rotate_tobni][i] = tobni[rotate_tobni][i - 1];
		tobni[rotate_tobni][0] = sub;
	}
	else if (rotate_way == -1)
	{
		int sub = tobni[rotate_tobni][0];
		for (int i = 1; i < TIME; i++)
		{
			tobni[rotate_tobni][i - 1] = tobni[rotate_tobni][i];
		}
		tobni[rotate_tobni][TIME - 1] = sub;
	}
}

void rotate_tobni(int rotate_tobni, int rotate_way)
{
	int rotateWay[TOBIN_NUM] = { 0, 0, 0, 0 };
	rotateWay[rotate_tobni] = rotate_way;

	queue<pair<int, int>> search_queue;

	int start = rotate_tobni;
	for (int i = 0; i < 2; i++)
	{
		int next = start + way[i];
		if (next >= 0 && next < TOBIN_NUM ) //
			search_queue.push({ start, next });
	}

	while (search_queue.size())
	{
		pair<int, int> move_pair = search_queue.front();
		search_queue.pop();

		int small = (move_pair.first < move_pair.second ? move_pair.first : move_pair.second);
		int big = (move_pair.first < move_pair.second ? move_pair.second : move_pair.first);

		if (tobni[small][2] == tobni[big][6])
			continue;

		rotateWay[move_pair.second] = -(rotateWay[move_pair.first]);

		int start = move_pair.second;
		for (int i = 0; i < 2; i++)
		{
			int next = start + way[i];
			if ((next >= 0) && (next < TOBIN_NUM) && (rotateWay[next] == 0))
				search_queue.push({ start, next });
		}
	}
	for (int i = 0; i < TOBIN_NUM; i++)
		change_tobni_num(i, rotateWay[i]);
}
int main(void)
{
	for (int i = 0; i < TOBIN_NUM; i++)
	for (int j = 0; j < TIME; j++)
		scanf("%1d", &tobni[i][j]);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int tobni_num, rotate_way;
		cin >> tobni_num >> rotate_way;
		 
		rotate_tobni(tobni_num - 1, rotate_way);
	}
	cout << print_answer();

	return 0;
}
