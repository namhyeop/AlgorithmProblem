#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 1;
int n, m;
ll arr[MAX];

int main(void)
{
    fastio;
    cin >> n >> m;

    ll maxValue = 0;
    ll lowValue = 0;
    for(int i =0; i < n; i++)
    {
        cin >> arr[i];
        lowValue = max(lowValue, arr[i]);
        maxValue += arr[i];
    }

    ll left = lowValue;
    ll right = maxValue;
    ll ans;
    while(left <= right)
    {
        ll mid = (left + right) / 2;

        ll cnt = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + arr[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += arr[i];
        }

        if(cnt <= m)
        {
            right = mid - 1;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    cout << ans <<"\n";
}
