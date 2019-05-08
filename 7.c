#include <stdio.h>

typedef struct process
{
    int pno;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} proc;

proc arr[10];
int circq[11];
int np,fr=0,re=1,tq,fin=0;
int ct=0;
int burst[10];
int queue[100];

void print()
{
    int i;
    for(i=0;i<np;i++)
    {
        printf("For %d ct is %d\n",arr[i].pno+1,arr[i].ct);
    }
    float avgtat=0,avgwt=0;
    for(i=0;i<np;i++)
    {
        printf("For %d:\n",i+1);
        arr[i].tat=arr[i].ct-arr[i].at;
        avgtat+=arr[i].tat;
        arr[i].wt=arr[i].tat-burst[i];
        avgwt+=arr[i].wt;
        printf("TAT %d WT %d\n",arr[i].tat,arr[i].wt);
    }
    printf("Average TAT %f WT %f\n",avgtat/np,avgwt/np);
}

void calprocseqrr()
{
    int j,i,dec=0;
    for(j=0;;j++)
    {
        for(i=0;i<np;i++)
        {
            if(arr[i].at==j)
            {
                fr=(fr+1)%11;
                circq[fr] = arr[i].pno;
            }
        }
        if(dec==tq)
        {
            if(arr[re].bt!=0)
            {
                fr=(fr+1)%11;
                circq[fr] = arr[circq[re]].pno;
            }
            re=(re+1)%11;
            dec=0;
        }
        if(dec!=tq)
        {
            if(arr[circq[re]].bt!=1)
            {
                arr[circq[re]].bt--;
                dec++;
            }
            else
            {
                arr[circq[re]].bt=0;
                arr[circq[re]].ct=j+1;
                fin++;
                dec = tq;
            }
        }
        if(fin==np)
        {
            break;
        }
    }
   print();
}

void calprocseqsrtf()
{
    int i,j;
    fin=0,fr=0,re=0;
    int currp = -1;
    for(j=0;;j++)
    {
        for(i=0;i<np;i++)
        {
            if(arr[i].at==j)
            {
                if(currp==-1)
                {
                    currp=arr[i].pno;
                }
                else
                {
                    if(arr[i].bt<arr[currp].bt)
                    {
                        queue[fr++]=arr[currp].pno;
                        currp=i;
                    }
                    else
                    {
                        queue[fr++] = i;
                    }
                }
            }
        }   
        if(arr[currp].bt==0)
        {
            fin++;
            arr[currp].ct=j;
            int sbt=999;
            for(i=re;i<fr;i++)
            {
                if(arr[queue[i]].bt<sbt && arr[queue[i]].bt!=0)
                {
                    sbt=arr[queue[i]].bt;
                    currp=arr[queue[i]].pno;
                }
            }
        }
        if(arr[currp].bt!=0)
        {
            arr[currp].bt--;
        }
        if (fin==np) 
        {
            break;
        }
    }
    print();
}

void main()
{
    int i;
    printf("Enter number of processes for RR\n");
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        printf("For processs %d enter Arrival Time and Burst Time\n",i);
        scanf("%d%d",&arr[i].at,&arr[i].bt);
        burst[i] = arr[i].bt;
        arr[i].pno=i;
    }
    printf("Enter TQ\n");
    scanf("%d",&tq);
    calprocseqrr();
    printf("Enter number of processes for SRTF\n");
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        printf("For processs %d enter Arrival Time and Burst Time\n",i);
        scanf("%d%d",&arr[i].at,&arr[i].bt);
        burst[i] = arr[i].bt;
        arr[i].pno=i;
    }
    calprocseqsrtf();
}