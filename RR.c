#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int arr_time;
    int burst_time;
}un_t3;
int main(){
    printf("Enter Number of process : ");
    int n;
    int wait_time = 0, ta_time = 0;
    scanf("%d",&n);
    un_t3 g[n];
    int  temp_burst_time[n];
      for(int i = 0; i < n; i++)
        { //reading details
        printf("Enter Details of Process %d \n", i + 1);
        printf("ID : ");
        scanf("%d",&g[i].id);
        printf("Arrival Time:  ");
        scanf("%d", &g[i].arr_time);
        printf("Burst Time:   ");
        scanf("%d", &g[i].burst_time);
        temp_burst_time[i] = g[i].burst_time;
        }
    int q;
    printf("Enter quantum: ");
    scanf("%d",&q);

    int total = 0,  j = 0,i; //total time of process working //j boolen
    int x=n;
    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");
    for(total=0, i = 0; x!=0;) /*  while(total==0 && i == 0 && x != 0) */
    {
        if(temp_burst_time[i] <= q && temp_burst_time[i] > 0)
        {
            total = total + temp_burst_time[i];
            temp_burst_time[i] = 0;
            j=1;
             /*printf("p%d BT%d ||",i+1,temp_burst_time[i]);*/
        }
        else if(temp_burst_time[i] > 0)
        {
            temp_burst_time[i] = temp_burst_time[i] - q;
            total  += q;
          /*  printf("p%d BT%d ||",i+1,temp_burst_time[i]);*/
        }
        if(temp_burst_time[i]==0 && j==1)
        {
            x--;
           printf("\nProcess No %d  \t\t %d\t\t\t\t %d\t\t\t %d", i+1, g[i].burst_time,total-g[i].arr_time, total-g[i].arr_time-g[i].burst_time);
            wait_time = wait_time+total-g[i].arr_time-g[i].burst_time;
            ta_time += total - g[i].arr_time;
            j =0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(g[i+1].arr_time<=total)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    printf("\nAverage Waiting Time:%f", average_wait_time);
    printf("\nAvg Turnaround Time:%f", average_turnaround_time);
    return 0;
}
/* قوانين المستخدمة
q=كوانتوم
متوسط وقت الانتظار = وقت الانتظار /عدد البروسس
متوسط وقت الدور= وقت الدور /عدد البروسس
*/
