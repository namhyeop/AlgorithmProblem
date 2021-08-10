#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
ll n, k, d;

struct info{
    ll start;
    ll end;
    ll width;
};

vector<info> v;

bool check(ll mid)
{
    ll cnt = 0;
    for(int i = 0; i < k; i++)
    {
        //앞에서 부터 도토리를 담으므로 가장 끝에 도토리가 있게 하기 위해서는 mid값을 줄여줘야한다. 그러므로 가능한 최소의 경우를 다믄ㄴ다.
        ll right = min(v[i].end, mid);
        if(right >= v[i].start)
            //너비에서 몇 개의 도토리를 담을 수 있는가
            cnt += ((right - v[i].start) / v[i].width) + 1;
    }
    return cnt >= d;
}

int main(void)
{
    fastio;
    cin >> n >> k >> d;
    v.resize(MAX);
    //규칙 담기
    for(int i = 0; i < k; i++)
        cin >> v[i].start >> v[i].end >> v[i].width;

    ll left = 0;
    ll right = n;
    while(left + 1 < right)
    {
        ll mid = (left + right) / 2;
        //박스가 mid개일 경우 도토리를 d개 이상 담을수 있는가
        if(check(mid))
            right = mid;
        else
            left = mid;
    }
    cout << right << "\n";
}