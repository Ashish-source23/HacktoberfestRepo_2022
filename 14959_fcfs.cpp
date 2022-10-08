#include<iostream>
 
using namespace std;
 
int main()
{
    int n,bt[20],wt[20],tat[20],avgwt=0,avgtat=0,i,j;
    cout<<"Enter total number of processes:  ";
    cin>>n;
 
    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
 
    wt[0]=0;    //waiting time for first process
 
    //waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];        //waiting time + burst time of previous process  
    }
 
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];      //burst time + waiting time
        avgwt+=wt[i];			 //average waiting time
        avgtat+=tat[i];			 //average turnaround time
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
 
    avgwt/=i;    		//average waiting time
    avgtat/=i;			//average turnaround time
    cout<<"\n\nAverage Waiting Time:"<<avgwt;
    cout<<"\nAverage Turnaround Time:"<<avgtat;
 
    return 0;
}
