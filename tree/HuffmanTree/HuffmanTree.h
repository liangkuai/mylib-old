/**
 * 哈夫曼树
 *
 * @author liangkuai
 * @data 2017.05.07
 */


#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

typedef unsigned int WeightType;

typedef struct _HuffmanNode
{
    WeightType weight;
    
    struct _HuffmanNode *parent;
    struct _HuffmanNode *lchild;
    struct _HuffmanNode *rchild;
} HuffmanNode;

typedef struct _HuffmanTree
{
    HuffmanNode *head;
    unsigned int leaf_node_num;
} HuffmanTree;

#endif  // _HUFFMAN_TREE_H_
