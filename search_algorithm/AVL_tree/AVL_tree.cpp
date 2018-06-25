#include "AVL_tree.h"


AVLTree::AVLTree()
{

}


AVLTree::~AVLTree()
{
    destroy_tree(root);
}






AVLTreeNode* AVLTree::create_tree(u32 value)
{
    root=new AVLTreeNode;
    root->height=1;
    root->bf=EH;
    root->value=value;
    root->left_child=NULL;
    root->right_child=NULL;
    return root;
}


/*Check banlance.If the node's left_child and right_child differ by 2,need to adjust.*/
s32 AVLTree::check_balance(AVLTreeNode* node)
{
    u32 left_height=0;
    u32 right_height=0;

    left_height=get_height(node->left_child);
    
    right_height=get_height(node->right_child);
    
    if(abs(left_height-right_height)>=2)
    {
        return UNBALANCED;
    }
    return BALANCED;
}

s32 AVLTree::balance_tree_operation(AVLTreeNode* node)
{
    if(get_height(node->left_child)>get_height(node->right_child))
    {
        //case LL
        if(get_height(node->left_child->left_child) >= get_height(node->left_child->right_child))
        {
            R_rotation(node);
        }
        //case LR
        else
        {
            LR_TO_LL_rotation(node->left_child);
            R_rotation(node);
        }
    }
    else
    {
        //case RR
        if(get_height(node->right_child->right_child) >= get_height(node->right_child->left_child))
        {
            L_rotation(node);
        }
        //case RL
        else
        {
            RL_TO_RR_rotation(node->right_child);
            L_rotation(node);
        }
    }
}


/*Get height of node*/
s32 AVLTree::get_height(AVLTreeNode* node)
{
    if(NULL==node)
    {
        return 0;
    }
    return node->height;
}



/*We should re-calculate the height of tree after insert/delete/rotation..,the way is the higher child's height +1*/
s32 AVLTree::set_height(AVLTreeNode* node)
{
    u32 left_height=0;
    u32 right_height=0;

    left_height=get_height(node->left_child);
    right_height=get_height(node->right_child);

    node->height=left_height>right_height?left_height+1:right_height+1;
}



/**     local rotation.The bf of node A and node C will be changed after.
**      explanation:After local left-rotation graph(1) turns to graph(2)
**                  exchange the contents of node A and node C.In this way can we keep the link of the father node,
**                  otherwise need to change the father's child pointer.
**      The node N is NULL;
**      case1:node B,D,E are NULL;bf of A becomes LH,bf of C becomes EH.
**      case2:node E is NULL;bf of A becomes LH+LH,bf of C becomes EH
**      case3:node D is NULL;bf of A becomes LH,bf of C becomes LH
**      However,The bf of A will be changed again,so we can not set it.         
**                A            C            A
**               / \          / \          / \ 
**              B   C  ==>   A   E    ==> C   E
**                 / \      / \          / \
**                D   E    B   D        B   D
**              (1)           (2)           (3)
**
*/
void AVLTree::LR_TO_LL_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp_r=node->right_child;    //record right_child
    AVLTreeNode* temp_rl=node->right_child->left_child;   //record right_child's left_child

    temp_r->left_child=node;          
    node->right_child=temp_rl;

    /*The top node is node->right_child after rotation,but the node's father still point to node.
      So we should move the node to the top position.*/
    swap_two_node_value(temp_r,node);
    node->left_child=temp_r;

    set_height(node->left_child);
    set_height(node);
}



