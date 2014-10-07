# include <iostream>
# include <cstdlib>
# include <stack>
# include <deque>
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
	TreeNode<T>* next = NULL;
public:	
	TreeNode(T e):count(1){element = e;};
	void display(){
		//cout << element << "(count: " << count << "; next:"<< (next ==NULL?0:next->element) << ") " ;
		cout << element <<" ";
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
	void nonRecurPreOrder();
	void nonRecurPreOrderV2();
	void nonRecurInOrder();
	void testDoubleLink();
	void doubleLink(TreeNode<T>* node, TreeNode<T>* &firstNode,TreeNode<T>* &lastNode);
	void Next();
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
void BinaryTree<T>::nonRecurPreOrder(){
	stack<TreeNode<T>*> mem;
	if(root == NULL){
		cout<< " empty tree!" << endl;
		return;
	}
	mem.push(root);
	while(!mem.empty()){
		TreeNode<T> * t = mem.top();
		mem.pop();
		t->display();
		if(t->right != NULL) mem.push(t->right);
		if(t->left != NULL) mem.push(t->left);
	}
}

template <class T>
void BinaryTree<T>::nonRecurPreOrderV2(){
	if(root == NULL){
		cout<< " empty tree!" << endl;
		return;
	}
	stack<TreeNode<T>*> mem;
	TreeNode<T>* t = root;
	while(t!=NULL || !mem.empty()){
		while(t!=NULL){
			mem.push(t);
			t->display();
			t = t->left;
		}

		t = mem.top();
		mem.pop();
		t = t->right;
	}
}

template <class T>
void BinaryTree<T>::nonRecurInOrder(){
	if(root == NULL){
		cout<< " empty tree!" << endl;
		return;
	}
	stack<TreeNode<T>*> mem;
	TreeNode<T>* t = root;
	while(t || !mem.empty()){
		while(t){
			mem.push(t);
			t = t->left;
		}

		t = mem.top();
		t->display();
		mem.pop();
		t = t->right;
	}
}

template <class T>
void BinaryTree<T>::Next(){
	if(root == NULL){
		cout<< " empty tree!" << endl;
		return;
	}
	int incount,outcout;
	deque<TreeNode<T>*> mem;
	mem.push_back(root);
	incount = 0;
	outcout = 1;
	TreeNode<T>* current;
	while(!mem.empty()){
		current = mem.front();
		mem.pop_front();
		outcout--;
		if(current->left != NULL){
			mem.push_back(current->left);
			incount++;
		}
		if(current->right != NULL){
			mem.push_back(current->right);
			incount++;
		}
		if(outcout > 0){
			current->next = mem.front();
		}else{
			outcout = incount;
			incount = 0;
		}
	}
	// check();
	inOrderDisplay();
}

template <class T>
void BinaryTree<T>::doubleLink(TreeNode<T>* node, TreeNode<T>* &firstNode,TreeNode<T>* &lastNode){
	if(node == NULL) return;
	doubleLink(node->left,firstNode,lastNode);
	// cout<<"..";
	// node->display();
	if(firstNode == NULL){
		firstNode = node;
	}
	if(lastNode == NULL){
		node->left = lastNode;
		lastNode = node;
	}else{
		node->left = lastNode;
		lastNode->right = node;
		lastNode = node;
	}
	doubleLink(node->right,firstNode,lastNode);
}

template <class T>
void BinaryTree<T>::testDoubleLink(){
	TreeNode<T> * first = NULL;
	TreeNode<T> * last = NULL;
	doubleLink(root,first,last);
	TreeNode<T> * current = first;
	TreeNode<T> * m, *m1;
	m = current;
	m1 = current;
	int count = 0;
	cout<<"\nfrom first to last"<<endl;
	while(current != NULL){
		current->display();
		count++;
		current = current->right;
		if(count % 2 == 0){
			m = m1;
			m1 = m1->right;
		}
	}
	cout <<endl;
	if(count % 2 == 0){
		cout <<"even:";
		m->display();
		m1->display();
	}else{
		cout <<"odd:";
		m1->display();
	}
	cout<<"\nfrom last to first"<<endl;
	
	current = last;
	while(current != NULL){
		current->display();
		current = current->left;
	}
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
	bst.insert(new TreeNode<int>(20));
	bst.insert(new TreeNode<int>(7));
	bst.insert(new TreeNode<int>(11));
	bst.insert(new TreeNode<int>(30));
	bst.insert(new TreeNode<int>(25));
	bst.insert(new TreeNode<int>(18));
	bst.insert(new TreeNode<int>(27));
	//bst.insert(new TreeNode<int>(22));
	cout <<endl<< "inOrderDisplay:";
	bst.inOrderDisplay();
	// cout <<endl<< "nonRecurPreOrder:";
	// bst.nonRecurPreOrder();
	// cout <<endl<< "nonRecurPreOrderV2:";
	// bst.nonRecurPreOrderV2();
	// cout <<endl<< "nonRecurInOrder:";
	// bst.nonRecurInOrder();
	//bst.Next();
	bst.testDoubleLink();
	return 0;
}