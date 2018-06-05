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

/**@file stack.cpp
 * @brief 
 * @author downey
 * @date 2018-06-05
 * 
 * */

#include "stack.h"


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





int main()
{
     Stack<u32> S1;
     Stack<string> S2;
    u32 data[]={1,2,3,4,5,6,7,8,9};
    string str_a[]={"hell","hello","hello_wor","hello world"};

    u32 value={0};
    string str[4];

    for(u32 i=0;i<9;i++)
    {
        S1.stack_push(data[i]);
    }
    for(u32 i=0;i<4;i++)
    {
        S2.stack_push(str_a[i]);
    }
    for(u32 i=0;i<9;i++)
    {
        S1.stack_pop(value);
        cout<<value<<"  ";
    }
    cout<<endl;
    for(u32 i=0;i<4;i++)
    {
        S2.stack_pop(str[i]);
        cout<<str[i]<<"  ";
    }
    cout<<endl;
    return 0;

}


