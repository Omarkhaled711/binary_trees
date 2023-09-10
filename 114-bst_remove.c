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
* bst_search - searches for a value in bst
* @tree: the tree to search in
* @value: the value to search for
* Return: the node that contains the value, or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
/**
*connect_parent_child - connects a parent node with its new child
* @parent: the parent node
* @new_child: the new child
* @old_child: the old child
* Return: void
*/
void connect_parent_child(bst_t *parent, bst_t *new_child, bst_t *old_child)
{
	if (parent->left == old_child)
		parent->left = new_child;
	else if (parent->right == old_child)
		parent->right = new_child;
}
/**
 * right_null - the node to be removed has only left child
 * @root: the root of the tree
 * @new_node: the node to replace the removed one in bst tree
 * @remove: the node to be removed
 * Return: the new root of the tree
*/
bst_t *right_null(bst_t *root, bst_t *new_node, bst_t *remove)
{
		new_node = remove->left;
		new_node->parent = remove->parent;
		if (remove->parent != NULL)
			connect_parent_child(remove->parent, new_node, remove);
		free(remove);
		if (new_node->parent == NULL)
			return (new_node);
		return (root);
}
/**
* bst_remove - removes a node from tree
* @root: the root of the tree
* @value: the value to be removed
* Return: the new root of the tree
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_node = NULL, *remove;

	remove = bst_search(root, value);
	if (remove == NULL)
		return (root);
	if (remove->right == NULL)
		return (right_null(root, new_node, remove));
	new_node = left_des(remove->right);
	if (new_node->parent == remove)
	{
		new_node->parent = remove->parent;
		if (remove->parent != NULL)
			connect_parent_child(remove->parent, new_node, remove);
		free(remove);
		if (new_node->parent == NULL)
			return (new_node);
		return (root);
	}
	if (new_node->right != NULL)
		new_node->right->parent = new_node->parent;
	new_node->parent->left = new_node->right;
	new_node->parent = remove->parent;
	new_node->left = remove->left;
	new_node->right = remove->right;
	if (remove->left != NULL)
		remove->left->parent = new_node;
	remove->right->parent = new_node;
	if (new_node->parent != NULL)
		connect_parent_child(new_node->parent, new_node, remove);
	free(remove);
	if (new_node->parent == NULL)
		return (new_node);
	return (root);
}
