#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

ll Calculator(ll num)
{
	if (~num & 1) // 짝수이면 참 홀수이면 거짓
		return num + 1;

	int t = 0;
	for (; num & 1LL << t; t++);// nun과의 공통점이 생기지 않는 부분까지 비트를 옮긴다. -> 이진수를 비교했을때 교집합이 안생기는 부분에서 끝난다.
	num ^= 1LL << t | 1LL << t - 1;// 홀수일 경우 1개또는 2개이상 차이나는 경우의 큰수
	return num;

}
vector<ll> solution(vector<ll> numbers)
{
	int n = numbers.size();
	vector<ll> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = Calculator(numbers[i]);
	return ret;
}

int main(void)
{
	fastio;
	vector<ll> v = { 3, 7 };
	
	vector<ll> ret = solution(v);
	for (int i = 0; i < sz(ret); i++)
		cout << ret[i] << " ";
	cout << '\n';
}
