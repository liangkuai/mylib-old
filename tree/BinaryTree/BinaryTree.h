/**
 * 二叉树
 *
 * @author liangkuai
 * @data 2017.05.09
 */


#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


typedef int ElemType;

typedef struct _BinaryTreeNode
{
    ElemType data;
    struct _BinaryTreeNode *lchild, *rchild;
} BinaryTreeNode, *BinaryTree;


#endif
