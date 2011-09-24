/*
*  红黑树的实现
*/
#include <stdio.h>

#include "../ds/tree.h"

/*中序遍历二叉树的递归实现*/
void inorder_tree_walk(TreeNode *r)
{
	if(r==NULL) return;
	inorder_tree_walk(r->left);
	printf("%d ",r->key);
	inorder_tree_walk(r->right);
}

/*搜索RHT的递归实现*/
TreeNode * tree_search(TreeNode *r,int k)
{
	if(r==NULL || r->key==k) return r;

	if(r->key>k) return tree_search(r->right,k);
	else return tree_search(r->left,k);
}

/*搜索RHT的迭代实现*/
TreeNode * i_tree_search(TreeNode *r,int k)
{
	TreeNode *n;
	n=r;
	while(n) {
		if(n->key==k) return n;
		if(n->key<k) n=n->left;
		else n=n->right;
	}
	return NULL;
}

TreeNode * tree_min(TreeNode *r)
{
	while(r && r->left) r=r->left;
	return r;
}

TreeNode * tree_max(TreeNode *r)
{
	while(r && r->right) r=r->right;
	return r;
}

TreeNode * tree_successor(TreeNode *x)
{
	TreeNode * node;
	if(x->right) return tree_min(x->right);
	// if the right subtree of node x is empty
	// and x has a successor y
	// the y IS THE LOWEST ANCESTOR OF x WHOSE LEFT
	// CHILD IS ALSO AN ANCESTOR OF x
	node=x->p;
	while(node && x==node->right) {x=node;node=node->p;};
	return x;
}

TreeNode * tree_predecessor(TreeNode *x)
{
	TreeNode * node;
	if(x->left) return tree_max(x->left);

	node=x->p;
	while(node && x==node->left) {x=node;node=node->p;};
	return x;
}

/*
 * 红黑树的左旋
 */
void left_rotation(Tree t,TreeNode x)
{

}



int main()
{
	return 0;
}

