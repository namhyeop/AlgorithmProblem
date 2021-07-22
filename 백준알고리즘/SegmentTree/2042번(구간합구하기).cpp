#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
int n, m, k;

//변수 소개
//arr : 입력값이 들어가 있는 변수, tree : 구성할 세그먼트 트리, node : 현재 노드, start : 더하는 시작 부분, end : 더하는 끝 부분
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
	if (start == end) //맨 리프노드까지 내려가면 tree에 값을 넣어준다.
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

//index : 바꾸려는 index, diff : 세그먼트 트리는 리프노드를 제외하고 구간합의 값을 가지고 있는데 빼주려는 값이 있다면 그 와 관련된 구간합도 다 빼줘야 한다. , diff는 빼야하는 구간 값을 가지고 있음
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
	if (!(start <= index && index <= end)) //start ~ end 사이의 값이 아니면 분기 정지
		return;

	tree[node] += diff; //각각의 구간합마다 diff를 더해주는 연산
	if (start != end) //리프노드가 아니라면 분기한다.
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

ll sumQuery(vector<ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) //범위가 초과한경우 자식에게 query를 보내 자식 구간에서 값을 찾게 탐색 함
		return 0;

	if (left <= start && end <= right)//구간에 포함할 경우 값을 반환해줌
		return tree[node];

	int mid = (start + end) / 2;
	return sumQuery(tree, node * 2, start, mid, left, right) + sumQuery(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	fastio;
	cin >> n >> m >> k;

	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	vector<ll> arr(n);
	vector <ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	int t = m + k;
	while (t--)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			int pos;
			ll val;
			cin >> pos >> val;
			ll diff = val - arr[pos - 1];
			arr[pos - 1] = val;
			update(tree, 1, 0, n - 1, pos - 1, diff); //구간합에 diff값을 더해준다.
		}
		else if (cmd == 2)
		{
			int left, right;
			cin >> left >> right;
			ll sum = sumQuery(tree, 1, 0, n - 1, left - 1, right - 1);
			cout << sum << "\n";
		}
	}
	return 0;
}#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
int n, m, k;

//변수 소개
//arr : 입력값이 들어가 있는 변수, tree : 구성할 세그먼트 트리, node : 현재 노드, start : 더하는 시작 부분, end : 더하는 끝 부분
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) 
{
	if (start == end) //맨 리프노드까지 내려가면 tree에 값을 넣어준다.
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

//index : 바꾸려는 index, diff : 세그먼트 트리는 리프노드를 제외하고 구간합의 값을 가지고 있는데 빼주려는 값이 있다면 그 와 관련된 구간합도 다 빼줘야 한다. , diff는 빼야하는 구간 값을 가지고 있음
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
	if (!(start <= index && index <= end)) //start ~ end 사이의 값이 아니면 분기 정지
		return;

	tree[node] += diff; //각각의 구간합마다 diff를 더해주는 연산
	if (start != end) //리프노드가 아니라면 분기한다.
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

ll sumQuery(vector<ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start) //범위가 초과한경우 자식에게 query를 보내 자식 구간에서 값을 찾게 탐색 함
		return 0;

	if (left <= start && end <= right)//구간에 포함할 경우 값을 반환해줌
		return tree[node];

	int mid = (start + end) / 2;
	return sumQuery(tree, node * 2, start, mid, left, right) + sumQuery(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	fastio;
	cin >> n >> m >> k;

	int h = (int)ceil(log2(n));
	int tree_size = 1 << (h + 1);
	vector<ll> arr(n);
	vector <ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	int t = m + k;
	while (t--)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			int pos;
			ll val;
			cin >> pos >> val;
			ll diff = val - arr[pos - 1];
			arr[pos - 1] = val;
			update(tree, 1, 0, n - 1, pos - 1, diff); //구간합에 diff값을 더해준다.
		}
		else if(cmd == 2)
		{
			int left, right;
			cin >> left >> right;
			ll sum = sumQuery(tree, 1, 0, n - 1, left - 1, right - 1);
			cout << sum << "\n";
		}
	}
	return 0;
}
