#include <iostream>

#include "insert_sort.h"




/**
 * 
 * 
 * */
s32 Insert::Insert_to_ordered(u32 *data,u32 len,u32 insert_value)
{
    u32 index=0;
    u32 start=0;
    u32 end=len-1;
    if(insert_value>=data[len-1])     //If the insert value is max one,Put it at the end of the array.return the location index.
    {
        return len;
    }
    if(insert_value<=data[0])           //If the insert value is max one,Put it at the start of the array.return the location index.
    {
        return 0;
    }
    while(end-start>1)
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
    return start;
}


void Insert::Insert_sort(u32 *data,u32 len)
{
    u32 i=0;
    u32 inse_index=0;
    for(i=0;i<len;i++)
    {
        Insert_to_ordered(data,i,data[i]);
    }
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




int main(int argc,char *argv[])
{
    u32 data[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    u32 ret;
    Insert sort;
    ret=sort.Insert_to_ordered(data,20,0);
    cout<<ret<<endl;
    return 1;
}