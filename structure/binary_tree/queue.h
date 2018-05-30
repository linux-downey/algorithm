#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

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

struct Q
{
	Q_NODE<u32>* head;
	Q_NODE<u32>* tail;
	u32 q_len;
	u32 max_len;
};


class QUEUE
{
	public:
		~QUEUE();
		QUEUE(u32 max_queue_len=DEFAULT_MAX_QUEUE_LEN);
		s32 destroy_queue();
		s32 push(u32 data);
		s32 pop(u32 *data);
		s32 is_empty();
		s32 is_full();
		s32 get_queue_len();
	private:
		Q queue;
		
};




#endif