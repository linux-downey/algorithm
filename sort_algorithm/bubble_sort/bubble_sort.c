#include "bubble_sort.h"




/*atoi() conver string to int,get the dst string before the first no-number char by src string */
int str_to_num(char *str)
{
    return atoi(str); 
}


void sort_bubble(u32 *data,u32 len)
{
    u32 i=0,j=0;
    u32 temp=0;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(data[j]>data[j+1])
            {
                temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
            }
        }
    }
}


s32 get_data_from_file(char* file_name,u32 *data,u32 *len)
{

}


int main(int argc,char *argv[])
{
    u32 *sort_num_array=malloc((argc-1)*sizeof(u32));
    if(NULL==sort_num_array) return 0;
    memset(sort_num_array,0,(argc-1)*sizeof(u32));
    if(argc<2)
    {
        printf("Too few arg !!\r\n");
    }
    else
    {
        if(strspn(argv[1],"0123456789")!=strlen(argv[1]))
        {
            //printf("files\n");

        }
        else
        {
            for(int i=0;i<argc-1;i++)
            {
                sort_num_array[i]=str_to_num(argv[i+1]);
            }
            sort_bubble(sort_num_array,(argc-1));
            for(int i=0;i<argc-1;i++)
            {
                printf("%d\t",sort_num_array[i]);
            }     
            printf("\r\n");
        }
    }
    
}