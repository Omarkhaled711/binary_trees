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
* check_avl_tree - checks if a bst is an avl
* @tree: the tree to check
* @prev: the previous value in inorder traversal
* Return: 1 if avl, 0 otherwise
*/
int check_avl_tree(const binary_tree_t *tree, int *prev)
{
	int left;
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (1);
	left = check_avl_tree(tree->left, prev);
	if (left == 0)
		return (0);
	if (tree->n < (*prev) || tree->n == (*prev))
		return (0);
	*prev = tree->n;
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	if (left_h > right_h && left_h - right_h > 1)
		return (0);
	if (right_h > left_h && right_h - left_h > 1)
		return (0);
	return (check_avl_tree(tree->right, prev));
}
/**
 * binary_tree_is_avl - a wrapper function for check_avl_tree
 * and returns 0 if the tree is empty (null)
 * @tree: the tree to check
 * Return: if the tree is avl, 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int prev = -2e9;

	if (tree == NULL)
		return (0);
	return (check_avl_tree(tree, &prev));
}
