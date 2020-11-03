#include<iostream>
#include<vector>

using namespace std;

int cutNode;

void cutting_leaf(int now_node)
{
	if (del_node == now_node)
		return;
	int ch_size = child 
}

int main(int argc, char *argv[])
{
	int inputN;
	int root;
	cin >> inputN;

	vector<vector<int>> Tree(inputN);

	for (int child = 0; child < inputN; child++)
	{
		int parent;
		cin >> parent;
		if (parent != -1)
			Tree[parent].push_back(child);
		else
			root = child;
	}

	cin >> cutNode;

	cutting_leaf(root);
}
