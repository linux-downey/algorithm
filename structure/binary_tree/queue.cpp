#include "queue.h"


QUEUE::QUEUE(u32 max_queue_len)
{
	queue.head=queue.tail=new QUEUE_NODE;
	queue.head->next=NULL;
	queue.max_len=max_queue_len;
	queue.q_len=0;
}

QUEUE::~QUEUE()
{
	destroy_queue();
}




s32 QUEUE::destroy_queue()
{
	while(!pop());
	delete queue.head;
	return 0;
}



s32 QUEUE::push(QUEUE_ELEM_TYPE data)
{
	QUEUE_NODE *node=new QUEUE_NODE;
	if(is_full())
	{
		return -1;
	}
	node->data=data;
	queue.tail->next=node;
	queue.tail=node;
	queue.q_len++;
	return 0;
}


/*Should not get the result through param,return the result is recomended.
**Cause there is no param in destructor.
*/
s32 QUEUE::pop()
{
	QUEUE_NODE *temp=NULL;
	if(is_empty())
	{
		return -1;	
	}
	temp=queue.head->next;  //get head of queue.
	if(temp==queue.tail)    //last node
	{
		queue.tail=queue.head;
		queue.head->next=NULL;
	}
	else
	{
		queue.head->next=temp->next;  //head point to next node.
	}
	queue.q_len--;
	delete temp;
	return 0;
}



s32 QUEUE::pop(QUEUE_ELEM_TYPE& data)
{
	QUEUE_NODE *temp=NULL;
	if(is_empty())
	{
		return -1;	
	}
	temp=queue.head->next;  //get head of queue.
	if(temp==queue.tail)    //last node
	{
		queue.tail=queue.head;
		queue.head->next=NULL;
	}
	else
	{
		queue.head->next=temp->next;  //head point to next node.
	}
	data=temp->data;
	queue.q_len--;
	delete temp;
	return 0;
}

s32 QUEUE::is_empty()
{
	if(0==queue.q_len)
	{
		//cout<<"is empty!"<<endl;
		return -1;
	}
	return 0;
}

s32 QUEUE::is_full()
{
	if(queue.q_len>=queue.max_len)
	{
		//cout<<"is full!"<<endl;
		return -1;
	}
	return 0;
}

s32 QUEUE::get_queue_len()
{
	return queue.q_len;
}



#ifdef QUEUE_DEBUG


//node 
int main()
{
	QUEUE queue;
	QUEUE_ELEM_TYPE S=new TREE_NODE[10];
	QUEUE_ELEM_TYPE temp;
	S[0].value=111;
	for(int i=1;i<10;i++)
	{
		queue.push(&S[i-1]);
		S[i].value=S[i-1].value*2;
	}

	  queue.pop(temp);
	  cout<<temp->value<<endl;
	  queue.pop(temp);
	  cout<<temp->value<<endl;
	  queue.pop(temp);
	  cout<<temp->value<<endl;
	  queue.pop(temp);
	  cout<<temp->value<<endl;
	  queue.pop(temp);
	  cout<<temp->value<<endl;
	delete[] S;
}


#endif