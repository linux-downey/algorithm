#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef int s32;


typedef void(*Algo_func)(u32 *,u32);






u32 get_process_time(Algo_func func,u32 *data,u32 len);





#endif