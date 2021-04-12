#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq;
	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ i, priorities[i] });
		pq.push(priorities[i]);
	}
	while (!pq.empty())
	{
		int cur = q.front().first;
		int grade = q.front().second;
		q.pop();
		
		if (grade == pq.top())
		{
			pq.pop();
			answer += 1;

			if (cur == location)
				break;
		}
		else
			q.push({ cur, grade });
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> p = { 1,1,9,1,1,1 };
	int l = 0;

	cout << solution(p, l) << "\n";
}
