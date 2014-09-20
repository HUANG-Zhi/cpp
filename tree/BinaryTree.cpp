# include <iostream>
# include <cstdlib>
using namespace std;
template <class T>
class TreeNode
{
	template <class> friend class BinaryTree;
	template <class> friend class BinarySearchTree;
private:
	T element;
	int count;
	TreeNode<T>* left = NULL;
	TreeNode<T>* right = NULL;
public:	
	TreeNode(T e):count(1){element = e;};
	void display(){
		cout << element << "(" << count << ")" << " " ;
	}
	int compare(TreeNode * node);
};

template <class T>
int TreeNode<T>::compare(TreeNode * node){
	if(node == NULL){
		cerr << "should not compare with a NULL TreeNode" << endl;
		exit(-1);
	}

	if(element < node->element) return -1;
	else if(element > node->element) return 1;
	else return 0;
}

template <class T>
class BinaryTree
{
private:
	void inOrderDisplay(TreeNode<T>* node);
protected:
	TreeNode<T>* root = NULL;
public:
	void deleteTree(TreeNode<T>* root);
	void inOrderDisplay();
	~BinaryTree();
};

template <class T>
void BinaryTree<T>::deleteTree(TreeNode<T>* root){
	if(NULL == root) return;
	else{
		deleteTree(root->left);
		deleteTree(root->right);
	}
}

template <class T>
void BinaryTree<T>::inOrderDisplay(TreeNode<T>* node){
	if(NULL == node) return;
	else {
		inOrderDisplay(node->left);
		node->display();
		inOrderDisplay(node->right);
	}
}
template <class T>
void BinaryTree<T>::inOrderDisplay(){
	inOrderDisplay(root);
}
template <class T>
BinaryTree<T>::~BinaryTree(){
	cout <<endl << "call ~BinaryTree .." << endl;
	delete(root);
}

template <class T>
class BinarySearchTree: public BinaryTree<T>
{
private:
	TreeNode<T>* insertNode(TreeNode<T>* current,TreeNode<T> * treeNode);
public:
	void insert(TreeNode<T> * treeNode);
};

template <class T>
TreeNode<T> * BinarySearchTree<T>::insertNode(TreeNode<T>* current, TreeNode<T> * treeNode){
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
template <class T>
void BinarySearchTree<T>::insert(TreeNode<T> * treeNode){
	if(NULL == treeNode) return;
	else this->root = insertNode(this->root,treeNode);
}

int main(int argc, char const *argv[])
{
	BinarySearchTree<int> bst;
	bst.insert(new TreeNode<int>(10));
	bst.insert(new TreeNode<int>(1));
	bst.insert(new TreeNode<int>(-1));
	bst.insert(new TreeNode<int>(1));
	bst.insert(new TreeNode<int>(6));
	bst.inOrderDisplay();
	return 0;
}