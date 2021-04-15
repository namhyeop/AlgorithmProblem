#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}
int solution(vector<vector<int>> r) 
{
	int answer = 1;
	sort(r.begin(), r.end(), cmp);
	
	int criteriValue = r[0][1];
	for (int i = 0; i < r.size(); i++)
	{
		if (criteriValue < r[i][0])
		{
			answer++;
			criteriValue = r[i][1];
		}
		if (criteriValue >= r[i][1])
			criteriValue = r[i][1];
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<vector<int>> r = { { -20, 15 }, { -14, -5 }, { -18, -13 }, { -5, -3 } };
	
	cout << solution(r);
}
