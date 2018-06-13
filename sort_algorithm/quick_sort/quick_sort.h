#ifndef _QUICK_SORT_
#define _QUICK_SORT_

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned int;
using s32=int;



class Quick
{
    public:
        void quick_sort(u32 *data,u32 len);
        void swap(u32 &val1,u32 &val2);
        template<typename T>
        void print_data(T *data,u32 data_len);
    private:
        vector<u32> data_from_cmdline;
        
};



#endif
