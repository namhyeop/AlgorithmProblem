#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int n;
int arr[MAX];
int cache_u[MAX];
int cache_d[MAX];
int cache_m[MAX];

int main(void)
{
	fastio;
	cin >> n;
	cache_u[0] = 0;
	cache_d[n + 1] = 0;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++)
	{
		/*cout << "i는 " << i <<"일 때" << "\n";*/
		cache_u[i] = 1;
		cache_d[n - i + 1] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && cache_u[j] + 1 > cache_u[i])
				cache_u[i] = cache_u[j] + 1;
			if (arr[n - i + 1] > arr[n - j + 1] && cache_d[n -j + 1] + 1 > cache_d[n - i + 1])
				cache_d[n - i + 1] = cache_d[n - j + 1] + 1;
		}

		//cout << "case_u의 가정 \n";
		//for (int i = 1; i < n + 1; i++)
		//{
		//	cout << cache_u[i] << " ";
		//}
		//cout << "\n";
		//cout << "case_d의 과정\n";
		//for (int j = 1; j < n + 2; j++)
		//	cout << cache_d[j] << " ";
		//cout << "\n";

		//cout << "=========================" << "\n";
		//cout << "\n";
	}

	
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		cache_m[i] = cache_u[i] + cache_d[i];
		ret = max(ret, cache_m[i]);
	}
	cout << ret - 1 << "\n";
}
