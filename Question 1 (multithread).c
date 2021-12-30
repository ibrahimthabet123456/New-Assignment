
#include<stdio.h>
#include<malloc.h>
void main()
{


  Summing implements Runnable 
{

    int x;

     Summing(int x) 
{
   this.x = x;
 }  	

     void run() 
	{
        addRondom();
	 }

     void addRondom() 
{
        Random rand = new Random();
        int n = rand.nextInt(10) + 1;
        printif("number generated: " + n);
        synchronized (this) 
	{
            x += n;
        }
    }
}






 static void main(String[] args) {
    int Base = 0;

    Summing sum2 = new Summing(Base);

    Thread T1 = new Thread(sum2);
    Thread T2 = new Thread(sum2);
    Thread T3 = new Thread(sum2);
    Thread T4 = new Thread(sum2);
    Thread T5 = new Thread(sum2);

    T1.start();
    T2.start();
    T3.start();
    T4.start();
    T5.start();

    try 
	{
        T1.join();
        T2.join();
        T3.join();
        T4.join();
        5.join();
   catch (InterruptedException e)
}
 
{
        e.printStackTrace();
    }

    System.out.print("final result: " + sum2.x);
}