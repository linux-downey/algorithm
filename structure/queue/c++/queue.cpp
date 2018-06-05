//  
//                                  _oo8oo_
//                                 o8888888o
//                                 88" . "88
//                                 (| -_- |)
//                                 0\  =  /0
//                               ___/'==='\___
//                             .' \\|     |// '.
//                            / \\|||  :  |||// \
//                           / _||||| -:- |||||_ \
//                          |   | \\\  -  /// |   |
//                          | \_|  ''\---/''  |_/ |
//                          \  .-\__  '-'  __/-.  /
//                        ___'. .'  /--.--\  '. .'___
//                     ."" '<  '.___\_<|>_/___.'  >' "".
//                    | | :  `- \`.:`\ _ /`:.`/ -`  : | |
//                    \  \ `-.   \_ __\ /__ _/   .-` /  /
//                =====`-.____`.___ \_____/ ___.`____.-`=====
//                                  `=---=`
// 
//                          佛祖保佑         永无bug
// 

/**@file queue.cpp
 * @brief 
 * @author downey
 * @date 2018-06-03
 * 
 * */



#include "queue.h"


/*Create a queue in constructor.
**User needn't to init the queue,because the NULL-queue was created at instantiation.
**User defines a max queue len,defualt is 255.
*/
template <class T>
QUEUE<T>::QUEUE(u32 max_queue_len)
{
	queue.head=queue.tail=new Q_NODE<T>;
	queue.head->next=NULL;
	queue.max_len=max_queue_len;
	queue.q_len=0;
}


/*Destroy the queue automatically in Destructor to avoid leak of memory.
**User can also call destroy_queue() to clean the queue.Double-destroy is acceptable.
*/
template <class T>
QUEUE<T>::~QUEUE()
{
	destroy_queue();
}


/*Destroy the queue,free memory.
**
*/
template <class T>
s32 QUEUE<T>::destroy_queue()
{
	while(!pop());
	delete queue.head;
	return 0;
}


/*Push node into queue.
**
*/
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


/*
**Pop elem without output.Called in destructor.
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


/*Pop elem.
**
*/
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


/*Check if the queue is empty.
**
*/
template <typename T>
s32 QUEUE<T>::is_empty()
{
	if(0==queue.q_len)
	{
		return -1;
	}
	return 0;
}


/*Check if the queue is full.
**
*/
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


/*Get length of queue.
**
*/
template <typename T>
s32 QUEUE<T>::get_queue_len()
{
	return queue.q_len;
}




int main()
{
	QUEUE<QUEUE_ELEM_TYPE> queue;
	QUEUE_ELEM_TYPE temp;
	QUEUE_ELEM_TYPE a[10]={"abc","bcd","cdf","efg","fgh","ghi","hij","ijk","jkl","klm"};
	for(int i=0;i<10;i++)
	{
		queue.push(a[i]);
	}
	for(int i=0;i<11;i++)
	{
		if(!queue.pop(temp))
		{
			cout<<temp<<endl;
			cout<<"queue len = ";
			cout<<queue.get_queue_len()<<endl;
		}
		else
		{
			cout<<"queue is empty"<<endl;
		}
	}
}


