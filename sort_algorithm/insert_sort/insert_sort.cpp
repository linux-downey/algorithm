#include <iostream>

#include "insert_sort.h"





s32 Insert::Insert_to_ordered(u32 *data,u32 len,u32 insert_value)
{
    u32 index=0;
    u32 start=0;
    u32 end=len-1;
    while(end==start)
    {
        index=(end+start)/2;
        if(insert_value>data[index])
        {
            start=index;
        }
        else
        {
            end=index;
        }
    }
}


void Insert::Insert_sort(u32 *data,u32 len)
{

}


template<typename T>
void Insert::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        cout<<i+1<<'-'<<data[i];
        cout<<"    ";
    }
    cout<<endl;
}




int main()
{

    return 1;
}