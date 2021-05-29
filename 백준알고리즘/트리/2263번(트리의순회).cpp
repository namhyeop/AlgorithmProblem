#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 1;
int n;
int inorder[MAX];
int postorder[MAX];
int idx[MAX];

void preorder(int inbegin, int inend, int postbegin, int postend)
{
	if (inbegin > inend || postbegin > postend)
		return;
	int root = postorder[postend];
	cout << root << " ";
	//cout << "first" << "\n";
	//cout << inbegin << " " << idx[root] - 1 << " " << postbegin << " " << postbegin + (idx[root] - inbegin) - 1 << "\n";
	preorder(inbegin, idx[root] - 1, postbegin, postbegin + (idx[root] - inbegin) - 1);
	//cout << "second" << "\n";
	//cout << idx[root] + 1 << " " << inend << " " << postbegin + (idx[root] - inbegin) << " " << postend - 1 << "\n";
	preorder(idx[root] + 1, inend, postbegin + (idx[root] - inbegin), postend - 1);
}

int main(void)
{
	fastio;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> inorder[i];

	for (int j = 0; j < n; j++)
		cin >> postorder[j];

	for (int i = 0; i < n; i++)
		idx[inorder[i]] = i;

	preorder(0, n- 1, 0, n - 1);
	cout << "\n";
	return 0;
}
