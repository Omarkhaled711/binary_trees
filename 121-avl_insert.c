#include "binary_trees.h"

/**
 * avl_rotate - rotates a tree if needed to be avl balanced
 * @tree: the tree to rotate
 * @balance: the balance value
 * @value: the last value added to the tree
 * Return: void
*/
void avl_rotate(avl_t *tree, int balance, int value)
{
	avl_t *parent, *new_subroot;

	parent = tree->parent;
	if (balance > 1 && value < tree->left->n)
		new_subroot = binary_tree_rotate_right(tree);
	else if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		new_subroot = binary_tree_rotate_right(tree);
	}
	else if (balance < -1 && value > tree->right->n)
		new_subroot = binary_tree_rotate_left(tree);
	else if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		new_subroot = binary_tree_rotate_left(tree);
	}
	if (parent != NULL)
	{
		new_subroot->parent = parent;
		if (parent->left == tree)
			parent->left = new_subroot;
		else
			parent->right = new_subroot;
	}
}
/**
 * avl_insert - inserts a node in an avl tree
 * @tree: a pointer to the root node
 * @value: the value to insert
 * Return: the inserted node or NULL
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;
	int balance;

	if (tree == NULL)
		return (NULL);
	if ((*tree) == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
		else
			new_node = avl_insert(&((*tree)->left), value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
		else
			new_node = avl_insert(&((*tree)->right), value);
	}
	else
		return (NULL);
	balance = binary_tree_balance((*tree));
	if (balance > 1 || balance < -1)
		avl_rotate(*tree, balance, value);
	return (new_node);
}
