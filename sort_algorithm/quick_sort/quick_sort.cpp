#include "quick_sort.h"

void Quick::swap(u32 &val1,u32 &val2)
{
    u32 temp=0;
    temp=val1;
    val1=val2;
    val2=temp;
}



void Quick::quick_sort(u32 *data,u32 len)
{
    u32 base_value=data[0];
    u32 i=1,j=len-1;
    u32 temp=0;

    if(1>=len)
    {
        return ;
    }

    //When i==j,the elem before i is less than base value,the elem after i is more than base value.
    while(i!=j)
    {
        while((data[i]<=base_value)&&(i!=j))   //Begin from head,Find a elem more than base value,till i==j
        {
            i++;
        }
        while((data[j]>base_value)&&(i!=j))   //Begin from tail，Find a elem less than base value,till i==j
        {
            j--;
        }
        swap(data[i],data[j]);
    }

    
    //if the data with index i less than base value,exchange before one with base value.
    if(data[i]>data[0])
    {
        temp=data[i-1];
        data[i-1]=data[0];
        data[0]=temp;
    }
    //if the data with index i more than base value,exchange then
    else
    {
        temp=data[i];
        data[i]=data[0];
        data[0]=temp;
    }

    quick_sort(data,i);
    quick_sort(&data[i],len-i);
}


template<typename T>
void Quick::print_data(T *data,u32 data_len)
{
    for(u32 i=0;i<data_len;i++)
    {
        //cout<<i+1<<'-'<<data[i];
        cout<<data[i];
        cout<<"   ";
    }
    cout<<endl;
}


int main()
{
    Quick sort;
    u32 data[]={6,64,25,84,5,1,2,48,62,5,8,548,24,12,6456,1,513456,1,31,5641,32,165,4135,15,145,15,6415456,48,4864,6584,6,84,5,2,6,4,2,4,58,1,4,1,1,2,65};
    sort.quick_sort(data,sizeof(data)/sizeof(u32));
    sort.print_data(data,sizeof(data)/sizeof(u32));
    return 1;
}
