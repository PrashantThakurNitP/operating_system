#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct data
{
 int at;
 int bt;
 int ct;//completion time
 int tat;//ct-at
 int wt;//tat-wt
 //int pt;
};

int main()
{
cout<<"Enter no of process ";
int n;
cin>>n;
int tq;
cout<<"Enter time quantum "<<endl;
cin>>tq;//time quantum
vector<data>v1(n);
vector<data>v2(n);
//int prev=0;
//vector<int>
//int total_ctime=0;//to complete
struct data d1;
int t_time=0;
for(int i=0;i<n;i++)
{
cout<<" enter arival time burst time ";
cin>>d1.at;
cin>>d1.bt;
//cin>>d1.pt;
t_time+=d1.bt;
d1.ct=0;
d1.tat=0;
d1.wt=0;
v1[i]=d1;
}
v2=v1;//copying
int jump=0;//time upto which to check


int prev=0;

float avg_tat=0;
float avg_wt=0;
//nt prev=0;
//int time=0;
int count=0;
int time=0;
while(time<t_time)
{
  struct data temp_min=v1[0];
  int at_min=20000;
  
  //cout<<" count = "<<count<<endl;//comment
  int u1=0;
  int flag=0;
  for( int u=0;u<n;u+=1)
  {
    
    if(v2[u].at<at_min && v2[u].at<=jump)
      {
        at_min=v2[u].at;
        temp_min=v2[u];
        u1=u;
        flag=1;
        
      }
      //set time upto which to sort
     
  }//finding min at each time
    // v2[u1].bt=20000;
     jump=min(jump+tq,v2[u1].at+v2[u1].bt);
     if(flag)
     {
      v2[u1].bt-=min(v2[u1].bt,tq);
      if(v2[u1].bt>0)
     v2[u1].at=tq*n+count;//push at end of queue
     else
     {
      v2[u1].at=20000;//random large value 
       v1[u1].ct=time+1;
       cout<<"Process P"<<u1+1<<"  complete at "<<time<<endl;
    }
     
    
     cout<<"Process P"<<u1+1<<" burst time "<<v1[u1].bt<<" jump = "<<jump<<endl;
      //v1[u1].ct=max(prev,v1[u1].at)+v1[u1].bt;
     v1[u1].ct=v1[u1].ct+min(tq,v2[u1].bt);
    //  prev=v1[u1].ct;//updated for next
      
      //v1[u1].tat+=min(v2[u1].bt,tq);//v1[u1].ct-v1[u1].at;

      time+=tq;
       count+=1;
      }

     // cout<<" turn around time "<<v1[u1].tat<<"  waiting time "<<v1[u1].wt<<" arrival time "<<v1[u1].at<<" burst time "<<v1[u1].bt<<endl;
  //time+=tq;//time quantum    
}
for(int i=0;i<n;i++)
{

  v1[i].tat=v1[i].ct-v1[i].at;
      v1[i].wt=v1[i].tat-v1[i].bt;
  v1[i].wt=v1[i].tat-v1[i].bt;
  cout<<"process P"<<i+1<<" arrival time "<<v1[i].at<<" burst time "<<v1[i].bt<<" turn around time "<<v1[i].tat<<"  waiting time "<<v1[i].wt<<endl;
  avg_tat+=v1[i].tat;
      avg_wt+=v1[i].wt;
}
avg_tat/=n;
avg_wt/=n;
cout<<"avg_tat  =  "<<avg_tat<<endl;
cout<<"avg_wt   =  "<<avg_wt<<endl;
/*nt avg_tat=0;
int avg_wt=0;
for(int i=0;i<n;i++)
{
cout<<" turn around time "<<v1[i].tat<<"  waiting time "<<v1[i].wt<<" arrival time "<<v1[i].at<<" burst time "<<v1[i].bt<<endl;
avg_tat+=v1[i].tat;
avg_wt+=v1[i].wt;


}
avg_tat/=n;
avg_wt/=n;
cout<<"avg_tat  =  "<<avg_tat<<endl;
cout<<"avg_wt   =  "<<avg_wt<<endl;

*/
}//main ends
