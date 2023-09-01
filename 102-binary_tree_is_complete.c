#include "binary_trees.h"

/**
* max - compute the max number
* @num1: the first number
* @num2: the seconde number
* Return: the max num
*/
size_t max(size_t num1, size_t num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
/**
* binary_tree_height - computes the height of the tree (leaves height = 1)
*                       If tree is null, returns 0
* @tree: the node to compute the height at
* Return: height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t num1, num2;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	num1 = binary_tree_height(tree->left);
	num2 = binary_tree_height(tree->right);
	return (1 + max(num1, num2));
}
/**
* binary_tree_is_full - checks if a binary tree is full or not
* @tree: the tree to consider
* Return: 1 if the tree is full, 0 therwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (0);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

/**
* binary_tree_is_complete - checks if a tree is complete or not
* @tree: the tree to check
* Return: 1 if the tree is complete, 0 otherwise
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	if (right_h > left_h)
		return (0);
	if (right_h + 1 < left_h)
		return (0);
	if (right_h == left_h && right_h != 0 && !binary_tree_is_full(tree->left))
		return (0);
	if (tree->right == NULL)
		return (1);
	return (binary_tree_is_complete(tree->left)
			&& binary_tree_is_complete(tree->right));
}
