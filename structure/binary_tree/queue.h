#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

#include "binary.h"


#ifndef PRE_DEFINE
#define PRE_DEFINE

using std::cout;
using std::cin;
using std::endl;

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


using QUEUE_ELEM_TYPE=TREE_NODE_PTR;


using QUEUE_NODE = Q_NODE<QUEUE_ELEM_TYPE>;  //Take the binary tree node pointer as queue-node value part.
using QUEUE_NODE_PTR = Q_NODE<QUEUE_ELEM_TYPE>*;

// using QUEUE_NODE = Q_NODE<u32>;  //Take the binary tree node pointer as queue-node value part.
// using QUEUE_NODE_PTR = Q_NODE<u32>*;

struct Q
{
	QUEUE_NODE* head;
	QUEUE_NODE* tail;
	u32 q_len;
	u32 max_len;
};





class QUEUE
{
	public:
		~QUEUE();
		QUEUE(u32 max_queue_len=DEFAULT_MAX_QUEUE_LEN);
		s32 destroy_queue();
		
		s32 push(QUEUE_ELEM_TYPE data);

		s32 pop(QUEUE_ELEM_TYPE& data);
		
		s32 pop(); 
		s32 is_empty();
		s32 is_full();
		s32 get_queue_len();
	private:
		Q queue;	
};




#endif