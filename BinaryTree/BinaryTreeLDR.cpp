#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class node
{
public:
	int value;
	shared_ptr<node> leftchild;
	shared_ptr<node> rightchild;
};

shared_ptr<node> build_tree(
	vector<int>::iterator preorder_start, vector<int>::iterator preorder_end,
	vector<int>::iterator inorder_start, vector<int>::iterator inorder_end);

void afterprint(shared_ptr<node> root)
{
	if (root == nullptr){
		return;
	}
	afterprint(root->leftchild);
	afterprint(root->rightchild);
	cout << root->value << ' ';
}


int main()
{
	vector<int> first_tree = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> middle_tree = {4, 7, 2, 1, 5, 3, 8, 6};
	shared_ptr<node> root;
	root = build_tree(first_tree.begin(),first_tree.end(),middle_tree.begin(),middle_tree.end());
	afterprint(root);
	cout << endl;
	return 0;
}

shared_ptr<node> build_tree(
	vector<int>::iterator preorder_start, vector<int>::iterator preorder_end,
	vector<int>::iterator inorder_start, vector<int>::iterator inorder_end)
{
	if (preorder_start == preorder_end)
	{
		return nullptr;
	}
	shared_ptr<node> rootnode(new node);
	rootnode->value = *preorder_start;
	vector<int>::iterator search = inorder_start;
	while ((*preorder_start! =* search) && (search != inorder_end))
	{
		search++;
	}
	if (search != inorder_end)
	{
		vector<int>::difference_type length = search - inorder_start;
		rootnode->leftchild=build_tree(preorder_start + 1, preorder_start + 1 + length, inorder_start, search);
		rootnode->rightchild=build_tree(preorder_start + 1 + length,preorder_end, search+1, inorder_end);
		return rootnode;
	}
	return nullptr;
}
