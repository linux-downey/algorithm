#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned int;
using s32=int;


typedef struct Node
{   
    struct Node *left_child;
    struct Node *right_child;
    u32 value;
    u32 child_num;
}Tree_node_t;


class Heap
{
    public:
        Heap();
        ~Heap();
        void create_binary_tree(u32 *data,u32 len);
        void adjust_binary_tree(u32 *data,u32 len);
        void heap_sort(u32 *data,u32 len);
        void insert_node(Tree_node_t* root,Tree_node_t *insert_node);
        template<typename T>
        void print_data(T *data,u32 data_len);
    private:
        Tree_node_t *root;
        vector<u32> data_from_cmdline;
        
};




#endif

