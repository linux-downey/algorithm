#ifndef _AVL_TREE_H
#define _AVL_TREE_H



#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

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


#define UNBANLANCED_ROOT  1
#define UNBANLANCED_NON_ROOT  2
#define MAX(a,b)  (a>b?a:b)

struct AVLTreeNode
{
	AVLTreeNode *left_child;
	AVLTreeNode *right_child;
    s32 height;
    s32 bf;  /*balance factory*/
	u32 value;
};

typedef enum
{
    LEFT,
    RIGHT,
}side_t;

typedef enum
{
    NOT_CHANGED,
    GROWN,
}opr_stat_t;


typedef enum
{
    DELETE_NO_CHILD,
    DELETE_ONLY_LEFT_CHILD,
    DELETE_ONLY_RIGHT_CHILD,
    NOT_CHANGE,
    SHORTEN,
}del_stat_t;

#define  LH   1   /*left subtree height is taller than right subtree height by 1*/
#define  RH   -1  /*left subtree height is shorter than right subtree height by 1*/
#define  EH   0   /*left subtree height is equal to right subtree height*/


class AVLTree:public BinaryTree<AVLTreeNode>
{
    public:
        AVLTree();
        ~AVLTree();
        AVLTreeNode* create_tree(u32 value);
        s32 insert_node(AVLTreeNode* root,u32 value);
        s32 adjust_tree(AVLTreeNode* root);
        AVLTreeNode* find_node(AVLTreeNode* root,u32 value);
        s32 delete_node(AVLTreeNode* root,u32 value);
        AVLTreeNode* find_smallest_from_sub_right(AVLTreeNode* root,del_stat_t& opt_stat);
        s32 delete_node(AVLTreeNode* root,u32 value,del_stat_t& opt_stat);
    private:
        void swap_two_node_value(AVLTreeNode*& node1,AVLTreeNode*& node2);
        s32 insert_node(AVLTreeNode* root,AVLTreeNode* node,opr_stat_t& opr_stat);
        s32 check_balance(AVLTreeNode* root);
        s32 adjust_tree_node(AVLTreeNode* root,u32 unbanlance_reason);
        s32 adjust_root_only_one_child_case(AVLTreeNode* root);
        void relink_node(AVLTreeNode* root,AVLTreeNode* left,AVLTreeNode* right);
        AVLTreeNode* find_adjust_node(AVLTreeNode* root);

        s32 left_rotation(AVLTreeNode* node);
        s32 right_rotation(AVLTreeNode* node);

        void LL_rotation(AVLTreeNode* node);
        void LR_rotation(AVLTreeNode* node);
        void RL_rotation(AVLTreeNode* node);
        void RR_rotation(AVLTreeNode* node);

        void RL_TO_RR_rotation(AVLTreeNode* node);
        void LR_TO_LL_rotation(AVLTreeNode* node);

        void R_rotation(AVLTreeNode* node);
        void L_rotation(AVLTreeNode* node);

        void delete_no_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat);
        void delete_only_left_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat);
        void delete_only_right_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat);
        void sub_tree_shorten(AVLTreeNode* node,side_t side,del_stat_t& opt_stat);
        AVLTreeNode *root;
};




#endif
