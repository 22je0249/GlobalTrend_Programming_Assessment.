#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;
	Node(int val)
		: val(val)
		, left(NULL)
		, right(NULL)
	{
	}
};

int find(Node* root)
{
	int max_sum = INT_MIN;
	stack<pair<Node*, int> > s;
	s.push(make_pair(root, 0));

	while (!s.empty()) {
		Node* node = s.top().first;
		int state = s.top().second;
		s.pop();

		if (node == NULL) {
			continue;
		}

		if (state == 0) {
	
			s.push(make_pair(node, 1));
			s.push(make_pair(node->left, 0));
		}
		else if (state == 1) {
	
			s.push(make_pair(node, 2));
			s.push(make_pair(node->right, 0));
		}
		else {
	
			int left_sum = (node->left != NULL)
							? node->left->val
							: 0;
			int right_sum = (node->right != NULL)
								? node->right->val
								: 0;
			max_sum
				= max(max_sum, node->val + max(0, left_sum)
								+ max(0, right_sum));
			int max_child_sum = max(left_sum, right_sum);
			node->val += max(0, max_child_sum);
		}
	}

	return max_sum;
}
// Driver Code
int main()
{
	// Constructing the random tree
	Node* root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(-25);
	root->left->left = new Node(20);
	root->left->right = new Node(1);
	root->right->left = new Node(3);
	root->right->right = new Node(4);

	int max_sum = find(root);
	cout << "Maximum Path Sum: " << max_sum << endl;

	return 0;
}


