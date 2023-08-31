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
* process_current_level - process the level passed as arg
* @tree: the tree to process
* @func: the function to apply on the tree nodes values
* @level: the level to process
* Return: void
*/
void process_current_level(const binary_tree_t *tree,
						void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	process_current_level(tree->left, func, level - 1);
	process_current_level(tree->right, func, level - 1);
}

/**
* binary_tree_levelorder - level traversal for the tree
* @tree: the tree to process
* @func: the function to apply on the tree nodes values
* Return: void
*/
void binary_tree_levelorder(const binary_tree_t *tree,
						void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_tree_height(tree);
	for (i = 1; i <= h; i++)
		process_current_level(tree, func, i);
}
