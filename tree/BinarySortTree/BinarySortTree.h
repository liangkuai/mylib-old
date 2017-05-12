/**
 * BST, 二叉排序树
 *
 * @author liangkuai
 * @data 2017.05.09
 */

#ifndef _BINARY_SORT_TREE_H_
#define _BINARY_SORT_TREE_H_


typedef int ElemType;

typedef struct _BSTNode
{
    ElemType data;
    struct _BinarySortTree *lchild, *rchild;
} BSTNode, *BST;


int treeEmpty(const BST tree);


BSTNode *searchNodeByRecursion(const BST tree, ElemType e);

BSTNode *searchNode(const BST tree, ElemType e);

int insertNode(BST tree, ElemType e);

#endif
