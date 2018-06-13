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

/**@file queue.h
 * @brief header file
 * @author downey
 * @date 2018-06-03
 * 
 * */
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <string>


#ifndef PRE_DEFINE
#define PRE_DEFINE

using std::cout;
using std::cin;
using std::endl;
using std::string;

using u8 =unsigned char;
using u32=unsigned int;
using s32=int;
using u16=unsigned short;

#endif


#define DEFAULT_MAX_QUEUE_LEN  255


template <typename T>
struct Q_NODE
{
	Q_NODE* next;
	T data;
};





template <typename T>
struct Q
{
	Q_NODE<T>* head;
	Q_NODE<T>* tail;
	u32 q_len;
	u32 max_len;
};



template <class T>
class QUEUE
{
	public:
		~QUEUE();
		QUEUE(u32 max_queue_len=DEFAULT_MAX_QUEUE_LEN);
		s32 destroy_queue();
		s32 push(T data);
		s32 pop(T& data);
		
		s32 pop();
		s32 is_empty();
		s32 is_full();
		s32 get_queue_len();
	private:
		Q<T> queue;
};



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
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
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
template <class T>
s32 QUEUE<T>::get_queue_len()
{
	return queue.q_len;
}








#endif