#ifndef _BIDIRECTIONAL_CYCLING_LIST_H
#define _BIDIRECTIONAL_CYCLING_LIST_H


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


typedef enum
{
    FORWARD,
    REVERSE,
}Traverse_direc_t;


template <typename T_INDEX,typename T_VALUE>
struct List_node
{
    List_node *next;
    List_node *pre;
    T_INDEX index;
    T_VALUE value;
};


template <typename T_INDEX,typename T_VALUE>
struct List_t
{
    List_node<T_INDEX,T_VALUE> *head;
    u32 list_len;
};

template <typename T_INDEX,typename T_VALUE>
class BidirecCyc_List
{
    public:
        BidirecCyc_List();
        ~BidirecCyc_List();
        s32 add_node(T_INDEX index,T_VALUE value);
        s32 delete_node(T_INDEX index);
        List_node<T_INDEX,T_VALUE>* find_node(T_INDEX index);
        s32 destroy_list();
        u32 get_list_len();
        void print_all_node(Traverse_direc_t direc);
    private:
       List_t<T_INDEX,T_VALUE> list;
};

template <typename T_INDEX,typename T_VALUE>
BidirecCyc_List<T_INDEX,T_VALUE>::BidirecCyc_List()
{
    list.head=new List_node<T_INDEX,T_VALUE>;
    list.head->next=list.head;
    list.head->pre=list.head;
    list.list_len=0;
}

template <typename T_INDEX,typename T_VALUE>
BidirecCyc_List<T_INDEX,T_VALUE>::~BidirecCyc_List()
{
    destroy_list();
}

template <typename T_INDEX,typename T_VALUE>
s32 BidirecCyc_List<T_INDEX,T_VALUE>::destroy_list()
{
    List_node<T_INDEX,T_VALUE>* temp=list.head->next;
    List_node<T_INDEX,T_VALUE>* temp_del=list.head->next;
    while(temp!=list.head)
    {
        temp=temp->next;
        delete temp_del;
        temp_del=temp;
    }
    list.list_len=0;
    delete list.head;
    list.head=NULL;
    return 0;
}


template <typename T_INDEX,typename T_VALUE>
s32 BidirecCyc_List<T_INDEX,T_VALUE>::add_node(T_INDEX index,T_VALUE value)
{
    List_node<T_INDEX,T_VALUE>* temp=new List_node<T_INDEX,T_VALUE>;
    List_node<T_INDEX,T_VALUE>* q=list.head->next;

    temp->next=list.head;
    temp->index=index;
    temp->value=value;

    while((q!=list.head))
    {
        q=q->next;
    }
    //q==list.head  at this time.
    temp->pre=q->pre;        
    temp->pre->next=temp;   
    q->pre=temp;
    list.list_len++;
    return 0;
}

template <typename T_INDEX,typename T_VALUE>
u32 BidirecCyc_List<T_INDEX,T_VALUE>::get_list_len()
{
    return list.list_len;
}



template <typename T_INDEX,typename T_VALUE>
void BidirecCyc_List<T_INDEX,T_VALUE>::print_all_node(Traverse_direc_t direc)
{
    u32 i=0;
    List_node<T_INDEX,T_VALUE> *temp;
    if(FORWARD==direc)
    {
        temp=list.head->next;
        while(temp!=list.head)
        {
            cout<<"node "<<i<<":"<<"index:"<<temp->index<<"  vlaue:"<<temp->value<<endl;
            i++;
            temp=temp->next;
        }
    }
    else
    {
        temp=list.head->pre;
        while(temp!=list.head)
        {
            cout<<"node "<<i<<":"<<"index:"<<temp->index<<"  vlaue:"<<temp->value<<endl;
            i++;
            temp=temp->pre;
        }
    }    
}


template <typename T_INDEX,typename T_VALUE>
s32 BidirecCyc_List<T_INDEX,T_VALUE>::delete_node(T_INDEX index)
{
    List_node<T_INDEX,T_VALUE> *temp=list.head->next;
    while(temp!=list.head)
    {
        if(index==temp->index)
        {
            temp->pre->next=temp->next;
            temp->next->pre=temp->pre;
            delete temp;
            list.list_len--;
            return 0;
        }
        else
        {
            temp=temp->next;
        }
    }
    return -1;
}

template <typename T_INDEX,typename T_VALUE>
List_node<T_INDEX,T_VALUE>* BidirecCyc_List<T_INDEX,T_VALUE>::find_node(T_INDEX index)
{
    List_node<T_INDEX,T_VALUE> *temp=list.head->next;
    while(temp!=list.head)
    {
        if(index==temp->index)
        {
            return temp;
        }
        else
        {
            temp=temp->next;
        }
    }
    return NULL;
}



#endif


