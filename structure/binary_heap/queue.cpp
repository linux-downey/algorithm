#include "queue.h"

template <class T>
QUEUE<T>::QUEUE(u32 max_queue_len)
{
	queue.head=queue.tail=new Q_NODE<T>;
	queue.head->next=NULL;
	queue.max_len=max_queue_len;
	queue.q_len=0;
}

template <class T>
QUEUE<T>::~QUEUE()
{
	destroy_queue();
}



template <class T>
s32 QUEUE<T>::destroy_queue()
{
	while(!pop());
	delete queue.head;
	return 0;
}


template <typename T>
s32 QUEUE<T>::push(T data)
{
	Q_NODE<T> *node=new Q_NODE<T>;
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
template <typename T>
s32 QUEUE<T>::pop()
{
	Q_NODE<T> *temp=NULL;
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


template <typename T>
s32 QUEUE<T>::pop(T& data)
{
	Q_NODE<T> *temp=NULL;
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

template <typename T>
s32 QUEUE<T>::is_empty()
{
	if(0==queue.q_len)
	{
		//cout<<"is empty!"<<endl;
		return -1;
	}
	return 0;
}


template <typename T>
s32 QUEUE<T>::is_full()
{
	if(queue.q_len>=queue.max_len)
	{
		//cout<<"is full!"<<endl;
		return -1;
	}
	return 0;
}


template <typename T>
s32 QUEUE<T>::get_queue_len()
{
	return queue.q_len;
}



#ifdef QUEUE_DEBUG



// int main()
// {
// 	QUEUE<QUEUE_ELEM_TYPE> queue;
// 	QUEUE_ELEM_TYPE
// 	// QUEUE_ELEM_TYPE S=new TREE_NODE[10];
// 	// QUEUE_ELEM_TYPE temp;
// 	// S[0].value=111;
// 	// for(int i=1;i<10;i++)
// 	// {
// 	// 	queue.push(&S[i-1]);
// 	// 	S[i].value=S[i-1].value*2;
// 	// }

// 	//   queue.pop(temp);
// 	//   cout<<temp->value<<endl;
// 	//   queue.pop(temp);
// 	//   cout<<temp->value<<endl;
// 	//   queue.pop(temp);
// 	//   cout<<temp->value<<endl;
// 	//   queue.pop(temp);
// 	//   cout<<temp->value<<endl;
// 	//   queue.pop(temp);
// 	//   cout<<temp->value<<endl;
// 	// delete[] S;
// }


int main()
{
	QUEUE<QUEUE_ELEM_TYPE> queue;
	QUEUE_ELEM_TYPE temp;
	QUEUE_ELEM_TYPE a[10]={"hihi","sdf","sdfa","adfasf","adfas","asfd","asdfds","safdasf","daf","adsfdsf"};
	for(int i=0;i<10;i++)
	{
		queue.push(a[i]);
	}
	for(int i=0;i<11;i++)
	{
		queue.pop(temp);
		cout<<temp<<endl;
	}

	  cout<<queue.get_queue_len()<<endl;
	// QUEUE_ELEM_TYPE S=new TREE_NODE[10];
	// QUEUE_ELEM_TYPE temp;
	// S[0].value=111;
	// for(int i=1;i<10;i++)
	// {
	// 	queue.push(&S[i-1]);
	// 	S[i].value=S[i-1].value*2;
	// }

	//   queue.pop(temp);
	//   cout<<temp->value<<endl;
	//   queue.pop(temp);
	//   cout<<temp->value<<endl;
	//   queue.pop(temp);
	//   cout<<temp->value<<endl;
	//   queue.pop(temp);
	//   cout<<temp->value<<endl;
	//   queue.pop(temp);
	//   cout<<temp->value<<endl;
	// delete[] S;
}



#endif