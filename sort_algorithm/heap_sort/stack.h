#ifndef _STACK_H
#define _STACK_H


#include <iostream>
#include <vector>
#include <string>

/*
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned int;
using s32=int;

*/
template <class T> 
struct Stack_node
{
    T value;
    
    struct Stack_node<T> *next; 
};

typedef struct Stack_node<u32>  Stack_node_t;


typedef struct
{
    Stack_node_t *top;
    Stack_node_t *bottom;
    u32 stack_max_depth;
    u32 stack_depth;
}Stack_t;

// template <class T>
// typedef struct StackNode
// {
// 　　T value;
// 　　struct StackNode<T> *next;
// }Stack_node;


class Stack
{
    private:
        Stack_t stack;
        
    public:
        Stack();
        ~Stack();
        s32 stack_init(u32 max_depth=100);
        s32 stack_pop(u32* elem);
        s32 stack_push(u32 elem);
        s32 destroy_stack();
        s32 stack_is_empty();
        s32 stack_is_full();
        void set_stack_max_depth(u32 max_depth);
};


#endif
