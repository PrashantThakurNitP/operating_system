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
};

int main()
{
cout<<"Enter no of process ";
int n;
cin>>n;
vector<data>v1(n);
vector<data>v2(n);
//int prev=0;
//vector<int>
//int total_ctime=0;//to complete
struct data d1;
for(int i=0;i<n;i++)
{
cout<<" enter ariival time burst time ";
cin>>d1.at;
cin>>d1.bt;

d1.ct=0;
d1.tat=0;
d1.wt=0;
v1[i]=d1;
}
v2=v1;//copying
int jump=0;//time upto which to check

int count=0;
int prev=0;

int avg_tat=0;
int avg_wt=0;
//nt prev=0;
while(count<n)
{
  struct data temp_min=v1[0];
  int bt_min=20000;
  
  //cout<<" count = "<<count<<endl;//comment
  int u1=0;
  for( int u=0;u<n;u+=1)
  {
    
    if(v2[u].bt<bt_min && v2[u].at<=jump)
      {
        bt_min=v2[u].bt;
        temp_min=v2[u];
        u1=u;
        
      }
      //set time upto which to sort
     
  }//finding min at each time
     v2[u1].bt=20000;
     v2[u1].at=10000; 
     cout<<" min bt "<<v1[u1].bt<<" jump = "<<jump<<"u1 = "<<u1<<endl;
      v1[u1].ct=max(prev,v1[u1].at)+v1[u1].bt;
      prev=v1[u1].ct;//updated for next
      jump=max(v1[u1].ct,jump);
      v1[u1].tat=v1[u1].ct-v1[u1].at;
      v1[u1].wt=v1[u1].tat-v1[u1].bt;
      
      avg_tat+=v1[u1].tat;
      avg_wt+=v1[u1].wt;

     // cout<<" turn around time "<<v1[u1].tat<<"  waiting time "<<v1[u1].wt<<" arrival time "<<v1[u1].at<<" burst time "<<v1[u1].bt<<endl;
      count+=1;
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
