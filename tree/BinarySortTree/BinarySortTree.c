#include <stdio.h>
#include <stdlib.h>
#include "BinarySortTree.h"
#include "../../common.h"


int treeEmpty(const BST tree)
{
    if (tree)
        return TRUE;
    else
        return FALSE;
}


BSTNode *searchNodeByRecursion(const BST tree, ElemType e)
{
    if (treeEmpty(tree) || e == tree->data)
        return tree;

    if (e < tree->data)
        return searchNode(tree->lchild, e);
    else
        return searchNode(tree->rchild, e);
}

BSTNode *searchNode(const BST tree, ElemType e)
{
    if (treeEmpty(tree) || e == tree->data)
        return tree;

    while (tree && e != tree->data)
    {
        if (e < tree->data)
            tree = tree->lchild;
        else
            tree = tree->rchild;
    }
}

int insertNode(BST tree, ElemType e)
{
    BSTNode *new_node;
    BSTNode *p = tree;

    if (!searchNode(p, e))
    {
            
        new_node = (BSTNode *)malloc(sizeof(BSTNode));
        new_node->data = e;
        new_node->lchild = new_node->rchild = NULL;

        if (treeEmpty)
            tree = new_node;
        else if (e < p->data)
            p->lchild = new_node;
        else
            p->rchild = new_node;
    }
    return EXECUTE_SUCCESS;
}