/**     local rotation.The bf of node A and node B will be changed after.
**      explanation:After local right-rotation graph(1) turns to graph(2)
**                  exchange the contents of node A and node B.In this way can we keep the link of the father node,
**                  otherwise need to change the father's child pointer.
**      The node N is NULL;
**      case1:node C,D,E are NULL;bf of A becomes RH,bf of B becomes EH.
**      case2:node D is NULL;bf of A becomes RH+RH,bf of B becomes EH
**      case3:node E is NULL;bf of A becomes RH,bf of B becomes RH
**      case4:all node is valid.bf of A becomes RH,bf of B becomes EH.
**      However,The bf of A will be changed again,so we can not set it.         
**                A            B            A
**               / \          / \          / \ 
**              B   C  ==>   D   A    ==> D   B
**             / \              / \          / \
**            D   E            E   C        E   C
**              (1)           (2)          (3)
**
*/
void AVLTree::RL_TO_RR_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp_l=node->left_child;
    AVLTreeNode* temp_lr=node->left_child->right_child;

    temp_l->right_child=node;
    node->left_child=temp_lr;
    //cout<<"hehehe"<<endl;
    /*The top node is node->left_child after rotation,but the node's father still point to node.
      So we should move the node to the top position.*/
    swap_two_node_value(temp_l,node);

    node->right_child=temp_l;

    set_height(node->right_child);
    set_height(node);

    // cout<<node->right_child->height<<endl;
    // cout<<node->height<<endl;
}


/**     After local rotation or not,the case only are:LL or RR
**      explanation:After left-rotation graph(1) turns to graph(2)
**      exchange the contents of node A and node B.In this way can we keep the link of the father node,
**      otherwise need to change the father's child pointer.
**      The node N is NULL;
**      case1:node F and G are NULL,bf of A is EH,bf of C is EH;
**      case2:node F|G don't equal to NULL,bf of A is LH,bf of C is RH.
**      case3:node B F G H are NULL,bf of A is LH,bf of C is RH.
**      case4:node B D F G H are NULL,bf of A is EH,bf of C is EH.
**
**
**           A                      C                       A
**          / \                    / \                     / \
**         B   C                  A   E                   C   E
**            / \     ==>        / \   \       ==>       / \   \
**           D   E              B   D   H               B   D   H
**          / \   \                / \                     / \
**         F   G   H              F   G                   F   G
**         (1)                     (2)                     (3)
**/
void AVLTree::L_rotation(AVLTreeNode* node)   
{
    AVLTreeNode* temp=node->right_child->left_child;
    AVLTreeNode* swap_temp=node->right_child;

    node->right_child->left_child=node;
    node->right_child=temp;

    swap_two_node_value(swap_temp,node);
    node->left_child=swap_temp;

    // if(node->left_child->right_child->left_child||node->left_child->right_child->right_child)
    // {
    //     node->bf=LH;
    //     node->right_child->bf=RH;
    // }
    // else
    // {
    //     node->bf=node->left_child->bf=EH;
    // }
    set_height(node->left_child);
    set_height(node);
}



/**     After local rotation or not,the case only are:LL or RR
**      explanation:After right-rotation graph(1) turns to graph(2)
**      exchange the contents of node A and node B.In this way can we keep the link of the father node,
**      otherwise need to change the father's child pointer.
**      The node N is NULL;
**      case1:node G and H are NULL,bf of A is EH,bf of B is EH;
**      case2:node G|H don't equal to NULL,bf of A is RH,bf of B is LH.
**      case3:node C F G H are NULL,bf of A is RH,bf of B is LH.
**      case4:node C E F G H are NULL,bf of A is EH,bf of B is EH.
**
**
**           A                      B                       A
**          / \                    / \                     / \
**         B   C                  D   A                   D   B
**        / \     ==>            /   / \          ==>    /   / \  
**       D   E                  F   E   C               F   E   C
**      /   / \                    / \                     / \
**     F   G   H                  G   H                   G   H
**         (1)                     (2)                     (3)
**/
void AVLTree::R_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp=node->left_child->right_child;

    AVLTreeNode* swap_temp=node->left_child;

    node->left_child->right_child=node;
    node->left_child=temp;

    swap_two_node_value(swap_temp,node);
    node->right_child=swap_temp;

    set_height(node->right_child);
    set_height(node);
}


void AVLTree::LL_rotation(AVLTreeNode* node)
{
    R_rotation(node);
}


void AVLTree::LR_rotation(AVLTreeNode* node)
{
    LR_TO_LL_rotation(node->left_child);
    R_rotation(node); 
}

void AVLTree::RL_rotation(AVLTreeNode* node)
{
    RL_TO_RR_rotation(node->right_child);
    //cout<<"f node value="<<node->right_child->value<<"   "<<node->right_child->right_child->value<<endl;
    L_rotation(node);
}

void AVLTree::RR_rotation(AVLTreeNode* node)
{
    L_rotation(node);
}



