#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct node 
{
	int info;
	int height;
	int equal;
	//	int ocurrence;
	node* left;
	node* right;
};
//====================================================================================================================================================================
node* makeNode(int info) 
{
	node* childnode;
	childnode = new node;
	childnode->info = info;
	childnode->height = 0;
	childnode->equal = 0;
	childnode->left = NULL;
	childnode->right = NULL;
	return childnode;
}
//====================================================================================================================================================================
int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}
//====================================================================================================================================================================
int height(node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
//====================================================================================================================================================================
node *rightRotate(node *y)
{
	node *x = y->left;
	node *T2 = x->right;

	
	x->right = y;
	y->left = T2;
 
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;


	return x;
}
//====================================================================================================================================================================
node *leftRotate(node *x)
{
	node *y = x->right;
	node *T2 = y->left;

	
	y->left = x;
	x->right = T2;

	 
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	
	return y;
}
//====================================================================================================================================================================
void SinglerotateLeft(node * &T)
{
	node * p = T->right;
	node * q = p->left;
	p->left = T;
	T->right = q;
	T->height -= 2;
	T = p;
}
//====================================================================================================================================================================
void SinglerotateRight(node * &T)
{
	node * p = T->left;
	node * q = p->right;
	p->right = T;
	T->left = q;
	T->height -= 2;
	T = p;
}
//====================================================================================================================================================================
void DoublerotateRifgtLeft(node * &T)
{
	SinglerotateRight(T->right);
	T->right->height += 1;
	T->right->right->height += 1;
	SinglerotateLeft(T);
}
//====================================================================================================================================================================
void DoublerotateLeftRight(node * &T)
{
	SinglerotateLeft(T->left);
	T->left->height += 1;
	T->left->left->height += 1;
	SinglerotateRight(T);
}
//====================================================================================================================================================================
void BST(node * &Tree, int c)
{
	node * T;
	T = makeNode(c);
	if (!Tree) Tree = T;
	else
	{
		if (c < Tree->info)
		{
			BST(Tree->left, c);
			Tree->height = max(Tree->left->height + 1, Tree->height);
			if (Tree->right
				&&
				Tree->left->height - Tree->right->height == 2
				||
				!Tree->right &&Tree->height == 2)

				if (c < Tree->left->info)
					SinglerotateRight(Tree);
				else
					DoublerotateLeftRight(Tree);
		}
		else if (c > Tree->info)
		{
			BST(Tree->right, c);
			Tree->height = max(Tree->right->height + 1, Tree->height);
			if (Tree->left&&Tree->right->height - Tree->left->height == 2 || !Tree->left &&Tree->height == 2)
			{
				if (Tree->right->info < c)SinglerotateLeft(Tree);

				else DoublerotateRifgtLeft(Tree);
			}
		}
		// else Tree->ocurrence +=1;

	}
}
//====================================================================================================================================================================
void inorder(node * Tree)
{
	if (!Tree) return;
	else
	{
		inorder(Tree->left); 
		cout << Tree->info << "  " << endl;
		inorder(Tree->right);
	}

}
//====================================================================================================================================================================
int w = 0; int A[20]; int p = 0, j = 0, S[20];
void print_tree(node *head)
{
	int e[20];

	std::queue<node*>q;
	q.push(head);
	q.push(NULL); int  K = 0, i = 0, A, k = -1, f = 0, m = 0, W = 0, L, r = 0;
	while (true)
	{

		node*cu = q.front();

		if (cu) { e[i] = cu->info; i++; }
		q.pop();

		if (cu != NULL)
		{
			m++;
			if (m > 2) {
				A = e[k + 1]; k++;
			}
			if (f == 0)
				cout << cu->info;
			else if (cu->info < A)
				cout << cu->info;

			else if (L == 1 && r == 0 && cu->info > e[0])cout << "             " << cu->info << "     ";
			else if (cu->info > A&&cu->info < e[0]) {
				cout << "   " << cu->info << "  ";
			}
			else if (L == 0 && r == 1 && cu->info > e[0])cout << "                     " << cu->info << "     ";


			else {
			cout << "        ";
			cout << cu->info;
			}L = r = 0;
			if (cu->left != NULL) {
				q.push(cu->left); L = 1;
			}
			if (cu->right != NULL) {
				q.push(cu->right); r = 1;
			}

		}
		else {
			if (q.empty())break;
			q.push(NULL);
			cout <<endl; cout <<endl;
			cout << endl;
			A = e[k + 1]; k++;
			for (size_t i = 12; i > K; i--)
			{
				cout << " ";
			}K++; m = 0;
		}
		f++;
	}
}
/*void printTree(node* T)
{
	queue<node*> q;
	node* p;
	if (T)
	{
		q.push(T);
		int i = 16, j = 0, previos = -1;
		while (!q.empty())
		{
			p = q.front(); q.pop();
			if (previos != p->height)
			{
				cout << endl; j = 0;
				previos = p->height;
			}
			cout << p->info << "  ";
			if (p->left) q.push(p->left);
			if (p->right) q.push(p->right);
		}
	}
	else cout << "Tree empty ";
}*/
//====================================================================================================================================================================
void Search(node* root, int data) {
	if (root == NULL) {
		cout << data <<" not found in tree" <<endl;
	}
	else if (root->info == data) {
		cout << data << " found in tree" << endl;
	}
	else if (data <= root->info) {
		 Search(root->left, data);
	}
	else {
		Search(root->right, data);
	}
}
//====================================================================================================================================================================
void Delete(node* & Tree, int c)
{
	node* p, *q, *r;
	if (!Tree) cout << "The value " << c << " Is not on the tree" << endl;
	else if (Tree->info > c) Delete(Tree->left, c);
	else if (Tree->info < c) Delete(Tree->right, c);
	else if (Tree->info == c)
	{
		if (!Tree->left && !Tree->right)
			Tree = NULL; 
		else if (!Tree->left)
			Tree = Tree->right; //Tree has only left child
		else if (!Tree->right) //Tree has only right child
			Tree = Tree->left;
		else //Tree has two children 
		{
			r = Tree; p = Tree->left; q = p->right;
			while (q) // find the right most child in the left subtree to replace and fix the tree :D
			{
				r = p;	p = q; q = q->right;
			}
			Tree->info = p->info;
			if (r != Tree) r->right = p->left;
			else r->left = p->left;
		}
		cout << "The Value " << c << " has been deleted from tree" << endl;
	}
}
//====================================================================================================================================================================
int main()
{
	node * Tree = NULL;
	int choice;
	int a;
	int b;
	cout << "===============================================" << endl;
	cout << "1-Insert a number" << endl;
	cout << "2-Delete a number" << endl;
	cout << "3-Print The Tree" << endl;
	cout << "4-Exit the program" << endl;
	cout << "===============================================" << endl;
	cin >> choice;
	while (choice != 4) 
	{
		switch (choice)
		{
		case 1:
			cout << "Enter a number "; cin >> a; BST(Tree, a);
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;

		case 2: 
			cout << "Enter a number "; cin >> b; Delete(Tree, b);
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;

		case 3: 
			cout << "               ";
			print_tree(Tree);
			cout << endl;
			cout << "===============================================" << endl;
			cout << "1-Insert a number" << endl;
			cout << "2-Delete a number" << endl;
			cout << "3-Print The Tree" << endl;
			cout << "4-Exit the program" << endl;
			cout << "===============================================" << endl;
			break;
		}
		cout << endl;
		cin >> choice;
	}
}




