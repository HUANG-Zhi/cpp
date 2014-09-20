# include <iostream>
# include <cstdlib>
using namespace std;
class TreeNode
{
	friend class BinaryTree;
	friend class BinarySearchTree;
private:
	int element;
	int count;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
public:	
	TreeNode(int e):count(1){element = e;};
	void display(){
		cout << element << "(" << count << ")" << " " ;
	}
	int compare(TreeNode * node);
};

class BinaryTree
{
private:
	void inOrderDisplay(TreeNode* node);
protected:
	TreeNode* root = NULL;
public:
	void deleteTree(TreeNode* root);
	void inOrderDisplay();
	~BinaryTree();
};

class BinarySearchTree: public BinaryTree
{
private:
	TreeNode* insertNode(TreeNode* current,TreeNode * treeNode);
public:
	void insert(TreeNode * treeNode);
};