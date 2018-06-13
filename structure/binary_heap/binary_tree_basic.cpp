#include "binary_tree_basic.h"
#include "queue.h"



template<class NODE_TYPE>
template<typename T>
void BinaryTree<NODE_TYPE>::print_node_value(T value)
{
	cout<<value<<"  ";
}


template<class NODE_TYPE>
BinaryTree<NODE_TYPE>::BinaryTree()
{
	root=NULL;
}


/*destroy the tree.
**
*/
template<class NODE_TYPE>
BinaryTree<NODE_TYPE>::~BinaryTree()
{
	destroy_tree(root);
}



/*
post order traversal way to delete node one by one.
*/
template<class NODE_TYPE>
s32 BinaryTree<NODE_TYPE>::destroy_tree(NODE_TYPE *root)
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



/*Create a binary tree and get the root,So that it can destroy the tree automatically when class call destructor function. 
**
*/
template<class NODE_TYPE>
NODE_TYPE* BinaryTree<NODE_TYPE>::create_tree()
{
	root=create_tree_preorder();
	return root;
}


/*Create tree from user input node elem.
**
*/
template<class NODE_TYPE>
NODE_TYPE* BinaryTree<NODE_TYPE>::create_tree_preorder()
{
	NODE_TYPE* root;
	char c;
	cin>>c;
	if('!'==c)
	{
		return NULL;
	}
	root=new NODE_TYPE;
	root->value=c;
	
	root->left_child=create_tree_preorder();
	root->right_child=create_tree_preorder();
	
	return root;
}

/*Get tree root.
**
*/
template<class NODE_TYPE>
NODE_TYPE* BinaryTree<NODE_TYPE>::get_root()
{
	return root;
}



/*Traversal the tree in the way of preorder.
**
*/
template<class NODE_TYPE>
s32 BinaryTree<NODE_TYPE>::preorder_traversal(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return -1;
	}
	print_node_value(root->value-0x30);
	
	preorder_traversal(root->left_child);
	preorder_traversal(root->right_child);
	return 0;
}


/*Traversal the tree in the way of middle order.
**
*/
template<class NODE_TYPE>
s32 BinaryTree<NODE_TYPE>::middle_order_traversal(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return -1;
	}
	middle_order_traversal(root->left_child);
	print_node_value(root->value-0x30);
	middle_order_traversal(root->right_child);
	return 0;
}

/*Traversal the tree in the way of post order.
**
*/
template<class NODE_TYPE>
s32 BinaryTree<NODE_TYPE>::post_order_traversal(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return -1;
	}
	post_order_traversal(root->left_child);
	post_order_traversal(root->right_child);
	print_node_value(root->value-0x30);
	return 0;
	
}

/*Traversal the tree in the way of level.
**Implementation:1.Push the root into queue,
**				 2.pop queue node,print node.Push two of child nodes into the queue if child node != NULL.
**				 3.Perform step 2 till queue is empty.
**
**The queue value is a pointer to binary node.
*/
template<class NODE_TYPE>
s32 BinaryTree<NODE_TYPE>::level_traversal(NODE_TYPE *root)
{

	if(NULL==root)
	{
		return -1;
	}

	NODE_TYPE *start_node;
	u32 level_flag=0;

	QUEUE_ELEM_TYPE elem;
	QUEUE queue;
	queue.push(root);

	while(-1!=queue.pop(elem))
	{
		if(level_flag)   //level flag = 1
		{
			if(start_node==elem)
			{
				cout<<endl;
				level_flag=0;
			}
		}
		if(NULL!=(elem->left_child))
		{	
			
			if(!level_flag)
			{
				start_node=elem->left_child;
				level_flag=1;
			}
			
			queue.push(elem->left_child);	
		}
		if(NULL!=(elem->right_child))
		{
			if(!level_flag)
			{
				start_node=elem->right_child;
				level_flag=1;
			}
			
			queue.push(elem->right_child);
		}
		print_node_value(elem->value-0x30);
	}
	return 0;
}

