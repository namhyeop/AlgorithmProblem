#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size());
	
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int cur = prices[i];
		int cnt = 1;
		for (int j = i + 1; j < prices.size()-1; j++)
		{
			if (cur > prices[j])
				break;
			cnt++;
		}
		answer[i] = cnt;
	}
	return answer;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v = { 1, 2, 3, 2, 3 };

	vector<int > ret = solution(v);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
