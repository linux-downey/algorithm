//  
//                                  _oo8oo_
//                                 o8888888o
//                                 88" . "88
//                                 (| -_- |)
//                                 0\  =  /0
//                               ___/'==='\___
//                             .' \\|     |// '.
//                            / \\|||  :  |||// \
//                           / _||||| -:- |||||_ \
//                          |   | \\\  -  /// |   |
//                          | \_|  ''\---/''  |_/ |
//                          \  .-\__  '-'  __/-.  /
//                        ___'. .'  /--.--\  '. .'___
//                     ."" '<  '.___\_<|>_/___.'  >' "".
//                    | | :  `- \`.:`\ _ /`:.`/ -`  : | |
//                    \  \ `-.   \_ __\ /__ _/   .-` /  /
//                =====`-.____`.___ \_____/ ___.`____.-`=====
//                                  `=---=`
// 
//                          佛祖保佑         永无bug
// 

/**@file stack.h
 * @brief 
 * @author downey
 * @date 2018-06-05
 * 
 * */
#ifndef _STACK_H
#define _STACK_H


#include <iostream>
#include <string>

#ifndef PRE_DEFINE
#define PRE_DEFINE

using std::cout;
using std::cin;
using std::endl;
using std::string;

using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned int;
using s32=int;

#endif


template <typename T> 
struct Stack_node
{
    struct Stack_node *next;
    T value; 
};


template <typename T>
struct Stack_t
{
    Stack_node<T> *top;
    Stack_node<T> *bottom;
    u32 stack_max_depth;
    u32 stack_depth;
};



#define DEFAULT_DEPTH  255


/*User specifys the stack elem-type when declare a object.
**
*/
template <class T>
class Stack
{
    private:
        Stack_t<T> stack;
        
    public:
        Stack(u32 max_depth=DEFAULT_DEPTH);
        ~Stack();

        s32 stack_pop(T& elem);
        s32 stack_pop();

        s32 stack_push(T elem);
        s32 destroy_stack();
        s32 stack_is_empty();
        s32 stack_is_full();
        void set_stack_max_depth(u32 max_depth);
};


/*Create a stack in constructor.
**User needn't to init the stack,because the NULL-stack was created at instantiation.
**User defines a max stack len,defualt is 255.
*/
template <class T>
Stack<T>::Stack(u32 max_depth)
{
    stack.top=stack.bottom=new Stack_node<T>;
    stack.top->next=NULL;
    stack.stack_max_depth=max_depth;
    stack.stack_depth=0;
}


/*Destroy the stack automatically in Destructor to avoid leak of memory.
**User can also call destroy_stack() to clean the stack.Double-destroy is acceptable.
*/
template <class T>
Stack<T>::~Stack()
{
    destroy_stack();
}

template <class T>
s32 Stack<T>::destroy_stack()
{
    while(0==stack_pop())
    {
        
    }
    delete stack.top;
    return 0;
}

template <class T>
s32 Stack<T>::stack_is_full()
{
    if(stack.stack_depth>=stack.stack_max_depth)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

template <class T>
void Stack<T>::set_stack_max_depth(u32 max_depth)
{
    stack.stack_max_depth=max_depth;
}


template <class T>
s32 Stack<T>::stack_is_empty()
{
    if(stack.top==stack.bottom)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
s32 Stack<T>::stack_pop()
{
    Stack_node<T> *temp=stack.top;
    if(stack_is_empty())
    {
        return -1;
    }
    stack.top=stack.top->next;        //top point to deeper one.
    stack.stack_depth--;
    delete temp;                //delete popped one.
    return 0;
}


template <class T>
s32 Stack<T>::stack_pop(T& elem)
{
    Stack_node<T> *temp=stack.top;
    if(stack_is_empty())
    {
        return -1;
    }
    elem=stack.top->value;     //top point to first node,get the node's value
    stack.top=stack.top->next;        //top point to deeper one.
    stack.stack_depth--;
    delete temp;                //delete popped one.
    return 0;
}


template <class T>
s32 Stack<T>::stack_push(T elem)
{
    Stack_node<T> *temp=new Stack_node<T>;
    if(stack_is_full())
    {
        return -1;
    }
    temp->value=elem;
    temp->next=stack.top;     //new node->next point to top.
    stack.top=temp;                  // update top pointer.
    stack.stack_depth++;      //depth plus 1
    return 0;
}



#endif