s32 AVLTree::left_rotation(AVLTreeNode* node)
{
    if(node->right_child->bf>0)  //case1 : RL
    {
        //cout<<"rl"<<endl;
        RL_rotation(node);
    }
    else if(node->right_child->bf<=0) //case2 :RR
    {
        RR_rotation(node);
    }
    else
    {
        cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }    
    return 0;
}


s32 AVLTree::right_rotation(AVLTreeNode* node)
{
    //cout<<"root value ="<<root->value<<endl;
    if(node->left_child->bf>=0)  //case1 : LL
    {   
        LL_rotation(node);
    }
    else if(node->left_child->bf<0)  //case2: LR
    {
        LR_rotation(node);
    }
    else
    {
        //cout<<"value="<<node->value<<endl;
        cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }
}


s32 AVLTree::insert_node(AVLTreeNode* root,AVLTreeNode* node)
{
    //Alone the right path.
    if(node->value>root->value)
    {
        if(NULL!=root->right_child)
        {
            insert_node(root->right_child,node);
            set_height(root);
            if(UNBALANCED==check_balance(root))
            {
                balance_tree_operation(root);
            }
        }
        else
        {
            root->height+=1;
            root->right_child=node;
        }
    }
    //Alone the left path.
    else if(node->value<root->value)
    {
        if(NULL!=root->left_child)
        {
            insert_node(root->left_child,node);
            set_height(root);
            if(UNBALANCED==check_balance(root))
            {
                balance_tree_operation(root);
            }
        }
        else
        {
            root->left_child=node;
            root->height+=1;
        }
    }
    else
    {
        cout<<"Not support same vlaue"<<endl;
        return -1;
    }
    return 0;
}


s32 AVLTree::insert_node(AVLTreeNode* root,u32 value)
{
    s32 ret=0;
    AVLTreeNode* temp=new AVLTreeNode;
    temp->value=value;
    temp->left_child=NULL;
    temp->right_child=NULL;
    temp->height=1;
    temp->bf=EH;

    insert_node(root,temp);

    return 0;
}



/**/
AVLTreeNode* AVLTree::find_smallest_from_sub_right(AVLTreeNode* father,AVLTreeNode* root)
{
    AVLTreeNode* temp;
    if(NULL!=root->left_child)
    {
        temp=find_smallest_from_sub_right(root,root->left_child);
        set_height(root);
        return temp;
    }
    else
    {
        if(father->left_child==root)
        {
            father->left_child=NULL;
        }
        else if(father->right_child==root)
        {
            father->right_child=NULL;
        }
        return root;
    }
}










s32 AVLTree::delete_node(AVLTreeNode* root,u32 value,del_stat_t& stat)
{
    AVLTreeNode* temp;
    AVLTreeNode* replace_node;
    if(NULL==root)
    {
        cout<<"ERROR::can't find node!!!"<<endl;
        stat=NOT_CHANGE;
        return -1;
    }
    if(root->value>value)
    {
        delete_node(root->left_child,value,stat);
        //root is father of the node to be deleted.
        if(DELETE_ONE_CHILD==stat)
        {
            temp=root->left_child;
            //Only right child or no child
            if(NULL==temp->left_child)
            {
                root->left_child=temp->right_child;
            }
            //Only left child
            else if(NULL==temp->right_child)
            {
                root->left_child=temp->left_child;
            }

            stat=NOT_CHANGE;
            delete temp;
        }
        //root is father of the node which to be deleted.
        else if(DELETE_TWO_CHILD==stat)
        {
            temp=root->left_child;
            //find the replace node.
            replace_node=find_smallest_from_sub_right(temp,temp->right_child);

            if(replace_node==temp->right_child)
            {
                replace_node->right_child=temp->right_child->right_child;
            }
            else
            {
                replace_node->right_child=temp->right_child;
            }
            replace_node->left_child=temp->left_child;
            root->left_child=replace_node;

            set_height(replace_node);

            stat=NOT_CHANGE;
            delete temp;
        }
        else
        {

        }
        set_height(root);
        if(UNBALANCED==check_balance(root))
        {
            balance_tree_operation(root);
        }
    }
    else if(root->value<value)
    {
        delete_node(root->right_child,value,stat);
        if(DELETE_ONE_CHILD==stat)
        {
            temp=root->right_child;
            if(NULL==temp->left_child)
            {
                root->right_child=temp->right_child;
            }
            //Only left child
            else if(NULL==temp->right_child)
            {
                root->right_child=temp->left_child;
            }
            stat=NOT_CHANGE;
            delete temp;
        }
        else if(DELETE_TWO_CHILD==stat)
        {
            //record the node need to be deleted.
            temp=root->right_child;
            //find the replace node.
            replace_node=find_smallest_from_sub_right(temp,temp->right_child);

            if(replace_node==temp->right_child)
            {
                replace_node->right_child=temp->right_child->right_child;
            }
            else
            {
                replace_node->right_child=temp->right_child;
            }
            replace_node->left_child=temp->left_child;
            root->right_child=replace_node;

            set_height(replace_node);

            stat=NOT_CHANGE;
            delete temp;
        }
        else
        {
            
        }
        set_height(root);
        if(UNBALANCED==check_balance(root))
        {
            balance_tree_operation(root);
        }
    }
    else
    {
        /*the root node need to deleted.*/
        /*the swap node is the smallest node in sub-right tree.*/
        if((NULL==root->left_child)||(NULL==root->right_child))
        {
            stat=DELETE_ONE_CHILD;
        }
        else
        {
            //AVLTreeNode* swap_node=find_smallest_from_sub_right(root->right_child,opt_stat);
            stat=DELETE_TWO_CHILD;
        }
    }
}

