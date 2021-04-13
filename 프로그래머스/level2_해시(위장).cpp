#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 1;
	map<string, int> m;
	for (auto a : clothes)
		m[a[1]]++;
	
	map<string, int>::iterator  iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		answer *= iter->second + 1;
	}
	answer -= 1;
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
