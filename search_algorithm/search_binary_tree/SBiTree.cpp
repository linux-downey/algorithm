#include "SBiTree.h"


SearchBiTree::SearchBiTree()
{

}


SearchBiTree::~SearchBiTree()
{
    destroy_tree(root);
}


SearchTreeNode* SearchBiTree::create_tree(u32 value)
{
    root=new SearchTreeNode;
    root->left_child=root->right_child=NULL;
    root->value=value;
    return root;
}


s32 SearchBiTree::insert_node(SearchTreeNode* root,SearchTreeNode* node)
{
    if(node->value>root->value)  
    {
        if(NULL!=root->right_child)
        {
            insert_node(root->right_child,node);
        }
        else
        {
            root->right_child=node;
        }
    }
    else if(node->value<root->value)
    {
        if(NULL!=root->left_child)
        {
            insert_node(root->left_child,node);
        }
        else
        {
            root->left_child=node;
        }
    }
    else
    {
        cout<<"Not support same vlaue"<<endl;
    }
    return 0;
}

s32 SearchBiTree::insert_node(SearchTreeNode* root,u32 value)
{
    SearchTreeNode* temp=new SearchTreeNode;
    temp->left_child=NULL;
    temp->right_child=NULL;
    temp->value=value;

    insert_node(root,temp);
    return 0;
}

SearchTreeNode* SearchBiTree::find_node(SearchTreeNode* root,u32 value)
{
    if(NULL==root)
    {
        return NULL;
    }
    if(value>root->value)
    {
        return find_node(root->right_child,value);
    }
    else if(value==root->value)
    {
        return root;
    }
    else
    {
        return find_node(root->left_child,value);
    }
}


s32 SearchBiTree::no_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node)
{
    if(dst_father_node==dst_node)
        {
            delete dst_node;
            this->root=NULL;
            return 0;
        }
        else
        {
            if(dst_node==dst_father_node->left_child)
            {
                dst_father_node->left_child=NULL;
                delete dst_node;
                return 0;
            }
            else if(dst_node==dst_father_node->right_child)
            {
                dst_father_node->right_child=NULL;
                delete dst_node;
                return 0;
            }
        }
}



s32 SearchBiTree::only_left_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node)
{
    //if the dst node is root,wo just can't delete it,just copy the data from replace node.
    if(dst_father_node==dst_node)
    {
        SearchTreeNode* temp=dst_node->left_child;
        memcpy(dst_node,dst_node->left_child,sizeof(SearchTreeNode));
        delete temp;
        return 0;
    }
    else
    {
        if(dst_node==dst_father_node->left_child)
        {
            dst_father_node->left_child=dst_node->left_child;
            delete dst_node;
            return 0;
        }
        else if(dst_node==dst_father_node->right_child)
        {
            dst_father_node->right_child=dst_node->left_child;
            delete dst_node;
            return 0;
        }
    }
    
    return 0;
}
s32 SearchBiTree::only_right_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node)
{
    if(dst_father_node==dst_node)
    {
        SearchTreeNode* temp=dst_node->right_child;
        memcpy(dst_node,dst_node->right_child,sizeof(SearchTreeNode));
        delete temp;
        return 0;
    }
    else
    {
        if(dst_node==dst_father_node->left_child)
        {
            dst_father_node->left_child=dst_node->right_child;
            delete dst_node;
            return 0;
        }
        else if(dst_node==dst_father_node->right_child)
        {
            dst_father_node->right_child=dst_node->right_child;
            delete dst_node;
            return 0;
        }
    }
    return 0;
}
s32 SearchBiTree::two_child_case(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node)
{
        SearchTreeNode* q=dst_node;
        SearchTreeNode* p=dst_node->right_child;  
        //find smallest one from right sub-tree.
        while(p->left_child!=NULL)
        {
            q=p;
            p=p->left_child;
        }
        //cout<<"dst father node is"<<q->value<<endl<<"dst node is"<<p->value<<endl;
        //replace the node
        //case1:The right child of dst node is smallest one in right-sub-tree.
        //the delete node is q,the replace node is p.
        if(q==dst_node)
        {
            if(dst_father_node==dst_node)
            {
                SearchTreeNode *temp=dst_node->left_child;
                memcpy(dst_node,p,sizeof(SearchTreeNode));
                dst_node->left_child=temp;
                delete p;
                return 0;
            }
            else
            {
                if(dst_node==dst_father_node->left_child)
                {
                    dst_father_node->left_child=p;
                }
                else
                {
                    dst_father_node->right_child=p;
                }
                p->left_child=q->left_child;
                delete q;
                return 0;
            }
            
        }
        //case2
        else
        {
            if(dst_father_node==dst_node)
            {
                
                SearchTreeNode *temp_left=dst_node->left_child;
                SearchTreeNode *temp_right=dst_node->right_child;
                q->left_child=p->right_child;
                memcpy(dst_node,p,sizeof(SearchTreeNode));
                dst_node->left_child=temp_left;
                dst_node->right_child=temp_right;
                //delete node  
                delete p;
                return 0; 
            }
            else
            {
                if(dst_node==dst_father_node->left_child)
                {
                    dst_father_node->left_child=p;
                }
                else
                {
                    dst_father_node->right_child=p;
                }
                
                //the smallest node replace by it's right child.According to specification of Binary-Search-Tree,this node has not left child certainly.
                q->left_child=p->right_child;
                p->left_child=dst_node->left_child;
                p->right_child=dst_node->right_child;
                //delete node  
                delete dst_node;
                
                return 0; 
            }
            
            
        }
    return 0;
}


