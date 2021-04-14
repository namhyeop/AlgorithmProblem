#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

bool visitedLost[31];
bool visitedReserve[31];

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;

	vector<int>::iterator it;
	for (int i = 0; i < reserve.size(); i++)
	{
		it = find(lost.begin(), lost.end(), reserve[i]);
		if (it != lost.end())
		{
			visitedLost[it - lost.begin()] = true;
			visitedReserve[i] = true;
		}
	}
	
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (!visitedLost[i] && !visitedReserve[j])
			{
				if (abs(lost[i] - reserve[j]) == 1)
				{
					visitedLost[i] = true;
					visitedReserve[j] = true;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < lost.size(); i++)
	{
		if (visitedLost[i])
			cnt++;
	}
	answer = n - lost.size() + cnt;
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 12;
	vector<int> lost = { 1,2,3,4,8,9,10,11 };
	vector<int> reserve = {9, 10};
	cout << solution(n, lost, reserve);
}
