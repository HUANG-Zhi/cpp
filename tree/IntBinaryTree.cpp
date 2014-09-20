# include "IntBinaryTree.h"
int TreeNode::compare(TreeNode * node){
	if(node == NULL){
		cerr << "should not compare with a NULL TreeNode" << endl;
		exit(-1);
	}

	if(element < node->element) return -1;
	else if(element > node->element) return 1;
	else return 0;
}


void BinaryTree::deleteTree(TreeNode* root){
	if(NULL == root) return;
	else{
		deleteTree(root->left);
		deleteTree(root->right);
	}
}

void BinaryTree::inOrderDisplay(TreeNode* node){
	if(NULL == node) return;
	else {
		inOrderDisplay(node->left);
		node->display();
		inOrderDisplay(node->right);
	}
}
void BinaryTree::inOrderDisplay(){
	inOrderDisplay(root);
}
BinaryTree::~BinaryTree(){
	cout <<endl << "call ~BinaryTree .." << endl;
	delete(root);
}

TreeNode * BinarySearchTree::insertNode(TreeNode* current, TreeNode * treeNode){
	if(NULL == current) return treeNode;
	int cmp = current->compare(treeNode);
	if(cmp == 0){
		current -> count += treeNode->count;
	}else if (cmp > 0){
		current->left = insertNode(current->left,treeNode);
	}else{
		current->right = insertNode(current->right,treeNode);
	}

	return current;
}
void BinarySearchTree::insert(TreeNode * treeNode){
	if(NULL == treeNode) return;
	else this->root = insertNode(this->root,treeNode);
}