#include "selection_sort.h"
#include <stdlib.h>

s32 Select::data_is_from_file(string str)
{
    string::iterator iter;
    iter=str.begin();
    while(iter!=str.end())
    {
        if((*iter<'0')||(*iter>'9'))
        {
            return 0;
        }
        iter++;
    }
    return 1;
}

template<typename T>
s32 Select::get_cmdline_num(char* argv[],u32 len,T *dst_data)
{
    s32 ret=0;
    //s32 array_len=0;
    string str(argv[1]);
    ret=data_is_from_file(str);
    if(0==ret)
    {
        cout<<"file"<<endl;
    }
    else
    {
        return get_sort_data(&argv[1],len-1,dst_data);
    }
    return 0;
}


void Select::selection_sort(u32 *data,u32 len)
{

}

template<typename T>
s32 get_sort_data(char *file_name,T *dst_data)
{
    ofstream f;
    f.open();
    return 0;
}


template<typename T>
s32 Select::get_sort_data(char *cmdline_num_str[],u32 len,T *dst_data)
{
    u32 i=0;
    for( i=0;i<len;i++)
    {
        dst_data[i]=atoi(cmdline_num_str[i]);
    }

    return i;
}

template<typename T>
void Select::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        cout<<i+1<<'-'<<data[i];
        cout<<"  ";
    }
    cout<<endl;
}



int main(int argc,char *argv[])
{
    Select sort;
    s32 dst_array[1024]={0};
    u32 array_len;
    if(argc<2)
    {
        cout<<"Too few arg!!"<<endl;
        return 0;
    }
    array_len=sort.get_cmdline_num(argv,argc,dst_array);
    sort.print_data(dst_array,array_len);
    return 1;
}