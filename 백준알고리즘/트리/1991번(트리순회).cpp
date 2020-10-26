#include<iostream>

using namespace std;

char Tree[26][2] = { '.', };

void preorder(char root)
{
	if (root == '.')
		return;
	else
	{
		cout << root;
		preorder(Tree[root - 'A'][0]);
		preorder(Tree[root - 'A'][1]);
	}
}

void inorder(char root)
{
	if (root == '.')
		return;
	else
	{
		inorder(Tree[root - 'A'][0]);
		cout << root;
		inorder(Tree[root - 'A'][1]);
	}
}

void postorder(char root)
{
	if (root == '.')
		return;
	else
	{
		postorder(Tree[root - 'A'][0]);
		postorder(Tree[root - 'A'][1]);
		cout << root;
	}
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	char root;
	char left;
	char right;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> root >> left >> right;
		Tree[root - 'A'][0] = left;
		Tree[root - 'A'][1] = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}
