#ifndef _SBITREE_H
#define _SBITREE_H

#include <iostream>
#include <string>
#include <string.h>

#include "binary.h"

#ifndef PRE_DEFINE
#define PRE_DEFINE

using std::cout;
using std::cin;
using std::endl;
using std::string;

using u8 =unsigned char;
using u32=unsigned int;
using s32=int;
using u16=unsigned short;

#endif


struct SearchTreeNode
{
	SearchTreeNode *left_child;
	SearchTreeNode *right_child;
	u32 value;
};


class SearchBiTree:public BinaryTree<SearchTreeNode>
{
    public:
        SearchBiTree();
        ~SearchBiTree();
        SearchTreeNode* create_tree(u32 value);
        s32 insert_node(SearchTreeNode* root,u32 value);
        SearchTreeNode* find_node(SearchTreeNode* root,u32 value);
        s32 delete_node(SearchTreeNode* root,u32 value);
        
    private:
        s32 insert_node(SearchTreeNode* root,SearchTreeNode* node);
        s32 delete_node_in_different_situation(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node);
        s32 no_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node);
        s32 only_left_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node);
        s32 only_right_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node);
        s32 two_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node);
        void copy_node_value(SearchTreeNode* dst_node,SearchTreeNode* src_node);
        SearchTreeNode* root;
};




#endif


