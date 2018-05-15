#ifndef _INSERT_SORT
#define _INSERT_SORT


#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

using u8=unsigned char;
using u16=unsigned short;
using u32=unsigned int;
using s32=int;



class Insert
{
    public:
        s32 Insert_to_ordered(u32 *data,u32 len,u32 insert_value);
        void Insert_sort(u32 *data,u32 len);
        template<typename T>
        void print_data(T *data,u32 data_len);
    private:
        vector<u32> data_from_cmdline;

};




#endif