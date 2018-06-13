#include "binary_heap.h"



BiHeap::~BiHeap()
{
    destroy_tree(root);
}

BiHeap::BiHeap()
{
    node_num=0;
    root=NULL;
}


/*
post order traversal way to delete node one by one.
*/
s32 BiHeap::destroy_tree(BITREE_NODE *root)
{
	if(NULL==root)
	{	
		return -1;
	}
	
	destroy_tree(root->left_child);
	
	destroy_tree(root->right_child);
	
	delete root;

	root=NULL;
	
	return 0;
}




BITREE_NODE* BiHeap::create_tree(ELEM_TYPE value)
{
    root=create_null_tree(value);
    return root;
}

BITREE_NODE* BiHeap::create_null_tree(ELEM_TYPE value)
{
	BITREE_NODE* root=new BITREE_NODE;
	root->value=value;
	root->left_child=NULL;
	root->right_child=NULL;
    node_num++;
	return root;
}


/*Binary heap is a complete binary tree,insert a node to bi-heap.
**insert node in the way of level_traversal.
*/
s32 BiHeap::insert_node(BITREE_NODE* root,ELEM_TYPE value)
{
    QUEUE queue;
    BITREE_NODE* tmp;

    if(NULL==root)
    {
        return -1;
    }

    BITREE_NODE* node =new BITREE_NODE;
    node->left_child=NULL;
    node->right_child=NULL;
    node->value=value;

    queue.push(root);
    while(-1!=queue.pop(tmp))
    {
        if(NULL!=tmp->left_child)
        {
            queue.push(tmp->left_child);
        }
        else
        {
            tmp->left_child=node;
            node_num++;
            return 0;
        }
        if(NULL!=tmp->right_child)
        {
            queue.push(tmp->right_child);
        }
        else
        {
            tmp->right_child=node;
            node_num++;
            return 0;
        }
    }
}


s32 BiHeap::adjust_node(BITREE_NODE* root)
{

}



/*Delete the root,cause it's a big root binary heap.
**
*/
s32 BiHeap::delete_node(BITREE_NODE* root)
{
    
}


#ifdef BINARY_HEAP_DEBUG


int main()
{
    BITREE_NODE* root;
    BiHeap BH;
    u32 level_node_counts=0;
    root=BH.create_tree(0x31);
    BH.insert_node(root,0x32);
    BH.insert_node(root,0x33);
    BH.insert_node(root,0x34);
    BH.insert_node(root,0x35);
    BH.insert_node(root,0x36);
    BH.insert_node(root,0x37);
    BH.insert_node(root,0x38);
    BH.insert_node(root,0x39);

    BH.level_traversal(root);
    cout<<endl;

    BH.post_order_traversal(root);
    cout<<endl;

    // level_node_counts=BH.get_level_nodes(root,0);
	// cout<<"level node counts="<<level_node_counts<<endl;

	// level_node_counts=BH.get_level_nodes(root,1);
	// cout<<"level node counts="<<level_node_counts<<endl;

	// level_node_counts=BH.get_level_nodes(root,2);
	// cout<<"level node counts="<<level_node_counts<<endl;

	// level_node_counts=BH.get_level_nodes(root,3);
	// cout<<"level node counts="<<level_node_counts<<endl;
    return 0;
}

#endif