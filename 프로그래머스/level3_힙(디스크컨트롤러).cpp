#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

struct cmp
{
	bool operator()(vector<int> a, vector<int> b)
	{
		return a[1] > b[1];
	}
};

//class cmp
//{
//public:
//	bool operator()(vector<int> a, vector<int> b)
//	{
//		if (a[1] > b[1])
//			return true;
//		else
//			return false;
//	}
//};

int solution(vector<vector<int>> jobs)
{
	int answer = 0, j = 0, time = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	sort(jobs.begin(), jobs.end());

	while (j < jobs.size() || !pq.empty())
	{
		if (jobs.size() > j && time >= jobs[j][0])
		{
			pq.push(jobs[j++]);
			continue;
		}

		if (!pq.empty())
		{
			time += pq.top()[1];
			answer += time - pq.top()[0];
			pq.pop();
		}
		else
			time = jobs[j][0];
	}
	return answer / jobs.size();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> jobs = { { 0, 3 }, { 1, 9 }, { 2, 6 } };

	cout << solution(jobs);
}