s32 SearchBiTree::delete_node_in_different_situation(SearchTreeNode* dst_father_node,SearchTreeNode* dst_node)
{
    //There is no child with dst node,just delete dst node.
    if((NULL==dst_node->left_child)&&(NULL==dst_node->right_child))  
    {
        no_child_case(dst_father_node,dst_node);
        return 0;
    }
    //The node only has a right child,moving dst father's pointer to next node.skip this node.
    else if((NULL==dst_node->left_child)&&(NULL!=dst_node->right_child))  
    {   
        only_right_child_case(dst_father_node,dst_node);
    }
    //The node only has a left child,moving dst father's pointer to next node.skip this node.
    else if((NULL!=dst_node->left_child)&&(NULL==dst_node->right_child))
    {
        only_left_child_case(dst_father_node,dst_node);
    }
    //This node have two child,find the smallest one from right-sub-tree and replace this node,delete node.
    else if((NULL!=dst_node->left_child)&&(NULL!=dst_node->right_child))
    {
        two_child_case(dst_father_node,dst_node);
    }
    return -1;
}



/*In conclusion:
**There is four cases at the time delete node.
**1.the node has not any child.
**
*/
s32 SearchBiTree::delete_node(SearchTreeNode* root,u32 value)
{
    SearchTreeNode *p=root,*q=root;
    while(NULL!=p)
    {
        if(value>p->value)
        {
            q=p;
            p=p->right_child;
        }
        else if(value==p->value)           //find the node.p is the dst node,q is the father node of p;
        {
            //cout<<"dst father node is"<<q->value<<endl<<"dst node is"<<p->value<<endl;
            delete_node_in_different_situation(q,p);
            return 0;
        }
        else
        {
            q=p;
            p=p->left_child;
        }
    }
    return -1;
}



int main()
{
    u32 data[30]={15,8,4,2,22,26,28,1,3,5,6,7,9,10,11,12,13,14,16,17,18,19,20,21,23,24,25,27,29,30};
    SearchBiTree SBT;
    SearchTreeNode* root;
    SearchTreeNode* found;

    root=SBT.create_tree(data[0]);
    for(int i=1;i<30;i++)
    {
        SBT.insert_node(root,data[i]);
    }
    SBT.level_traversal(root);
    cout<<endl;
    // SBT.preorder_traversal(root);
    // cout<<endl;
    found=SBT.find_node(root,12);
    if(found!=NULL)
        cout<<"find node value="<<found->value<<endl;
    SBT.delete_node(root,1);
    
    cout<<"after delete:"<<endl;
    SBT.level_traversal(root);
    cout<<endl;
    // SBT.preorder_traversal(root);
    // cout<<endl;
    
}