AVLTreeNode* AVLTree::find_node(AVLTreeNode* root,u32 value)
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





/*Swap two nodes' value*/
void AVLTree::swap_two_node_value(AVLTreeNode*& node1,AVLTreeNode*& node2)
{
    AVLTreeNode temp;
    memcpy(&temp,node1,sizeof(AVLTreeNode));
    memcpy(node1,node2,sizeof(AVLTreeNode));
    memcpy(node2,&temp,sizeof(AVLTreeNode));
}







int main(int argc,char *argv[])
{
    del_stat_t stat;
    char str[50];
    u32 c;
    AVLTree AVL;
    AVLTreeNode* root;
    //root=AVL.create_tree(13);
    u32 data[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //u32 data[]={13,19,5,17,16,10,14,20,12,11,15,9,8,7,6,18,4,2,3,1,36,38,23,24,25,29,27,40,26,30,34,32,33,31,35,21,37,22,39,28};
    // u32 data[]={13,51,19,52,5,50,17,48,53,16,49,10,14,46,20,54,47,55,12,11,56,44,45,15,9,8
    //             ,43,7,6,18,4,2,3,42,1,36,38,57,23,41,24,58,25,59,29,60,27,40,26,30,34,32,33,31,35,21,37,22,39,28};
    // while(cin>>c)
    // {
    //     //cout<<c<<endl;    //     AVL.insert_node(root,c);
    //     cout<<"new tree ="<<endl;;
    //     AVL.level_traversal(root);
    //     cout<<endl;
    //     cout<<endl;
    // }
    root=AVL.create_tree(data[0]);
    for(int i=1;i<20;i++)
    {
        AVL.insert_node(root,data[i]);
    }

    AVL.level_traversal(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    // cout<<root->value<<" "<<root->bf<<endl;
    // cout<<root->left_child->value<<" "<<root->left_child->bf<<endl;
    // cout<<root->right_child->value<<" "<<root->right_child->bf<<endl;
    //AVL.delete_node(root,5,stat);
     AVL.delete_node(root,2,stat);
     AVL.delete_node(root,18,stat);
    //  AVL.delete_node(root,3,stat);
    //  AVL.delete_node(root,5,stat);
    //  AVL.delete_node(root,7,stat);
    //  AVL.delete_node(root,20,stat);
    //  AVL.delete_node(root,17,stat);
    //  AVL.delete_node(root,19,stat);
    //  AVL.delete_node(root,18,stat);
    //cout<<"stat="<<stat<<endl;
    //AVL.insert_node(root,data[3]);
    AVL.level_traversal(root);
    cout<<endl;
    //AVL.preorder_traversal(root);
    //cout<<endl;
}
