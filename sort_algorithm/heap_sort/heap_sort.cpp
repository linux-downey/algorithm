#include "heap_sort.h"
#include "stack.h"

Heap::Heap()
{
    root=new Tree_node_t;
    root->left_child=NULL;
    root->right_child=NULL;
    root->value=0;
    root->child_num=0;
}

Heap::~Heap()
{
    delete root;
}


template<typename T>
void Heap::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        //cout<<i+1<<'-'<<data[i];
        cout<<data[i];
        cout<<"   ";
    }
    cout<<endl;
}


void Heap::insert_node(Tree_node_t* root,Tree_node_t *insert_node)
{
    //Tree_node_t* temp=root;
    
}


void Heap::create_binary_tree(u32 *data,u32 len)
{
    u32 i=0;
    root->value=data[0];
    for(i=0;i<len-1;i++)
    {
        //Tree_node_t* node=new Tree_node_t;
        
    }
}


void Heap::adjust_binary_tree(u32 *data,u32 len)
{

}

void Heap::heap_sort(u32 *data,u32 len)
{

}



int main()
{
    Heap sort;
    //u32 data[]={6,64,25,84,5,1,2,48,62,5,8,548,24,12,6456,1,513456,1,31,5641,32,165,4135,15,145,15,6415456,48,4864,6584,6,84,5,2,6,4,2,4,58,1,4,1,1,2,65};

    return 1;
}


