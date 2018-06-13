#ifndef _BINARY_TREE_BASIC_H
#define _BINARY_TREE_BASIC_H

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

//#define BITREE_DEBUG


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

template<class NODE_TYPE>
class BinaryTree
{
	public:
	 	BinaryTree();
		~BinaryTree();
		NODE_TYPE* create_tree_preorder();
		virtual NODE_TYPE* create_tree();   //create a tree from user input.
		s32 destroy_tree(NODE_TYPE *root);
		
		
		s32 preorder_traversal(NODE_TYPE *root);
		s32 middle_order_traversal(NODE_TYPE *root);
		s32 post_order_traversal(NODE_TYPE *root);
		s32 level_traversal(NODE_TYPE *root);
		u32 get_height_of_tree(NODE_TYPE *root);
		u32 leaves_counts(NODE_TYPE *root);
		u32 nodes_counts(NODE_TYPE *root);
		u32 get_level_nodes(NODE_TYPE *root,u32 level);
		
		NODE_TYPE* get_root();
		template<typename T>
		void print_node_value(T value);
	private:
		NODE_TYPE *root;
};


#endif

