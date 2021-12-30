#include<stdio.h>
void main()
{
int x,n,P[10]={1,2,3,4,5,6,7,8,9,10},Min,r=1,Brust time=0;

int BT[10],Temp,y,At[10],Wt[10],Tt[10],Ta=0,Sum=0;

float Wavg=0,Tavg=0,Tsum=0,Wsum=0;

printf(" Shortest Job First Scheduling ( Non PremmiPtive ) \n");
printf(" Enter the Number of processes :\n");
scanf("%d",&n);
 
for(x=0;x<n;x++)
{
printf("\tEnter the burst time of %d process :",x+1);
scanf(" %d",&bt[x]);
printf("\tEnter the arrival time of %d process :",x+1);
scanf(" %d",&at[x]);
}
 
//sorting According to Arrival Time.
 
for(x=0;x<n;x++)
{
for(y=0;y<n;y++)
{
if(at[x]<at[y])
{
Temp=P[y];
P[y]=P[x];
P[x]=Temp;
Temp=AT[y];
AT[y]=AT[x];
AT[x]=Temp;
Temp=BT[y];
BT[y]=BT[x];
BT[x]=Temp;
}
}
}
 
//Arranging the table according to Burst time,Execution time and Arrival Time.
//arrival time <= execution time.

 
for(y=0;y<n;y++)
{
Brust time=Brust time+BT[y];
Min=BT[r];
for(x=r;x<n;x++)
{
if (Brust time>=AT[x] && BT[x]<Min)
{
Temp=P[r];
P[r]=P[x];
P[x]=Temp;
Temp=AT[r];
AT[r]=AT[x];
AT[x]=Temp;
Temp=BT[r];
BT[r]=BT[x];
BT[x]=Temp;
}
}
r++;
}
WT[0]=0;
for(x=1;x<n;x++)
{
Sum=Sum+BT[x-1];
WT[x]=Sum-AT[x];
Wsum=Wsum+Wt[x];
}
 
Wavg=(Wsum/n);
for(x=0;x<n;x++)
{
Ta=Ta+BT[x];
Tt[x]=Ta-AT[x];
Tsum=Tsum+Tt[x];
}
 
Tavg=(Tsum/n);
 
printf("$$$$$$$$$$$$$$$$$$$");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(x=0;x<n;x++)
{
printf("\n P%d\t %d\t %d\t\t %d\t\t\t%d",P[x],BT[x],AT[x],Wt[x],Tt[x]);
}
 
printf("\n\n average wating time : %f",Wavg);
printf("\n average turnaround time : %f",Tavg);

}
