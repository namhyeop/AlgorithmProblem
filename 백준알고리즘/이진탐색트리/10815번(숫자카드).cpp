//equal_range 활용 코드
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 5e5 + 1;
int arr1[MAX];
int arr2[MAX];

int n, m;
int main(void)
{
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    cin >> m;
    for(int j = 0; j < m; j++)
        cin >> arr2[j];
    sort(arr1, arr1 + MAX);
    for(int i = 0; i < m; i++)
    {
        auto[lo, hi] = equal_range(arr1, arr1 + MAX, arr2[i]);
        cout << hi - lo << "\n";
    }
}

/*binary_search 활용 코드
#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e7;

int n,m;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		if (binary_search(arr, arr + n, num))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}
*/
