#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	ll targetValue = brown + yellow;

	for (int i = 3; i <= LLONG_MAX; i++)
	{
		bool flag = false;
		for (int j = 3; j <= i; j++)
		{
			if (i * j == targetValue)
			{
				if ((targetValue - (((i+j) * 2) - 4)) == yellow)
				{
					answer.push_back(i);
					answer.push_back(j);
					flag = true;
					break;
				}
			}
		}
		if (flag == true)
			break;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> ret = solution(18, 6);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
