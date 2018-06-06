#include "binary.h"
#include "queue.h"
#include "stack.h"




#ifdef BITREE_TEST

int main()
{
	QUEUE<u32> queue;

	u32 height=0;
	u32 node_cts=0;
	u32 leaf_couts=0;
	u32 level_node_counts=0;

	TreeNode<ELEM_TYPE>* head;
	BinaryTree<TreeNode<ELEM_TYPE>> BT;

	 head=BT.create_tree();
	
	BT.preorder_traversal_nonRecursive(head);
	cout<<endl;
	BT.preorder_traversal(head);
	cout<<endl;
	BT.middle_order_traversal_nonRecursive(head);
	cout<<endl;
	BT.middle_order_traversal(head);
	cout<<endl;
	BT.post_order_traversal_nonRecursive(head);
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

