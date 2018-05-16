#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

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


class Select
{
    public:
        void selection_sort(u32 *data,u32 len);
        template<typename T>
        s32 get_sort_data(char *file_name,T *dst_data);
        template<typename T>
        s32 get_sort_data(char *cmdline_num_str[],u32 len,T *dst_data);
        template<typename T>
        s32 get_cmdline_num(char* argv[],u32 len,T *dst_data);
        template<typename T>
        void print_data(T *data,u32 data_len);
        void get_cmdline_num(char* argv[],u32 len);
        s32 data_is_from_file(string str);
    private:
        vector<u32> data_from_cmdline;
        
};



#endif
