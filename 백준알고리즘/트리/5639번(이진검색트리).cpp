#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *root = NULL;

Node *insert(Node *node, int data)
{
	if (node == NULL)
	{
		node = new Node();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data <= node->data)
	{
		node->left = insert(node->left, data);
	}
	else
		node->right = insert(node->right, data);
	return node;
}

void postOrder(Node *node)
{
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);
	cout << node->data << "\n";
}

int main(void)
{
	fastio;
	int num;
	while (scanf("%d", &num) != EOF)
	{
		if (num == EOF)
			break;
		root = insert(root, num);
	}
	postOrder(root);
	return 0;
}
