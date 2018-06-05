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


#endif
