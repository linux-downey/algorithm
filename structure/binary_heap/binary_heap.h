#ifndef _BINARY_HEAP_H
#define _BINARY_HEAP_H

#include <iostream>
#include "binary_tree_basic.h"
#include "queue.h"

#ifndef PRE_DEFINE
#define PRE_DEFINE

using std::cout;
using std::cin;
using std::endl;

using u8 =unsigned char;
using u32=unsigned int;
using s32=int;
using u16=unsigned short;

#endif



template<typename T>
struct BIHEAP
{
	BIHEAP *left_child;
	BIHEAP *right_child;
	T value;
	u32 index;
};


using ELEM_TYPE=u32;

using BITREE_NODE=BIHEAP<ELEM_TYPE>;



#define BINARY_HEAP_DEBUG




class BiHeap:public BinaryTree<BITREE_NODE>
{
    public:
        BiHeap();
        ~BiHeap();
        BITREE_NODE* create_tree(ELEM_TYPE value);
        BITREE_NODE* create_null_tree(ELEM_TYPE value);
        s32 insert_node(BITREE_NODE* root,ELEM_TYPE value);
        s32 delete_node(BITREE_NODE* root);
        s32 adjust_node(BITREE_NODE* root);
        s32 destroy_tree(BITREE_NODE *root);
    private:
        BITREE_NODE* root;
        u32 node_num;
};


#endif