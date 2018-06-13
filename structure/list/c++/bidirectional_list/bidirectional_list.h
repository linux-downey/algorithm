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

/**@file bidirectional_list.h
 * @brief 
 * @author downey
 * @date 2018-06-05
 * 
 * */


#ifndef _BIDERECTIONAL_LIST_H
#define _BIDERECTIONAL_LIST_H



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
    List_node<T_INDEX,T_VALUE> *tail;
    u32 list_len;
};


template <typename T_INDEX,typename T_VALUE>
class Bidirec_List
{
    public:
        Bidirec_List();
        ~Bidirec_List();
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
Bidirec_List<T_INDEX,T_VALUE>::Bidirec_List()
{
    list.head=new List_node<T_INDEX,T_VALUE>;
    list.tail=new List_node<T_INDEX,T_VALUE>;
    list.head->next=list.tail;
    list.head->pre=NULL;
    list.tail->next=NULL;
    list.tail->pre=list.head;
    list.list_len=0;
}


template <typename T_INDEX,typename T_VALUE>
Bidirec_List<T_INDEX,T_VALUE>::~Bidirec_List()
{
    destroy_list();
}


template <typename T_INDEX,typename T_VALUE>
s32 Bidirec_List<T_INDEX,T_VALUE>::destroy_list()
{
    List_node<T_INDEX,T_VALUE>* temp=list.head->next;
    List_node<T_INDEX,T_VALUE>* temp_del=list.head->next;
    while(temp!=list.tail)
    {
        temp=temp->next;
        delete temp_del;
        temp_del=temp;
    }
    list.list_len=0;
    delete list.head;
    delete list.tail;
    list.head=NULL;
    list.tail=NULL;

    return 0;
}

template <typename T_INDEX,typename T_VALUE>
s32 Bidirec_List<T_INDEX,T_VALUE>::add_node(T_INDEX index,T_VALUE value)
{
    List_node<T_INDEX,T_VALUE>* temp=new List_node<T_INDEX,T_VALUE>;
    List_node<T_INDEX,T_VALUE>* p=list.head;

    temp->value=value;
    temp->index=index;
    temp->next=list.tail;
    while(p->next!=list.tail)
    {
        p=p->next;
    }
    p->next=temp;
    temp->pre=p;
    list.tail->pre=temp;
    list.list_len++;
    return 0;
}

template <typename T_INDEX,typename T_VALUE>
void Bidirec_List<T_INDEX,T_VALUE>::print_all_node(Traverse_direc_t direc)
{
    u32 i=0;
    List_node<T_INDEX,T_VALUE>* temp;
    if(FORWARD==direc)
    {
        temp=list.head->next;
        while(temp!=list.tail)
        {
            cout<<"node "<<i<<":"<<"index:"<<temp->index<<"  vlaue:"<<temp->value<<endl;
            i++;
            temp=temp->next;
        }
    }
    else
    {
        temp=list.tail->pre;
        while(temp!=list.head)
        {
            cout<<"node "<<i<<":"<<"index:"<<temp->index<<"  vlaue:"<<temp->value<<endl;
            i++;
            temp=temp->pre;
        }
    }
}


template <typename T_INDEX,typename T_VALUE>
s32 Bidirec_List<T_INDEX,T_VALUE>::delete_node(T_INDEX index)
{
    List_node<T_INDEX,T_VALUE>* temp=list.head->next;
    while(temp!=list.tail)
    {
        if(temp->index==index)
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
u32 Bidirec_List<T_INDEX,T_VALUE>::get_list_len()
{
    return list.list_len;
}



template <typename T_INDEX,typename T_VALUE>
List_node<T_INDEX,T_VALUE>* Bidirec_List<T_INDEX,T_VALUE>::find_node(T_INDEX index)
{
    List_node<T_INDEX,T_VALUE>* temp=list.head->next;
    while(temp!=list.tail)
    {
        if(temp->index==index)
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
