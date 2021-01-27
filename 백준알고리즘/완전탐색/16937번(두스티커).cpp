#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int height;
int width;
int N;
int ret;
vector<pair<int, int>> v;

bool chosSticker(pair<int,int> &a, pair<int,int> &b)
{
	if (a.first <= height && a.second <= width && b.first <= height && b.second <= width && !(height - b.first < a.first && width - b.second < a.second)) return 1;
	if (a.first <= height && a.second <= width && b.second <= height && b.first <= width && !(height - b.second < a.first && width - b.first < a.second)) return 1;
	if (a.second <= height && a.first <= width && b.first <= height && b.second <= width && !(height - b.first < a.second && width - b.second < a.first)) return 1;
	if (a.second <= height && a.first <= width && b.second <= height && b.first <= width && !(height - b.second < a.second && width - b.first < a.first)) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	cin >> height >> width;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int row;
		int col;
		cin >> row >> col;
		v.push_back({ row,col });
	}

	for (int i = 0; i < N; i++)
	for (int j = i + 1; j < N; j++)
	{
		if (chosSticker(v[i], v[j]))
			ret = max(ret, v[i].first *v[i].second + v[j].first * v[j].second);
	}

	cout << ret << "\n";

	return 0;
}
