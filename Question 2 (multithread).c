// C Program to multiply 2 Matrix using pthreads without using of global variables.
#define MAX 4
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

 
 
//Each thread computes single element in the resultant matrix.
void Multiply(void arg)
{
    int *Data = (int *)arg;
    int r = 0, w = 0;
     
    int d = Data[0];
    for (w = 1; w <= d; w++)
           r += Data[w]*Data[w+d];
     
    int q = (int)malloc(sizeof(int));
         *q = r;
     
//Used to terminate a thread and the return value is passed as a pointer
    pthread_exit(q);
}
 
//Driver code
void main()
{
 
    int matA[MAX][MAX];
    int matB[MAX][MAX];
     
     
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,x,y,z;
 
 
    // Generating random values in matA
    for (x = 0; x < r1; x++)
            for (y = 0; y < c1; y++)
                   matA[x][y] = rand() % 10;
           
        // Generating random values in matB
    for (x = 0; x < r1; x++)
            for (y = 0; y < c1; y++)
                   matB[x][y] = rand() % 10;
    
    // Displaying matA        
    for (x = 0; x < r1; x++){
        for(y = 0; y < c1; y++)
            printf("%d ",matA[x][y]);
        printf("\n");
    }
             
    // Displaying matB               
    for (x = 0; x < r2; x++){
        for(y = 0; y < c2; y++)
            printf("%d ",matB[x][y]);
        printf("\n");   
    }
      
     
    int max = r1*c2;
     
     
    //declaring array of threads of size r1*c2       
    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));
     
    int count = 0;
    int* data = NULL;
    for (x = 0; x < r1; x++)
        for (y = 0; y < c2; y++)
               {
                
               //storing row and column elements in data
            data = (int *)malloc((20)*sizeof(int));
            data[0] = c1;
     
            for (z = 0; z < c1; z++)
                data[k+1] = matA[x][z];
     
            for (z = 0; z < r2; z++)
                data[z+c1+1] = matB[z][y];
              
     //creating threads

    pthread_create(&threads[count++], NULL,
			{
                         mult, (void*)(data));
                 
                    }
     
    printf("RESULTANT MATRIX IS :- \n");
    for (x = 0; x < max; x++)
    {
      void *z;
       
      //joining all threads and collecting return value.

      pthread_join(threads[x], &z);
            
           
          int *p = (int *)z;
      printf("%d ",*p);
      if ((x + 1) % c2 == 0)
          printf("\n");
    }
 
     
 
  }