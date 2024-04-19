#include<stdio.h>
typedef struct pro{
    int n;
    float a;
    float b;
}pro;
void tab(struct pro t[],int n){ //function of reading
    int i,j;
    for(i=0;i<n;i++){ 
        printf("Enter Arrival Time for P%d ; ",i+1);
        scanf("%f",&t[i].a);
        printf("Enter Burst Time for P%d ; ",i+1);
        scanf("%f",&t[i].b);
        t[i].n = i+1; //number of process
    }
    struct pro c;
    for(i=0;i<n;i++) //for sorting process 3la 7sab arival time
    {
      for(j=i;j<n;j++){
      if(t[j].a<t[i].a){
      c = t[i];
      t[i]=t[j];
      t[j]=c;
      }
      }
    } 
}
void R_R(struct pro t[],float a[],int n,float q){ //roundrobing function
    int i,b,j;
    float c;
    c = 0;
    i = 0;
    b = 1;
    while( b=1 &&i<n ){ 
        if(t[i].b > q){
            t[i].b -= q; //burst time - q
            c += q; //c counter ta3 lwa9t li 5admo fih process
            printf("P%d BT:%d",i+1,t[i]);
        }else if(t[i].b > 0){
            c += t[i].b;//if burst time a9al mn q ydirha 0
            t[i].b = 0;
           printf("P%d BT:%d",i+1,t[i]);
        }
        if(t[i].b == 0){
            a[i] = c - t[i].a; //a == turn around time
        }
        j = 0;
        while(j<n && t[j].b == 0){
            j++; //skiping finish process
        }
        if(j>=n){
            b = 0; //boolen pour while
        }
        if(i == n-1 && b == 1){ 
            i = -1; 
        }
        i++;
    }
}
void W_T(float w[],float t[],float b[],int n){ //waiting time function
    int i;
    for(i=0;i<n;i++){
        w[i] = t[i] - b[i]; //waiting time = turnaround time - brusttime
    }
}
float average(float t[],int n){
    int a,i;
    a = 0;
    for(i=0;i<n;i++){
        a += t[i]; //average waiting time =+waiting time // average tAT += waiting turnaroundtime 
    }
    return a/2;
}
void display(struct pro p[],float b[],float t[],float w[],float q,int n){
    int i;
    printf("quantum is : %.3f\n",q);
    printf("Process       Burst       Arrival       Turnaround       Waiting\n");
    for(i=0;i<n;i++){
    printf("P%d            %.2f      
      %.2f          %.2f             %.2f\n",i+1,b[i],p[i].a,t[i],w[i]);
    }
    printf("Average                                 %.2f             %.2f\n",average(t,n)),average(w,n);
}
void T(struct pro t[],int n){
int i,j;
 struct pro c;
    for(i=0;i<n;i++){
      for(j=i;j<n;j++){
      if(t[j].a<t[i].a){
      c = t[i];
      t[i]=t[j];
      t[j]=c;
      }
      }
    }
} 
void main(){
    struct pro P[100];
    int n,i;
    printf("Enter Number process : ");
    scanf("%d",&n);
    float BT[n],TAT[n],WT[n],q;
    printf("Enter Quantum : ");
    scanf("%f",&q);
    tab(P,n);
    for(i=0;i<n;i++){
        BT[i] = P[i].b;
    }
    R_R(P,TAT,n,q);
    W_T(WT,TAT,BT,n);
    T(P,n);
    display(P,BT,TAT,WT,q,n);
}
