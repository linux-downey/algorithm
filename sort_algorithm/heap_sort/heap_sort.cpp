#include "heap_sort.h"
#include "stack.h"



Stack S;


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
    destroy_tree(root);
}




void Heap::destroy_tree(Tree_node_t* root)
{
    if(NULL==root)
    {
        return;
    }
    Tree_node_t *temp=root;
    delete root;
    destroy_tree(temp->left_child);
    destroy_tree(temp->right_child);
}


template<typename T>
void Heap::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        cout<<data[i];
        //cout<<"   ";
    }
    //cout<<endl;
}



/**
*
*
**/      
/*???????????????????????????????????????????????????????????????????????????????*/
void Heap::insert_node(Tree_node_t* root,Tree_node_t *insert_node,u32 index_of_array)
{
    Tree_node_t* p=root,q;      //Use two point to locat the location of new node.
    u32 elem=0;
    u32 index_of_tree=index_of_array+1;
    u32 temp=index_of_tree;
    if(1==index_of_tree)                    //Put the first elem of array into root;
    {
        root->value=insert_node->value;
        delete insert_node;
        return ;
    }
    while(temp>1)
    {
        S.stack_push(temp);
        temp=temp/2;
    }
    // while(0==S.stack_pop(&elem))
    // {
    //     cout<<elem<<" "<<endl;
    // }
    while(0==S.stack_pop(&elem))
    {
        if(elem%2!=0)                   //right branch
        {
            
        }
        else                            //left branch
        {

        }
    }
    
}

/**

*/
void Heap::create_binary_tree(u32 *data,u32 len)
{
    u32 i=0;
    root->value=data[0];
    for(i=0;i<len-1;i++)
    {
        Tree_node_t* node=new Tree_node_t;
        node->value=data[i];
        insert_node(root,node,i);  //o in array corresponding to 1 of tree.root is 1 of tree.
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

    S.stack_init();
    //u32 data[]={6,64,25,84,5,1,2,48,62,5,8,548,24,12,6456,1,513456,1,31,5641,32,165,4135,15,145,15,6415456,48,4864,6584,6,84,5,2,6,4,2,4,58,1,4,1,1,2,65};
    sort.insert_node(sort.root,NULL,27);

    return 1;
}


