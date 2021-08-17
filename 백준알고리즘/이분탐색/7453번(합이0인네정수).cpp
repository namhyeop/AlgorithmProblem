#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 4000;
int n;
vector<ll> a, b, c, d;
vector<ll> v;
int main(void)
{
    fastio;
    cin >> n;

    a.resize(n), b.resize(n), c.resize(n), d.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(int i =0; i < n; i++)
        for(int j = 0; j < n; j++)
            v.push_back(c[i] + d[j]);

        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                auto cur = a[i] + b[j];
                auto [low, high] = equal_range(v.begin(), v.end(), -cur);
                ans += high - low;
            }
        }
        cout << ans << "\n";
}