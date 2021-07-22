#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX_CANDY = 1e6;

int k;
int tree_size;
int ret;

ll query(vector<ll> &tree, int node, int start, int end, int k)
{
	if ((start == end) && ret == 0)
	{
		cout << start << "\n";
		return start;
	}

	if (ret == 0 && (node * 2 <= tree_size && tree[node * 2] >= k))
		return ret = query(tree, node * 2, start, (start + end) / 2, k);
	k -= tree[node * 2];
	if (ret == 0 && (node * 2 + 1 <= tree_size && tree[node * 2 + 1] >= k))
		return ret = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, k);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	fastio;

	int n;
	int h = (int)ceil(log2(MAX_CANDY));
	tree_size = (1 << (1 + h));

	vector<ll> tree(tree_size);
	//tree.push_back(0);
	cin >> n;

	while (n--)
	{
		int num;
		cin >> num;

		if (num == 1)
		{
			cin >> k;
			int getIndex = query(tree, 1, 0, MAX_CANDY - 1, k);
			ret = 0;
			update(tree, 1, 0, MAX_CANDY - 1, getIndex, -1);
		}

		else if (num == 2)
		{
			int index;
			ll val;
			cin >> index >> val;
			update(tree, 1, 0, MAX_CANDY - 1, index, val);
		}
	}
	return 0;
}
