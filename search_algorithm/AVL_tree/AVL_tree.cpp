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
    root->height=0;
    root->bf=EH;
    root->value=value;
    root->left_child=NULL;
    root->right_child=NULL;
    return root;
}


void AVLTree::LR_TO_LL_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp=node->right_child;   

    node->right_child->left_child=node;          
    node->right_child=NULL;

    /*The top node is node->right_child after rotation,but the node's father still point to node.
      So we should move the node to the top position.*/
    swap_two_node_value(temp,node);
    node->left_child=temp;

    if(NULL==node->right_child)
    {
        node->bf=LH;
        node->left_child->bf=EH;
    }   
    else
    {
        node->bf=LH;
        node->left_child->bf=LH;
    }
}

void AVLTree::RL_TO_RR_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp=node->left_child;

    node->left_child->right_child=node;
    node->left_child=NULL;
    //cout<<"hehehe"<<endl;
    /*The top node is node->left_child after rotation,but the node's father still point to node.
      So we should move the node to the top position.*/
    swap_two_node_value(temp,node);

    node->right_child=temp;

    if(NULL==node->left_child)
    {
        node->bf=RH;
        node->right_child->bf=EH;
    }
    else
    {
        node->bf=RH;
        node->right_child->bf=RH;
    }
}


/*case RR rotation*/
void AVLTree::L_rotation(AVLTreeNode* node)   
{
    AVLTreeNode* temp=node->right_child->left_child;
    AVLTreeNode* swap_temp=node->right_child;

    node->right_child->left_child=node;
    node->right_child=temp;

    swap_two_node_value(swap_temp,node);
    node->left_child=swap_temp;

    node->bf=node->left_child->bf=0;
}

/*case LL rotation*/
void AVLTree::R_rotation(AVLTreeNode* node)
{
    AVLTreeNode* temp=node->left_child->right_child;

    AVLTreeNode* swap_temp=node->left_child;

    node->left_child->right_child=node;
    node->left_child=temp;

    swap_two_node_value(swap_temp,node);
    node->right_child=swap_temp;

    node->bf=node->right_child->bf=0;
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



s32 AVLTree::insert_node(AVLTreeNode* root,AVLTreeNode* node,opr_stat_t& opr_stat)
{
    if(node->value>root->value)
    {
        if(NULL!=root->right_child)
        {
            /*Call insert_node recursively*/
            insert_node(root->right_child,node,opr_stat);
            switch(root->bf)
            {
                /*If current node'bf is LH(left-subtree-height - right-subtree-height=1)*/
                case LH:
                    /*If the inserted node increases the tree,according to **if(NULL!=root->right_child)** above .right sub-tree grown one,so LH+RH=EH*/
                    if(GROWN==opr_stat)
                    {
                        root->bf=EH;
                        opr_stat=NOT_CHANGED;
                    }
                break;
                case RH:
                    /*If the inserted node increases the tree,according to **if(NULL!=root->right_child)** above .right sub-tree grown one,so RH+RH=-2,need to rotate*/
                    /*Current node's bf turns EH after rotating,the height of tree has not grown anymore.*/
                    if(GROWN==opr_stat)
                    {
                        //cout<<"hear"<<endl;
                        left_rotation(root);
                        //cout<<"value="<<root->value<<endl;
                        root->bf=EH;
                        opr_stat=NOT_CHANGED;
                    }
                break;
                /*If the inserted node increases the tree,according to **if(NULL!=root->right_child)** above .right sub-tree grown one,so EH+RH=RH*/
                case EH:
                    if(GROWN==opr_stat)
                    {
                        root->bf=RH;
                        //opr_stat=NOT_CHANGED;
                    }
                break;
                default:break;
            }
        }
        /*Find a null node,insert node.Use opr_stat indicate that whether the height of tree was grown.*/
        /*Set the variable bf of inserted node's father node.*/
        /*And combine above to determine the balance factor along recursive path nodes,if unbalanced,rotation tree.*/
        else
        {
            root->right_child=node;
            if(root->left_child==NULL)
            {
                root->bf=RH;
                opr_stat=GROWN;
                return 0;
            }
            else
            {
                root->bf=EH;
                opr_stat=NOT_CHANGED;
                return 0;
            }
        }
    }
    else if(node->value<root->value)
    {

        if(NULL!=root->left_child)
        {
            insert_node(root->left_child,node,opr_stat);
            switch(root->bf)
            {
                /*If current node'bf is LH(left-subtree-height - right-subtree-height=1)*/
                case LH:
                /*If the inserted node increases the tree,according to **if(NULL!=root->left_child)** above .left sub-tree grown one,so LH+LH=2,need to rotate.*/
                    /*Current node's bf turns EH after rotating,the height of tree has not grown anymore.*/
                    if(GROWN==opr_stat)
                    {
                        right_rotation(root);
                        root->bf=EH;
                        opr_stat=NOT_CHANGED;
                    }
                break;
                case RH:
                    if(GROWN==opr_stat)
                    {
                        root->bf=EH;
                        opr_stat=NOT_CHANGED;
                    }
                break;
                case EH:
                    if(GROWN==opr_stat)
                    {
                        root->bf=LH;
                        //opr_stat=NOT_CHANGED;
                    }
                break;
                default:break;
            }
        }
        else
        {
            /*Find a null node,insert node.Use opr_stat indicate that whether the height of tree was grown.*/
        /*Set the variable bf of inserted node's father node.*/
        /*And combine above to determine the balance factor along recursive path nodes,if unbalanced,rotation tree.*/
            root->left_child=node;
            
            if(root->right_child==NULL)
            {
                root->bf=LH;
                opr_stat=GROWN;
                //cout<<"insert"<<endl;
                return 0;
            }
            else
            {
                root->bf=EH;
                opr_stat=NOT_CHANGED;
                return 0;
            }
        }
    }
    else
    {
        opr_stat=NOT_CHANGED;
        cout<<"Not support same vlaue"<<endl;
        return -1;
    }
    return 0;
}



s32 AVLTree::insert_node(AVLTreeNode* root,u32 value)
{
    s32 ret=0;
    opr_stat_t stat=NOT_CHANGED;
    AVLTreeNode* temp=new AVLTreeNode;
    temp->value=value;
    temp->left_child=NULL;
    temp->right_child=NULL;
    temp->height=0;
    temp->bf=EH;

    insert_node(root,temp,stat);

    return 0;
}



/**/
AVLTreeNode* AVLTree::find_smallest_from_sub_right(AVLTreeNode* root,del_stat_t& opt_stat)
{
    if(NULL!=root->left_child)
    {
        find_smallest_from_sub_right(root->left_child,opt_stat);
    }
    else
    {

        return root;
    }
}


/*The param node is the father of need to be deleted node.*/
/*The param side the node need to be deleted is on the left/right sub tree.*/
void AVLTree::delete_no_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat)
{
    if(LEFT==side)
    {
        /*If the node need to be deleted has not brother,the height shorten.*/
        if(NULL==node->right_child)
        {
            node->bf=EH;
            opt_stat=SHORTEN;

            delete node->left_child;
            node->left_child=NULL;
        }
        /*If the node need to be deleted has brother,the height not changed.*/
        else
        {
            /*delete left,left-height - right-height =RH*/
            node->bf=RH;
            opt_stat=NOT_CHANGE;
            delete node->left_child;
            node->left_child=NULL;
        }
    }
    else if(RIGHT==side)
    {
        if(NULL==node->left_child)
        {
            cout<<"no left"<<endl;
            node->bf=EH;
            opt_stat=SHORTEN;
            delete node->right_child;
            node->right_child=NULL;
        }
        else
        {
            node->bf=LH;
            opt_stat=NOT_CHANGE;
            delete node->right_child;
            node->right_child=NULL;
        }
    }
    else
    {
         cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }
}

