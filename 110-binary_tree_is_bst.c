#include "binary_trees.h"

/**
* check_right - checks the right subtree in the left branch
* @root: the root of the tree
* @node: the node in the right subtree of the left branch
* Return: 0 or 1
*/
int check_right(const binary_tree_t *root, const binary_tree_t *node)
{
	if (node == NULL || root == NULL)
		return (1);

	if (node->n >= root->n)
		return (0);
	return (check_right(root->parent, node));
}

/**
* check_left - checks the left subtree in the right branch
* @root: the root of the tree
* @node: the node in the left subtree of the right branch
* Return: 0 or 1
*/
int check_left(const binary_tree_t *root, const binary_tree_t *node)
{
	if (node == NULL || root == NULL)
		return (1);

	if (node->n <= root->n)
		return (0);
	return (check_right(root->parent, node));
}
/**
* binary_tree_is_bst - checks if a binary tree is bst
* @tree: the tree to check
* Return: 1 if it's bst, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *left_tree, *right_tree;
	int bst_left = 1, bst_right = 1;

	if (tree == NULL)
		return (0);

	left_tree = tree->left;
	right_tree = tree->right;

	if (left_tree != NULL)
	{
		if (left_tree->n >= tree->n)
			return (0);
		bst_left = binary_tree_is_bst(tree->left);
		bst_left = bst_left & check_right(tree, tree->left->right);
	}
	if (right_tree != NULL)
	{
		if (right_tree->n <= tree->n)
			return (0);
		bst_right = binary_tree_is_bst(tree->right);
		bst_right = bst_right & check_left(tree, tree->right->left);
	}
	return (bst_left && bst_right);
}
