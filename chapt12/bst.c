/*
 *  Chapter 12 Binary Search Tree
 *
 * */

#include <stdio.h>

// 数据结构的定义

typedef struct _TreeNode {
	int key;
	struct _TreeNode *left;
	struct _TreeNode *right;
	struct _TreeNode *p;
} TreeNode;

typedef struct _Tree {
	TreeNode * root;
} Tree;
//

void inorder_tree_walk(TreeNode *r)
{
	if(r==NULL) return;
	inorder_tree_walk(r->left);
	printf("%d ",r->key);
	inorder_tree_walk(r->right);
}

/*搜索BST的递归实现*/
TreeNode * tree_search(TreeNode *r,int k)
{
	if(r==NULL || r->key==k) return r;

	if(r->key>k)
		return tree_search(r->right,k);
	else
		return tree_search(r->left,k);
}

/*搜索BST的迭代实现*/
TreeNode * i_tree_search(TreeNode *r,int k)
{
	TreeNode *n;
	n=r;
	while(n) {
		if(n->key==k)
			return n;
		if(n->key<k)
			n=n->left;
		else
			n=n->right;
	}
	return NULL;
}

TreeNode * tree_min(TreeNode *r)
{
	while(r && r->left)
		r=r->left;
	return r;
}

TreeNode * tree_max(TreeNode *r)
{
	while(r && r->right)
		r=r->right;
	return r;
}

TreeNode * tree_successor(TreeNode *x)
{
	TreeNode * node;
	if(x->right)
		return tree_min(x->right);
	//THE LOWEST ANCESTOR OF x WHOSE LEFT CHILD IS ALSO AN ANCESTOR OF x
	node=x->p;
	while(node && x==node->right) {
		x=node;
		node=node->p;
	}
	return node;
}

TreeNode * tree_predecessor(TreeNode *x)
{
	TreeNode * node;
	if(x->left)
		return tree_max(x->left);

	node=x->p;
	while(node && x==node->left) {
		x=node;
		node=node->p;
	}
	return node;
}

/*二叉搜索树的插入
  r 为非空二叉搜索树的根节点
  z 为要插入的节点的指针
 */
void tree_insert(Tree* tree,TreeNode * z)
{
	TreeNode * node;
	TreeNode * r;
	r=tree->root;
	if(r==NULL) {
		tree->root=z;
		return;
	}
	while(r) {
		node=r;
		if(r->key>=z->key)
			r=r->left;
		else
			r=r->right;
	}
	if(node->key>=z->key)
		node->left=z;
	else
		node->right=z;
	z->p=node;
}


/*二叉搜索树的删除
  r 为非空二叉搜索树的根节点
  z 为要删除的节点的指针
 */
TreeNode * tree_deletion(Tree* tree,TreeNode * z)
{
	TreeNode *node,*x;
	node=z;
	if(z->left && z->right)
		node=tree_successor(z);

	if(node->left) //只可能是z只有左子树的情况
		x=node->left;
	else
		x=node->right;

	//node已经指向了要删除的结点
	if(x)
		x->p=node->p;

	//如果要删除的节点是根节点
	if(node->p==NULL) {
		tree->root=x;
	}

	if(node==(node->p)->left) {
		(node->p)->left=x;
	}
	else {
		(node->p)->right=x;
	}
	if(node!=z) {
		z->key=node->key;
		//satellite data
	}
	return node;
}

//===================================
void print_tree(TreeNode * r,int l)
{
	int i;
	if(r==NULL)
		return;


	print_tree(r->right,l+1);
	for(i=0;i<l;i++)
			printf("-");
	printf("%d\n",r->key);
	print_tree(r->left,l+1);


}
//===================================

int main()
{
	int i;
	Tree t;
	TreeNode * node;
	int array[]={30,6,3,7,2,8,32,89,4,7,24,67,3,6,32,6,54,7,32};
	t.root=NULL;
	for(i=0;i<sizeof(array)/sizeof(int);i++) {
		node=(TreeNode*)malloc(sizeof(TreeNode));
		node->left=node->right=node->p=NULL;
		node->key=array[i];
		tree_insert(&t,node);
	}
	print_tree(t.root,0);

	return 0;
}

