#include "bidirectional_list.h"



int main()
{
    Bidirec_List<u32,string> list1;
    Bidirec_List<u32,u32> list2;

    List_node<u32,string>* temp1;
    List_node<u32,u32>* temp2;

    string test_string[]={"hell","hello","hello_wor","hello world"};
    u32 test_num[]={1,2,3,4};
    cout<<"list len="<<list1.get_list_len()<<endl;
    cout<<"list len="<<list2.get_list_len()<<endl;
    for(int i=0;i<4;i++)
    {
        list1.add_node(i,test_string[i]);
        list2.add_node(i,test_num[i]);
    }

    cout<<"list len="<<list1.get_list_len()<<endl;
    cout<<"list len="<<list2.get_list_len()<<endl;

    list1.delete_node(1);
    list2.delete_node(1);

    cout<<"list len="<<list1.get_list_len()<<endl;
    cout<<"list len="<<list2.get_list_len()<<endl;

    cout<<"list1 forward:"<<endl;
    list1.print_all_node(FORWARD);
    cout<<"list1 reverse:"<<endl;
    list1.print_all_node(REVERSE);
    cout<<"list2 forward:"<<endl;
    list2.print_all_node(FORWARD);
    cout<<"list2 reverse:"<<endl;
    list2.print_all_node(REVERSE);

    temp1=list1.find_node(0);
    temp2=list2.find_node(0);

    cout<<"find node's value="<<temp1->value<<endl;
    cout<<"find node's value="<<temp2->value<<endl;

    return 0;
}