#include "selection_sort.h"


void Select::get_cmdline_num(char* argv[],u32 len)
{
    string str=argv[1];
    
}


void Select::selection_sort(u32 *data,u32 len)
{

}

s32 Select::get_sort_data(char *file_name)
{

    return 0;
}


s32 Select::get_sort_data(char *cmdline_num_str[],u32 len)
{

    return 0;
}

template<typename T>
void Select::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        cout<<i+1<<'-'<<data[i];
    }
    cout<<endl;
}



int main()
{
    return 1;
}