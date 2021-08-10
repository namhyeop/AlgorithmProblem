#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

struct info{
    ll type;
    ll a;
    ll h;

    info(ll type, ll a, ll h) : type(type), a(a), h(h){}
};

const int MAX = 123456 + 1;
vector<info> arr;
int n, h;

bool check(ll mid, ll atackP)
{
    ll hp = mid;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].type == 1)
        {
            ll cnt = arr[i].h / atackP;
            ll mod = arr[i].h % atackP;
            if (mod > 0)
                cnt++;

            //-1을 해주는 이유는 문제에서 주어지는 전투진행 순서를 자세히 봐야한다
            //용사가 먼저 공격하므로 몬스터가 죽으면 자신이 깍이는 피가 1번 없기 때문이다.
            ll monAtack = (cnt -1) * arr[i].a ;
            hp -= monAtack;
            if (hp <= 0)
                return false;
        }
        else if (arr[i].type == 2)
        {
            atackP += arr[i].a;
            hp = min(hp + arr[i].h, mid);
        }
    }
    return true;
}

int main(void)
{
    fastio;
    cin >> n >> h;

    for (int i = 0; i < n; i++)
    {
        int type, a, h;
        cin >> type >> a >> h;
        arr.push_back({ type, a, h });
    }

    ll left = 1;
    ll right = LLONG_MAX;
    ll ans;
    while (left + 1 < right)
    {
        ll atackP = h;
        ll mid = (left + right) / 2;

        if (!check(mid, atackP))
        {
            left = mid;
        }
        else
            right = mid ;
    }

    cout << right << "\n";
}
