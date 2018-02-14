#include <stdio.h>
#include <math.h>


struct node {
    int lower_limit;
    int frequency;
    int higher_limit;
    struct node* next;
};
int t=0;
struct node* add_intervals();
void display();
void add_frequency();
float mean();
float variance();
int main()
{
    int i,n,min,max,*arr,count,count1,intervals,interval_length;
    float mean_value,variance_value,avg=0,avg_lessthanavg=0; t=t+2;
    struct node *ptr,*start=NULL;
    printf("Total no. of numbers in the given data:\n");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("No. of intervals required:\n");
    scanf("%d",&intervals);
    t++;
    for(i=0;i<n;i++)
    {
        t=t+3;
        scanf("%d",&arr[i]);
    }
    min=arr[0]; // 2 for this => 1 for assignment ,1 for fetching *arr 
    max=min;
    count=1;
    t=t+4;//for above three lines
    t=t+1;//for i=1 assignment
    for(i=1;i<n;i++)
    {
        t=t+3;// 1 for i<n 2 for i=i+1
        if(min>arr[i])//3 => 1 for comparision 1 for fetching *arr 1 for fetching *(arr+i) 
        {
            min=arr[i];//3 => almost same as above
            t=t+6;
        }
        if(max<arr[i])
        {
            max=arr[i];
            t=t+6;
        }
        count++;
        t=t+2;
    }
    interval_length = ((max - min+1) / intervals);
    /*******/
    /*ADD THIS HERE:*/
    t+=1;
    if(interval_length == 0){
        interval_length =1;
        t++;
    }
    /*************/
    
    
    t=t+3;
    printf("interval length=%d minimum=%d maximum=%d\n",interval_length,min,max);
    count=0;
    t=t+3;// 1 for count 1 for i
    ptr=start;
    for(i=0;i<intervals;i++)
    {
        ptr=add_intervals(ptr,min,min+interval_length-1);
        if(start==NULL)
            {
                start=ptr;
                t=t+2;
            }
        min=min+interval_length;
        t=t+6;
    }
    if(min <= max){
        ptr=add_intervals(ptr,min,min+interval_length-1);
        intervals++;
        t=t+4;
        }
    for(i=0;i<n;i++)
    {
        add_frequency(start,arr[i]);
        t=t+3;
    }
    display(start);
    mean_value=mean(start);
    t++;
    printf("%.1f\n",mean_value);
    variance_value=variance(start);
    t=t+2;
    printf("%.2f\n",variance_value-((mean_value)*(mean_value)));
    t=t+2;
    for(i=0;i<n;i++)
    {
        avg=avg+arr[i];
        t=t+7;
    }
    avg=(float) avg/n;
    count1=0;
    t=t+5;
    for(i=0;i<n;i++)
    {
        if(avg>arr[i])
        {
            avg_lessthanavg=avg_lessthanavg+arr[i];
            count1++;
            t=t+9;
        }
        t=t+3;
    }
    /*******/
    //Add this too:
    t++;
    if(count1>0){
        avg_lessthanavg=(float) avg_lessthanavg/count1;
        t++;
    }
    t=t+3;
    printf("%.1f\n",avg_lessthanavg);
    printf("the value of t is : %d \n", t);
    return 0;
}
struct node* add_intervals(struct node* start, int low, int high)
{
    struct node *temp,*ptr;
    ptr=start;
    temp=(struct node *) malloc(sizeof(struct node));
    temp->lower_limit=low;
    temp->higher_limit=high;
    temp->frequency=0;
    temp->next=NULL;
    t=t+8; // 2 for each of the above assignments 1 for assignment  1 for temp->lower_limit/higher_limit/frequency/next
    if(ptr==NULL)
    {
        ptr=temp;//1
        t=t+3; // 1 for return too
        return ptr;
    }
    ptr->next=temp;
    t=t+3;
    return temp;
};
void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d-%d  %d\n",ptr->lower_limit,ptr->higher_limit,ptr->frequency);
        ptr=ptr->next;
        t=t+3;
    }
}
void add_frequency(struct node* ptr, int k)
{
    while(ptr!=NULL)
    {
        if((ptr->lower_limit<= k)&& (ptr->higher_limit >= k))
        {
            ptr->frequency++;
            ptr=ptr->next;
            t=t+10;
        }
        else
        {
            ptr=ptr->next;
            t=t+2;
        }
        t++;
    }
}
float mean(struct node *ptr)
{
    float mean_value,mean_sum=0;
    int total_frequencies=0;
    t=t+2;
    while(ptr!=NULL)
    {
        mean_sum = mean_sum +(float)(ptr->frequency)*(ptr->higher_limit + ptr->lower_limit)/2 ;
        total_frequencies=total_frequencies+ ptr->frequency;
        ptr=ptr->next;
        t=t+15;
    }
    mean_value=(float) mean_sum / total_frequencies;
    t=t+4;
    return mean_value;
}
float variance(struct node *ptr)
{
    float variance_value,variance_sum=0;
    int total_frequencies=0;
    t=t+2;
    while(ptr!=NULL)
    {
        variance_sum = variance_sum + (float) (ptr->frequency)*((float)(ptr->higher_limit + ptr->lower_limit)/2)*((float)(ptr->higher_limit + ptr->lower_limit)/2) ;
        total_frequencies=total_frequencies+ ptr->frequency;
        ptr=ptr->next;
        t=t+18;
    }
    variance_value= (float) (variance_sum / total_frequencies) ;
    t=t+4;
    return variance_value;
}
