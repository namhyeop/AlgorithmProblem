#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());

	int left = 0;
	int right = citations[citations.size() - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int overCnt = 0, lessCnt = 0;

		for (int i = 0; i < citations.size(); i++)
		{
			if (mid <= citations[i])
				overCnt++;
			if (mid > citations[i])
				lessCnt++;
		}

		if (overCnt >= mid  && lessCnt <= mid)
		{
			answer = max(answer, mid);
		}

		if (overCnt < mid)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v = { 12, 11, 10, 9, 8, 1 };
	int ret = solution(v);

	cout << ret << "\n";
}
