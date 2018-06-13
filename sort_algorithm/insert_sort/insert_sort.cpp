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
    return start+1;      //if end-start equal to 1,insert value>start,insert_value<end.Put it next to start.
}



void Insert::shift_array(u32 *data,u32 len,u32 insert_index,u32 insert_data)
{
    
    u32 *temp=new u32[len];
    memcpy(temp,data,len*sizeof(u32));
    
    data[insert_index]=insert_data;
    memcpy(&data[insert_index+1],&temp[insert_index],(len-insert_index)*sizeof(u32));
    delete[] temp;
    
}

void Insert::Insert_sort(u32 *data,u32 len)
{
    u32 i=0;
    u32 insert_index=0;
    u32 temp=0;
    for(i=1;i<len;i++)
    {
        insert_index=Insert_to_ordered(data,i,data[i]);
        
        shift_array(data,i,insert_index,data[i]);
        print_data(data,i+1);
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
    u32 data[100]={5,11,53,1,9,55,54,18,3,5};
    //u32 data[100]={5,11,36,2,1,55,12};
    u32 ret;
    Insert sort;
    sort.Insert_sort(data,10);
    sort.print_data(data,10);
    //sort.shift_array(data,5,2,88);
    //cout<<data[0]<<' '<<data[1]<<' '<<data[2]<<' '<<data[3]<<' '<<data[4]<<' '<<data[5]<<endl;
    //ret=sort.Insert_to_ordered(data,20,0);
    //cout<<ret<<endl;
    return 1;
}