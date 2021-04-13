#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;

	ll sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	//priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	while (pq.top() <= K && pq.size() > 1)
	{
		ll num1 = pq.top();
		pq.pop();
		ll num2 = pq.top();
		pq.pop();

		if (num1 == 0 && num2 == 0)
		{
			answer = -1;
			break;
		}
		sum = num1 + (num2*2);
		pq.push(sum);
		answer++;
	}

	if (pq.top() < K)
		answer = -1;

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> s = { 1, 2, 3, 9, 10, 12 };
	int k = 7;
	cout << solution(s, k);
}
