#include "binary.h"
#include "queue.h"


BinaryTree::BinaryTree()
{
	//root=new TreeNode<u32>;
}

BinaryTree::~BinaryTree()
{
	destroy_tree(root);
}




s32 BinaryTree::destroy_tree(TreeNode<u32> *root)
{
	if(NULL==root)
	{	
		return -1;
	}
	
	destroy_tree(root->left_child);
	
	destroy_tree(root->right_child);
	
	delete root;
	
	return 0;
}


TreeNode<u32>* BinaryTree::create_tree()
{
	TreeNode<u32>* root;
	char c;
	cin>>c;
	if('!'==c)
	{
		return NULL;
	}
	root=new TreeNode<u32>;
	root->value=c;
	
	root->left_child=create_tree();
	root->right_child=create_tree();
	
	return root;
}


TreeNode<u32>* BinaryTree::get_root()
{
	return root;
}



s32 BinaryTree::create_tree(u32 value)
{
	root=new TreeNode<u32>;
	root->value=value;
	root->left_child=NULL;
	root->right_child=NULL;
	return 0;
}

s32 BinaryTree::preorder_traversal(TreeNode<u32> *root)
{
	if(NULL==root)
	{
		return -1;
	}
	cout<<root->value<<"  ";
	preorder_traversal(root->left_child);
	preorder_traversal(root->right_child);
	return 0;
}


s32 BinaryTree::middle_order_traversal(TreeNode<u32> *root)
{
	if(NULL==root)
	{
		return -1;
	}
	
	preorder_traversal(root->left_child);
	cout<<root->value<<"  ";
	preorder_traversal(root->right_child);
	return 0;
}


s32 BinaryTree::post_order_traversal(TreeNode<u32> *root)
{
	if(NULL==root)
	{
		return -1;
	}
	
	post_order_traversal(root->left_child);
	post_order_traversal(root->right_child);
	cout<<root->value<<"  ";
	return 0;
	
}


s32 BinaryTree::level_traversal(TreeNode<u32> *root)
{
	QUEUE queue;
	/*u32 root_addr=static_cast<u32>(root);
	queue.push(root);
	//cout<<root->value<<"  ";
	while(-1!=queue.pop(&root_addr))
	{
		if(NULL!=(TreeNode<u32>*)root_addr->left_child)
		{
			queue.push((TreeNode<u32>*)root_addr->left_child);	
		}
		if(NULL!=(TreeNode<u32>*)root_addr->right_child)
		{
			queue.push((TreeNode<u32>*)root_addr->right_child);	
		}
		cout<<(TreeNode<u32>*)root_addr->value<<"  ";
	}*/
	return 0;
}


s32 BinaryTree::get_height_of_tree(TreeNode<u32> *root)
{
	
	return 0;
}



s32 BinaryTree::insert_node(u32 value)
{
	return 0;
}

s32 BinaryTree::delete_node(u32 *value)
{
	return 0;
}


#ifdef BITREE_DEBUG

int main()
{
	BinaryTree BT;
	BT.root=BT.create_tree();
	//BT.destroy_tree(root);
	BT.preorder_traversal(BT.root);
	cout<<endl;
	BT.middle_order_traversal(BT.root);
	cout<<endl;
	BT.post_order_traversal(BT.root);
	cout<<endl;
	return 0;
}

#endif

