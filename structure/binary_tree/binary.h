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


class BinaryTree
{
	public:
	 	BinaryTree();
		~BinaryTree();
		TreeNode<u32>* create_tree();   //create a tree from user input.
		s32 create_tree(u32 value);    //create a empty tree;
		s32 destroy_tree(TreeNode<u32> *root);
		s32 insert_node(u32 value);
		s32 delete_node(u32 *value);
		TreeNode<u32>* get_root();
		TreeNode<u32> *root;
		
		s32 preorder_traversal(TreeNode<u32> *root);
		s32 middle_order_traversal(TreeNode<u32> *root);
		s32 post_order_traversal(TreeNode<u32> *root);
		s32 level_traversal(TreeNode<u32> *root);
		s32 level_traversal(TreeNode<u32> *root);
		s32 get_height_of_tree(TreeNode<u32> *root);
	private:
		
};


#endif

