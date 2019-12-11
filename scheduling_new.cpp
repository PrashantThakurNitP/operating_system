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
//int prev=0;
//vector<int>
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
struct data temp;
for(int i=0;i<n-1;i++)
  {
      for(int j=i+1;j<n;j++)
      {
        if(v1[i].at > v1[j].at)
          {
            temp=v1[i];
            v1[i]=v1[j];
            v1[j]=temp;
          } 
       
      }
  }
int prev=0;
for(int i=0;i<n;i++)
{
//cout<<" enter ariival time burst time";
//cin>>d1.at
//cin>>d1.bt
/*if(i==0)
{
v1[i].ct=v1[i].at+v1[i].bt;
prev=v1[i].ct;
v1[i].tat=v1[i].ct-v1[i].at;
v1[i].wt=0;
}
else
{*/
 v1[i].ct=max(prev,v1[i].at)+v1[i].bt;
 prev=v1[i].ct;
 v1[i].tat=v1[i].ct-v1[i].at;
 v1[i].wt=v1[i].tat-v1[i].bt;
//}

//v1[i].tat=v1[i].ct-d1.at;
//v1[i].wt=v1[i].tat-v1[i].bt;
//v1.push_back(d1);
}
int avg_tat=0;
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


}//main ends
