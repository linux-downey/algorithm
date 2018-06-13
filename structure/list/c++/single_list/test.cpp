#include "single_list.h"


int main()
{
    List<u32,string> list1;
    List<u32,u32> list2;

    List_node<u32,string>* temp1;
    List_node<u32,u32>* temp2;

    string test_string[]={"hell","hello","hello_wor","hello world"};
    u32 test_num[]={1,2,3,4};
    for(int i=0;i<4;i++)
    {
        list1.add_node(i,test_string[i]);
        list2.add_node(i,test_num[i]);
    }
    cout<<"list_len="<<list1.get_list_len()<<endl;
    list1.print_all_node();
    list2.print_all_node();

    list1.delete_node(1);
    list2.delete_node(1);

    cout<<"after delete:"<<endl;
    list1.print_all_node();
    list2.print_all_node();

    temp1=list1.find_node(0);
    temp2=list2.find_node(0);
    cout<<"find node value="<<temp1->value<<endl;
    cout<<"find node value="<<temp2->value<<endl;
    return 0;
}