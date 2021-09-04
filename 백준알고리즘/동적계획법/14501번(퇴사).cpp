#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 15;
int n;
pii arr[MAX + 1];
int cache[MAX + 1];

int search(int day)
{
    //기저사례: 날짜를 초과할 경우에는 탐색 방법이 잘못된 경우
    if(day > n + 1)
        return INT_MIN;

    int &ret = cache[day];

    if(ret != -1)
        return ret;

    ret = 0;
    //상담을 선택한 날과 선택하지 않은날의 경우 비교
    ret += max(arr[day].second + search(day + arr[day].first), search(day + 1));
    return ret;
}

int main(void)
{
    fastio;
    cin >> n;
    for(int i = 1 ; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    //DP를 활용을 위한 메모리제이션 설정, 갱신된 값을 기억하고 있으면 그 값을 가져와서 사용하기 위한 초기화
    memset(cache, -1, sizeof cache);

    cout << search(1) <<"\n";
}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//int Testcase;
//
//int cache[16];
//pair<int, int> arr[16];
//
//int solve(int day)
//{
//	if (day == Testcase + 1)
//		return 0;
//
//	if (day > Testcase + 1)
//		return INT_MIN;
//
//	int &ret = cache[day];
//
//	if (ret != -1)
//		return ret;
//
//	ret = 0;
//	ret += max(arr[day].second + solve(day + arr[day].first), solve(day + 1));
//
//	return ret;
//}
//
//int main()
//{
//	cin >> Testcase;
//
//	for (int i = 1; i <= Testcase; i++)
//		cin >> arr[i].first >> arr[i].second;
//	//memset(cache, -1, sizeof(cache));
//	fill(cache, cache + 16, -1);
//
//	cout << solve(1) << "\n";
//
//}
