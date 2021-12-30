#include<stdio.h> 
 void main() 
{ 
      int x, Limit, Total = 0, L, Counter = 0, Time_quantum; 
      int Waiting_time = 0, Turnaround_time = 0, Arrival_time[10], Burst_time[10], Temp[10]; 
      float Average_Waiting_time, Average_Turnaround_time;
      printf("\n enter the Total Number of Processes:\t"); 
      scanf("%d", &Limit); 
      L = Limit; 
      for(x = 0; x < Limit; x++) 
      {
            printf("\n enter the Details of Process[%d]\n", x + 1);
            printf("Arrival Time:\t");
            scanf("%d", &Arrival_time[x]);
            printf("Burst_Time:\t");
            scanf("%d", &Burst_time[x]); 
            Temp[x] = Burst_time[x];
      } 
      printf("\n enter the Time Quantum:\t"); 
      scanf("%d", &Time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(Total = 0, L = 0; L != 0;) 
      { 
            if(Temp[x] <= Time_quantum && Temp[x] > 0) 
            { 
                  Total = Total + Temp[x]; 
                  Temp[x] = 0; 
                  Counter = 1; 
            } 
            else if(Temp[x] > 0) 
            { 
                  Temp[x] = Temp[x] - Time_quantum; 
                  Total = Total + Time_quantum; 
            } 
            if(Temp[x] == 0 && Counter == 1) 
            { 
                  L--; 

                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", x + 1, burst_time[x], Total - Arrival_time[x], Total - Arrival_time[x] - Burst_time[x]);
                 
                Turnaround_time = Turnaround_time + Total - Arrival_time[x]; 
 		Waiting_time = Waiting_time + Total - Arrival_time[x] - Burst_time[x]; 
                Counter = 0; 
            } 
            if(x == Limit - 1) 
            {
                 x = 0; 
            }
            else if(Arrival_time[x + 1] <= Total) 
            {
                  x++;
            }
            else 
            {
                  x = 0;
            }
      } 
      Average_Waiting_time = Waiting_time * 1.0 / Limit;
      Average_Turnaround_time = Turnaround_time * 1.0 / Limit;

      printf("\n\n Average Waiting Time:\t%f", Average_Waiting_time); 
      printf("\n Avg Turnaround Time:\t%f\n", Average_Turnaround_time); 
       
}
