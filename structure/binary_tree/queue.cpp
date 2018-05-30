#include "queue.h"


QUEUE::QUEUE(u32 max_queue_len)
{
	queue.head=queue.tail=new Q_NODE<u32>;
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
	u32 value;
	while(!pop(&value));
	delete queue.head;
}



s32 QUEUE::push(u32 data)
{
	Q_NODE<u32> *node=new Q_NODE<u32>;
	if(is_full())
	{
		return -1;
	}
	node->data=data;
	queue.tail->next=node;
	queue.tail=node;
	queue.q_len++;
	cout<<"hello"<<queue.q_len<<endl;
	return 0;
}

s32 QUEUE::pop(u32 *data)
{
	Q_NODE<u32> *temp=NULL;
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
	*data=temp->data;
	queue.q_len--;
	delete temp;
	return 0;
}

s32 QUEUE::is_empty()
{
	if(0==queue.q_len)
	{
		cout<<"is empty!"<<endl;
		return -1;
	}
	return 0;
}

s32 QUEUE::is_full()
{
	if(queue.q_len>=queue.max_len)
	{
		cout<<"is full!"<<endl;
		return -1;
	}
	return 0;
}

s32 QUEUE::get_queue_len()
{
	return queue.q_len;
}

#ifdef QUEUE_DEBU

int main()
{
	QUEUE queue;
	u32 value=0;
	queue.push(0x38);
	queue.push(0x39);
	queue.push(0x40);
	queue.pop(&value);
	cout<<value<<endl;
	queue.pop(&value);
	cout<<value<<endl;
	queue.pop(&value);
	cout<<value<<endl;
}


#endif