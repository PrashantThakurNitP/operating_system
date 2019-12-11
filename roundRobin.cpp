#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct data{
	float at;
	int bt;
	int ct;
	int tat;
	int wt;
};

void roundRobin(vector<data>&v1,int n,float *avg_tat,float *avg_wt,int t_time)
{
 // cout<<"    inside ROUND ROBIN fn   "<<endl;
  int tq;
  cout<<"Enter time quantum "<<endl;
  cin>>tq;//time quantum
  vector<data>v2(n);
  v2=v1;
int jump=0;//time upto which to check
int prev=0;
int count=0;
int time=0;
*avg_tat=0;
 *avg_wt=0;
while(time<t_time)//RUN AS MANY TIME AS THAT OF BURST TIME/TIME QUANTUM
{
  struct data temp_min=v1[0];
  float at_min=20000;
  int u1=0;
  int flag=0;
  for( int u=0;u<n;u+=1)//CHOSING MINIMUM ARIVAL TIME AMONG AVAILABLE PROCESS TILL TIME JUMP
  {
    
    if(v2[u].at<at_min && v2[u].at<=float(jump))
      {
        at_min=v2[u].at;
        temp_min=v2[u];
        u1=u;
        flag=1;//means process found
        
      }
      //set time upto which to sort
     
  }//finding min at each time
    // v2[u1].bt=20000;
    jump=min(jump+tq,jump+v2[u1].bt);//UPDATING JUMP UPTO WHERE TO SEARCH
    time=jump;
    if(flag)//IF TILL TIME JUMP ANY PROCESS FOUND
    {
      v2[u1].bt-=min(v2[u1].bt,tq);//REMAINING BURST TIME
      if(v2[u1].bt>0)//IF PROCESS IS STILL REMAINING
         v2[u1].at=jump+0.5;//push at end of queue this process start when all other process completes at least once
      else
      {
         v2[u1].at=20000;//random large value 
         v1[u1].ct=time;//PROCESS HAS FINISHED
         cout<<"Process P"<<u1+1<<"  complete at "<<time<<endl;
      }
     //  cout<<"Process P"<<u1+1<<" burst time "<<v1[u1].bt<<" jump = "<<jump<<endl;
      
       count+=1;//how mant time context switch occured
    }
    else
    time++;
}
  for(int i=0;i<n;i++)//CALCULATION
  {

      v1[i].tat=v1[i].ct-v1[i].at;
      v1[i].wt=v1[i].tat-v1[i].bt;
      //v1[i].wt=v1[i].tat-v1[i].bt;
      cout<<"process P"<<i+1<<" arrival time "<<v1[i].at<<" burst time "<<v1[i].bt;
      cout<<" turn around time "<<v1[i].tat<<"  waiting time "<<v1[i].wt<<endl;
      *avg_tat+=v1[i].tat;
      *avg_wt+=v1[i].wt;
  }
    *avg_tat/=n;
    *avg_wt/=n;

}//main ends

int main()
{

 cout<<" ROUND ROBIN"<<endl;
cout<<"Enter no of process : ";
int n;
cin>>n;
vector<data>v1(n);
vector<data>v2(n);
int total_time=0;
struct data a1;
for(int i=0;i<n;i++)
{
cout<<" Enter arival time  and burst time  ";
cin>>a1.at;
cin>>a1.bt;
total_time+=a1.bt;
a1.ct=0;
a1.tat=0;
a1.wt=0;
v1[i]=a1;
}
float avg_tat=0;
float avg_wt=0;


	
	
	  		 roundRobin(v1,n,&avg_tat,&avg_wt,total_time);
	  



cout<<"avg_tat  =  "<<avg_tat<<endl;
cout<<"avg_wt   =  "<<avg_wt<<endl;

}//main ends

