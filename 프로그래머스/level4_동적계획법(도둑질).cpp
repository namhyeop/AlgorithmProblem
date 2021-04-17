#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e6;
int cache1[MAX];
int cache2[MAX];

int solution(vector<int> money)
{
	int answer = 0;

	cache1[0] = money[0];
	cache1[1] = money[0];
	for (int i = 2; i < money.size() - 1; i++)
		cache1[i] = max(cache1[i - 2] + money[i], cache1[i - 1]);
	
	cache2[0] = 0;
	cache2[1] = money[1];
	for (int i = 2; i < money.size(); i++)
		cache2[i] = max(cache2[i - 2] + money[i], cache2[i - 1]);
	
	return max(cache1[money.size() -2], cache2[money.size() - 1]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> mo = { 1, 2, 3, 1 };
	cout << solution(mo);
}