/*The param node is the father of need to be deleted node.*/
/*The param side the node need to be deleted is on the left/right sub tree.*/
void AVLTree::delete_only_left_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat)
{
    AVLTreeNode* temp;
    if(LEFT==side)
    {
        temp=node->left_child;
        node->left_child=node->left_child->left_child;
        /*According to characteristic,if the deleted node has noly left_child,it must has a brother.*/
        node->bf=EH;
        delete temp;
        opt_stat=SHORTEN;
    }
    else if(RIGHT==side)
    {
        temp=node->right_child;
        node->right_child=node->right_child->left_child;
        /*According to characteristic,if the deleted node has noly left_child,it must has a brother.*/
        node->bf=EH;
        delete temp;
        opt_stat=SHORTEN;
    }
    else
    {
        cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }
}




void AVLTree::delete_only_right_child(AVLTreeNode* node,side_t side,del_stat_t& opt_stat)
{
    AVLTreeNode* temp;
    if(LEFT==side)
    {
        temp=node->left_child;
        node->left_child=node->left_child->right_child;
        /*According to characteristic,if the deleted node has noly left_child,it must has a brother.*/
        node->bf=EH;
        delete temp;
        opt_stat=SHORTEN;
    }
    else if(RIGHT==side)
    {
        temp=node->right_child;
        node->right_child=node->right_child->right_child;
        /*According to characteristic,if the deleted node has noly left_child,it must has a brother.*/
        node->bf=EH;
        delete temp;
        opt_stat=SHORTEN;
    }
    else
    {
        cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }
}


