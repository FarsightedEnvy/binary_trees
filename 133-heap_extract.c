#include "binary_trees.h"

/**
 * max - Finds the node with the maximum value in a subtree.
 * @tree: The pointer to the root of the subtree.
 * Return: The pointer to the node with the maximum value.
 */
heap_t *max(heap_t *tree)
{
    heap_t *max_node = tree;
    if (tree->left && tree->left->n > max_node->n)
        max_node = tree->left;
    if (tree->right && tree->right->n > max_node->n)
        max_node = tree->right;
    return max_node;
}

/**
 * recurse_extract - Recursively extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 */
void recurse_extract(heap_t *tree)
{
    heap_t *sub_max, *right_max = NULL;

    if (!tree->left)
        return;

    sub_max = max(tree->left);
    if (tree->right)
        right_max = max(tree->right);
    if (right_max && right_max->n > sub_max->n)
        sub_max = right_max;

    tree->n = sub_max->n;

    if (!sub_max->left && !sub_max->right)
    {
        if (sub_max->parent && sub_max->parent->left == sub_max)
            sub_max->parent->left = NULL;
        if (sub_max->parent && sub_max->parent->right == sub_max)
            sub_max->parent->right = NULL;
        free(sub_max);
    }
    else
    {
        recurse_extract(sub_max);
    }
}

/**
 * heap_extract - Extracts the root from a Binary Heap.
 * @root: The pointer to the root of the tree.
 * Return: The value of the extracted node.
 */
int heap_extract(heap_t **root)
{
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    recurse_extract(*root);

    return (value);
}
