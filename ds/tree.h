/*
 *
 */

#ifndef __INTRO_2_TREE__
#define __INTRO_2_TREE__

typedef struct _TreeNode {
	int key;
	int color;
	struct _TreeNode *left;
	struct _TreeNode *right;
	struct _TreeNode *p;
} TreeNode;

typedef struct _Tree {
	TreeNode * root;
	TreeNode * nill;
} Tree;


#endif

