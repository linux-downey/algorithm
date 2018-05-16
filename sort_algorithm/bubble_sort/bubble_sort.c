#include "bubble_sort.h"
#include <sys/time.h>
#include <unistd.h>
#include <sstream>



/*atoi() conver string to int,get the dst string before the first no-number char by src string */
int str_to_num(char *str)
{
    return atoi(str); 
}


/**Optimization:Add a flag
 * 
 * 
 * */
void sort_bubble(u32 *data,u32 len)
{
    u32 i=0,j=0;
    u32 temp=0;
    char flag=0;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(data[j]>data[j+1])
            {
                temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
                flag=1;
            }
        }
        if(!flag)
        {
            return;
        }
        else
        {
            flag=0;
        }
    }
}


s32 get_data_from_file(const char* file_name,u32 *data,u32 *len)
{
    FILE *fp=NULL;
    char file_buf[100]={0};
    s32 i=0;
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        printf("can't open file!!!\r\n");
        return -1;
    }
    for(i=0;!feof(fp);i++)
    {
        fgets(file_buf,100,fp); 
        data[i]=str_to_num(file_buf);
    }
    *len=i;
    return 0;
}

void print_32_array(u32 *buf,u32 buf_len)
{
<<<<<<< Updated upstream
    for(int i=0;i<buf_len;i++)
    {
        printf("%d-%d ",i+1,buf[i]);
    }
    printf("\r\n");
}


u32 get_process_time(Algo_func func,u32 *data,u32 len)
{
    struct timeval tv_befor,tv_after;
    gettimeofday(&tv_befor,NULL);
    func(data,len);
    gettimeofday(&tv_after,NULL);
    return (tv_after.tv_sec*1000000+tv_after.tv_usec)-(tv_befor.tv_sec*1000000+tv_befor.tv_usec);
=======
    
>>>>>>> Stashed changes
}




int main(int argc,char *argv[])
{
    u32 sort_num_array[1024]={0};
    
    u32 time_us=0;
    if(argc<2)
    {
        printf("Too few arg !!\r\n");
    }
    else
    {
        if(strspn(argv[1],"0123456789")!=strlen(argv[1]))   //Read number data from file!!
        {
            u32 num=0;
            if(get_data_from_file(argv[1],sort_num_array,&num))
            {
                return 0;
            }
            time_us=get_process_time(sort_bubble,sort_num_array,num);
            printf("process time =%d\r\n",time_us);
            //sort_bubble(sort_num_array,num);

            print_32_array(sort_num_array,num);
        }
        else                                                //Get number data from CMD line!!
        {
            //u32 *sort_num_array=malloc((argc-1)*sizeof(u32));
            for(int i=0;i<argc-1;i++)
            {
                sort_num_array[i]=str_to_num(argv[i+1]);
            }
            time_us=get_process_time(sort_bubble,sort_num_array,(argc-1));
            printf("process time =%d\r\n",time_us);
            //sort_bubble(sort_num_array,(argc-1));
            print_32_array(sort_num_array,(argc-1));
        }
    }
    
}