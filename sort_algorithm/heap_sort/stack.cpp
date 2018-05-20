#include "stack.h"

Stack::Stack()
{
    
}


Stack::~Stack()
{
    destroy_stack();
}

s32 Stack::destroy_stack()
{
    u32 temp=0;
    while(0==stack_pop(&temp))
    {
        
    }
    delete stack.top;
    return 0;
}

s32 Stack::stack_init(u32 max_depth)
{
    stack.top=stack.bottom=new Stack_node_t;
    stack.top->next=NULL;
    stack.stack_max_depth=max_depth;
    stack.stack_depth=0;
    return 0;
}

s32 Stack::stack_is_full()
{
    if(stack.stack_depth>stack.stack_max_depth)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


void Stack::set_stack_max_depth(u32 max_depth)
{
    stack.stack_max_depth=max_depth;
}

s32 Stack::stack_is_empty()
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


s32 Stack::stack_pop(u32* elem)
{
    Stack_node_t *temp=stack.top;
    if(stack_is_empty())
    {
        return -1;
    }
    *elem=stack.top->value;     //top point to first node,get the node's value
    stack.top=stack.top->next;        //top point to deeper one.
    stack.stack_depth--;
    delete temp;                //delete popped one.
    return 0;
}




s32 Stack::stack_push(u32 elem)
{
    Stack_node_t *temp= new Stack_node_t;
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



void func()
{
    Stack S;
    u32 data[]={1,2,3,4,5,6,7,8,9};
    u32 value[9]={0};
    S.stack_init();
    for(u32 i=0;i<9;i++)
    {
        S.stack_push(data[i]);
    }
    for(u32 i=0;i<5;i++)
    {
        S.stack_pop(&value[i]);
        cout<<value[i]<<"  ";
    }
    cout<<endl;
}


/*
int main()
{
    func();
    return 0;

}
*/