// /*Traversal the tree in the way of level.
// **Implementation:1.Push the root into queue,
// **				 2.pop queue node,print node.Push two of child nodes into the queue if child node != NULL.
// **				 3.Perform step 2 till queue is empty.
// **
// **The queue value is a pointer to binary node.
// */
// s32 BinaryTree::level_traversal(NODE_TYPE *root)
// {

// 	if(NULL==root)
// 	{
// 		return -1;
// 	}

// 	QUEUE_ELEM_TYPE elem;
// 	QUEUE queue;
// 	queue.push(root);

// 	while(-1!=queue.pop(elem))
// 	{
// 		if(NULL!=(elem->left_child))
// 		{
// 			queue.push(elem->left_child);	
// 		}
// 		if(NULL!=(elem->right_child))
// 		{
// 			queue.push(elem->right_child);
// 		}
// 		print_node_value(elem->value-0x30);
// 	}
// 	return 0;
// }

/*Get the height of tree.
**In the way of post order traversal,treat each subtree as a separate tree,get subtree's height recursively.
*/
template<class NODE_TYPE>
u32 BinaryTree<NODE_TYPE>::get_height_of_tree(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return 0;
	}
	u32 left_height=get_height_of_tree(root->left_child);
	u32 right_height=get_height_of_tree(root->right_child);
	return left_height>right_height?left_height+1:right_height+1;
}


/*Get all leaves counts.Leaf definition:the node without any subnode.
*/
template<class NODE_TYPE>
u32 BinaryTree<NODE_TYPE>::leaves_counts(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return 0;
	}
	if((NULL==root->left_child) && (NULL==root->right_child))
	{
		return 1;
	}
	u32 left_counts=leaves_counts(root->left_child);
	u32 right_counts=leaves_counts(root->right_child);
	return left_counts+right_counts;
}


/*Get all nodes counts. 
**
*/
template<class NODE_TYPE>
u32 BinaryTree<NODE_TYPE>::nodes_counts(NODE_TYPE *root)
{
	if(NULL==root)
	{
		return 0;
	}
	u32 left_counts=nodes_counts(root->left_child);
	u32 right_counts=nodes_counts(root->right_child);
	return left_counts+right_counts+1;
}


/*Get nth level nodes.Root is level 0,and so on.
**if the level deeper than depth of tree,return 0;
*/
template<class NODE_TYPE>
u32 BinaryTree<NODE_TYPE>::get_level_nodes(NODE_TYPE *root,u32 level)
{
	if((NULL==root)||(level<0))
	{
		return 0;
	}
	if(0==level)
	{
		return 1;
	}
	u32 left_node_counts=get_level_nodes(root->left_child,level-1);
	u32 right_node_counts=get_level_nodes(root->right_child,level-1);
	return right_node_counts+left_node_counts;
}





#ifdef BITREE_DEBUG

int main()
{
	u32 height=0;
	u32 node_cts=0;
	u32 leaf_couts=0;
	u32 level_node_counts=0;
	TREE_NODE* head; 

	BinaryTree<TREE_NODE> BT;
	head=BT.create_tree();
	
	BT.preorder_traversal(head);
	cout<<endl;
	BT.middle_order_traversal(head);
	cout<<endl;
	BT.post_order_traversal(head);
	cout<<endl;
	BT.level_traversal(head);
	cout<<endl;

	height=BT.get_height_of_tree(head);
	cout<<"height="<<height<<endl;

	node_cts=BT.nodes_counts(head);
	cout<<"nodes counts="<<node_cts<<endl;

	leaf_couts=BT.leaves_counts(head);
	cout<<"leaf counts="<<leaf_couts<<endl;

	level_node_counts=BT.get_level_nodes(head,0);
	cout<<"level node counts="<<level_node_counts<<endl;

	level_node_counts=BT.get_level_nodes(head,1);
	cout<<"level node counts="<<level_node_counts<<endl;

	level_node_counts=BT.get_level_nodes(head,2);
	cout<<"level node counts="<<level_node_counts<<endl;

	level_node_counts=BT.get_level_nodes(head,3);
	cout<<"level node counts="<<level_node_counts<<endl;

	level_node_counts=BT.get_level_nodes(head,4);
	cout<<"level node counts="<<level_node_counts<<endl;
	return 0;
}

#endif

