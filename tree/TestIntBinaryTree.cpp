# include "IntBinaryTree.h"
int main(int argc, char const *argv[])
{
	BinarySearchTree bst;
	bst.insert(new TreeNode(10));
	bst.insert(new TreeNode(1));
	bst.insert(new TreeNode(-1));
	bst.insert(new TreeNode(1));
	bst.insert(new TreeNode(6));
	bst.inOrderDisplay();
	return 0;
}