void AVLTree::sub_tree_shorten(AVLTreeNode* node,side_t side,del_stat_t& opt_stat)
{
    /*The left sub tree has shorten*/
    if(LEFT==side)
    {
        //cout<<"delete"<<endl;
        
        switch(node->bf)
        {
            case LH:
            node->bf=EH;
            
            break;
            case EH:
            node->bf=LH;
            opt_stat=NOT_CHANGE;
            break;
            case RH:
            left_rotation(node);
            opt_stat=NOT_CHANGE;
            node->bf=EH;
            break;
            default:break;
        }
    }
    else if(RIGHT==side)
    {
        switch(node->bf)
        {
            case LH:
            right_rotation(node);
            opt_stat=NOT_CHANGE;
            node->bf=EH;
            break;
            case EH:
            node->bf=LH;
            opt_stat=NOT_CHANGE;
            break;
            case RH:            
            node->bf=EH;
            break;
            default:break;
        }
    }
    else
    {
        cout<<__FILE__<<"-"<<__LINE__<<"-"<<"error!"<<endl;
    }
}


s32 AVLTree::delete_node(AVLTreeNode* root,u32 value,del_stat_t& opt_stat)
{
    AVLTreeNode* temp;
    if(root->value>value)
    {
        delete_node(root->left_child,value,opt_stat);
        switch(opt_stat)
        {
            case DELETE_NO_CHILD:
            //cout<<root->value<<endl;
            delete_no_child(root,LEFT,opt_stat);
                break;
            /*delete the node,point the father's left_child pointer to left_child*/
            case DELETE_ONLY_LEFT_CHILD:
                delete_only_left_child(root,LEFT,opt_stat);
                break;
                /*delete the node,point the father's left_child pointer to right_child*/
            case DELETE_ONLY_RIGHT_CHILD:
                delete_only_right_child(root,LEFT,opt_stat);
                break;
            case NOT_CHANGE:
                break;
            case SHORTEN:
                sub_tree_shorten(root,LEFT,opt_stat);
                break;
            default:break;
        }
    }
    else if(root->value<value)
    {
        
        delete_node(root->right_child,value,opt_stat);
        switch(opt_stat)
        {
            case DELETE_NO_CHILD:
                //cout<<"f value "<<root->value<<endl;
                delete_no_child(root,RIGHT,opt_stat);
                break;
                /*delete the node,point the father's left_child pointer to left_child*/
            case DELETE_ONLY_LEFT_CHILD:
                delete_only_left_child(root,RIGHT,opt_stat);
                break;
                /*delete the node,point the father's left_child pointer to right_child*/
            case DELETE_ONLY_RIGHT_CHILD:
                delete_only_right_child(root,RIGHT,opt_stat);
                break;
            case NOT_CHANGE:
                break;
            case SHORTEN:
                sub_tree_shorten(root,RIGHT,opt_stat);
                break;
            default:break;
        }

    }
    else
    {
        /*the root node need to deleted.*/
        /*the swap node is the smallest node in sub-right tree.*/
        if((NULL==root->left_child)&&(NULL==root->right_child))
        {
            //cout<<"delete "<<root->value<<endl;
            opt_stat=DELETE_NO_CHILD;
        }
        else if((NULL!=root->left_child)&&(NULL==root->right_child))
        {
            opt_stat=DELETE_ONLY_LEFT_CHILD;
        }
        else if((NULL==root->left_child)&&(NULL!=root->right_child))
        {
            opt_stat=DELETE_ONLY_RIGHT_CHILD;
        }
        else
        {
            //AVLTreeNode* swap_node=find_smallest_from_sub_right(root->right_child,opt_stat);
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
    //u32 data[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    u32 data[]={13,19,5,17,16,10,14,20,12,11,15,9,8,7,6,18,4,2,3,1,36,38,23,24,25,29,27,40,26,30,34,32,33,31,35,21,37,22,39,28};
    // while(cin>>c)
    // {
    //     //cout<<c<<endl;
    //     AVL.insert_node(root,c);
    //     cout<<"new tree ="<<endl;;
    //     AVL.level_traversal(root);
    //     cout<<endl;
    //     cout<<endl;
    // }
    root=AVL.create_tree(data[0]);
    for(int i=1;i<23;i++)
    {
        AVL.insert_node(root,data[i]);
    }

    // cout<<root->value<<" "<<root->bf<<endl;
    // cout<<root->left_child->value<<" "<<root->left_child->bf<<endl;
    // cout<<root->right_child->value<<" "<<root->right_child->bf<<endl;
    //AVL.delete_node(root,5,stat);
    // AVL.delete_node(root,20,stat);
    // AVL.delete_node(root,18,stat);
    // AVL.delete_node(root,14,stat);
    // AVL.delete_node(root,16,stat);
    //AVL.delete_node(root,3,stat);
    //cout<<"stat="<<stat<<endl;
    //AVL.insert_node(root,data[3]);
    AVL.level_traversal(root);
    cout<<endl;
    //AVL.preorder_traversal(root);
    //cout<<endl;
}
