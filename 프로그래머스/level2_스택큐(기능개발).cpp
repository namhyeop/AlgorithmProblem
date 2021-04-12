#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> q;

	for (int i = 0; i < progresses.size(); i++)
	{
		int cur = 0;
		if (((100 - progresses[i]) % speeds[i]) != 0)
			cur = ((100 - progresses[i]) / speeds[i]) + 1;
		else
			cur = ((100 - progresses[i]) / speeds[i]);
		
		if (!q.empty() && q.top() < cur)
		{
			int cnt = 0;
			while (!q.empty())
			{
				q.pop();
				cnt++;
			}
			answer.push_back(cnt);
		}
		q.push(cur);
	}

	int cnt = 0;
	if (!q.empty())
	{
		while (!q.empty())
		{
			q.pop();
			cnt++;
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = { 93, 30, 55 };
	vector<int> v2 = { 1, 30, 5 };
	vector<int> ret = solution(v, v2);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";	
}
