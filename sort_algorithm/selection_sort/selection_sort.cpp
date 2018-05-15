#include "selection_sort.h"


void Select::get_cmdline_num(char* argv[],u32 len)
{
    string str=argv[1];
    
}




u32 Select::get_min_num(u32 *data,u32 len)
{
    u32 min_num=0;                                 //min num value
    u32 min_num_index=0;                            //min num index
    u32 i=0;
    min_num=data[0];
    for(i=1;i<len;i++)
    {
        if(data[i]<min_num)
        {
            min_num=data[i];                        //find the min num.
            min_num_index=i;                      //find index of min num.
        }
    }
    return min_num_index;
}





void Select::selection_sort(u32 *data,u32 len)
{
    u32 sort_index=0;
    u32 temp=0;
    for(u32 i=0;i<len;i++)
    {
        sort_index=get_min_num(&data[i],len-i);
        temp=data[i];
        data[i]=data[sort_index+i];
        data[sort_index+i]=temp;
    }
    
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
        cout<<"    ";
    }
    cout<<endl;
}



int main()
{
    Select sort;
    u32 s[13]={5,8,3,6,4,2,1,5,4,7,88,99,20};
    sort.selection_sort(s,13);
    sort.print_data(s,13);
    return 1;
}