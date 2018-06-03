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


using QUEUE_ELEM_TYPE=string;


template<typename T>
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




#endif