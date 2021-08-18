#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 201;
const int mod = 1e9;
int n, k;
//DP cache 정의: cache[a][b]인 경우
//a개 더한 경우 값은 b이다.
ll cache[MAX][MAX];
int main(void)
{
    fastio;
    cin >> n >> k;

    for(int i = 0; i <= n; i++)
        cache[1][i] = 1;

    for(int i = 2; i <= k; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int l = 0; l <= j; l++)
            {
                //i번째 더한 경우의 값 j를 구하기 위해서는 i - 1개 더한 값의 0부터 j개를 다 더한 값과 같다.
                cache[i][j] += cache[i - 1][l];
            }
            cache[i][j] %= mod;
        }
    }
    cout << cache[k][n] <<"\n";
    return 0;
}