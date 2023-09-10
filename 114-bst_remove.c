#include "binary_trees.h"

/**
* left_des - finds the left descendant in a tree
* @node: the node to search from
* Return: the left descendant node
*/
bst_t *left_des(bst_t *node)
{
	if (node->left == NULL)
		return (node);
	return (left_des(node->left));
}
/**
* bst_remove - removes a node from tree
* @root: the root of the tree
* @value: the value to be removed
* Return: the new root of the tree
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_node = NULL;

	if (root == NULL)
		return (NULL);
	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);
	}
	if (root->left == NULL)
	{
		new_node = root->right;
		if (new_node != NULL)
			new_node->parent = root->parent;
		free(root);
		return (new_node);
	}
	if (root->right == NULL)
	{
		new_node = root->left;
		new_node->parent = root->parent;
		free(root);
		return (new_node);
	}
	new_node = left_des(root->right);
	if (new_node->parent == root)
		new_node->parent->right = new_node->right;
	else
		new_node->parent->left = new_node->right;
	if (new_node->right != NULL)
		new_node->right->parent = new_node->parent;
	root->n = new_node->n;
	free(new_node);
	return (root);
}
