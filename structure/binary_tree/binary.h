#ifndef _BINARY_H
#define _BINARY_H

#include <iostream>

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

#define BITREE_DEBUG


template<typename T>
struct TreeNode
{
	TreeNode *left_child;
	TreeNode *right_child;
	T value;
};

using ELEM_TYPE=u32;

using TREE_NODE=TreeNode<ELEM_TYPE>;
using TREE_NODE_PTR=TreeNode<ELEM_TYPE>*;

class BinaryTree
{
	public:
	 	BinaryTree();
		~BinaryTree();
		TREE_NODE* create_tree_preorder();
		TREE_NODE* create_tree();   //create a tree from user input.
		s32 create_tree(ELEM_TYPE value);    //create a empty tree;
		s32 destroy_tree(TREE_NODE *root);
		
		
		s32 preorder_traversal(TREE_NODE *root);
		s32 middle_order_traversal(TREE_NODE *root);
		s32 post_order_traversal(TREE_NODE *root);
		s32 level_traversal(TREE_NODE *root);
		u32 get_height_of_tree(TREE_NODE *root);
		u32 leaves_counts(TREE_NODE *root);
		u32 nodes_counts(TREE_NODE *root);
		u32 get_level_nodes(TREE_NODE *root,u32 level);
		
		TREE_NODE* get_root();

		template<typename T>
		void print_node_value(T value);
	private:
		TREE_NODE *root;
};


#endif

