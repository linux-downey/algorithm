#ifndef _AVL_TREE_H
#define _AVL_TREE_H



#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "math.h"
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


#define UNBALANCED  1
#define BALANCED    0

struct AVLTreeNode
{
	AVLTreeNode *left_child;
	AVLTreeNode *right_child;
    s32 height;                 //The initial value is 1
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
    DELETE_ONE_CHILD,
    DELETE_TWO_CHILD,
    NOT_CHANGE,
}del_stat_t;