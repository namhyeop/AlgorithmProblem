#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000

using namespace std;

bool visited[MAX];

struct subject
{
	int day;
	int point;

	subject() {}
	subject(int a, int b) : day(a), point(b) {}
};

bool cmp(subject &a, subject &b)
{
	return a.point > b.point;
}

int main(int argc, char *argv[])
{
	int N;
	int lastDay = 0;
	int ret = 0;
	cin >> N;

	vector<subject> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].day >> v[i].point;
		lastDay = max(lastDay, v[i].day);
	}

	sort(v.begin(), v.end(), cmp);

	for (int curDay = lastDay; curDay >= 1; curDay--)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (!visited[i] && v[i].day >= curDay)
			{
				ret += v[i].point;
				visited[i] = true;
				break;
			}
		}
	}

	cout << ret << "\n";
	return 0;
}
