#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int D, V;

bool order(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int main(int argc, char *argv[])
{
	vector<pair<int, int>> board;

	for (int i = 0; i < 11; i++)
	{
		cin >> D >> V;
		board.push_back({ D, V });
	}

	sort(board.begin(), board.end(), order);

	int ret = 0;
	int time = 0;
	int curV = 0;

	for (int i = 0; i < 11; i++)
	{
		time += board[i].first;
		curV = board[i].second;
		ret += (time + curV * 20);
	}

	cout << ret << "\n";

	return 0;
}
