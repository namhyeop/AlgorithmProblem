#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	ll answer = 0;

	sort(rocks.begin(), rocks.end());

	ll left = 1, right = distance;

	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll prevIdx = 0;
		ll removeRockCnt = 0;

		for (auto rock : rocks)
		{
			if ((rock - prevIdx) < mid)
				removeRockCnt++;
			else
				prevIdx = rock;
		}

		if (distance - prevIdx < mid)
			removeRockCnt++;

		if (removeRockCnt <= n)
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int dist = 25;
	vector<int> rock = { 2, 14, 11, 21, 17 };
	int n = 2;

	cout << solution(25, rock, 2);
}


/*
#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	ll answer = 0;
	ll left = 1;
	ll right = distance;
	ll ret = 0;

	while (left <= right)
	{
		int removeRockCnt = 0;
		int prevIdx = 0;
		ll mid = (left + right) / 2;

		for (int rock : rocks)
		{
			if ((rock - prevIdx) < mid)
				removeRockCnt++;
			else
				prevIdx = rock;
		}

		if (distance - prevIdx < mid)
			removeRockCnt++;

		if (removeRockCnt <= n)
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
*/
