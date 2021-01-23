#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(int argc, char *argv[])
{
	int N;
	cin >> N;

	vector<pair<int, int>> day;

	for (int i = 0; i < N; i++)
	{
		int month1, day1, month2, day2;
		cin >> month1 >> day1 >> month2 >> day2;

		day.push_back({ month1 * 100 + day1, month2 * 100 + day2 });
	}

	sort(day.begin(), day.end());

	int idx = -1;
	int tmp = 0;
	int ret = 0;

	for (int i = 301; i <= 1130 && idx < N; i = tmp)
	{
		bool flag = false;
		idx++;
		for (int j = idx; j < day.size(); j++)
		{
			if (day[j].first > i)
				break;
			
			if (tmp < day[j].second)
			{
				tmp = day[j].second;
				idx = j;
				flag = true;
			}
		}

		if (flag)
		{
			ret++;
		}
		else
		{
			cout << 0 << "\n";
			return 0;
		}
	}
	cout << ret << "\n";

	return 0;
}
