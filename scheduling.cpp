#include<iostream>
#include<vector>
using namespace std;
struct data
{
 int at;
 int bt;
 int ct;//completion time
 int tat;//ct-at
 int wt;//tat-wt
}

int main()
{
cout<<"Enter no of process";
int n;
cin>>n;
vector<data>v1;
int prev=0;
//vector<int>
struct data d1;
for(int i=0;i<n;i++)
{
cout<<" enter ariival time burst time";
cin>>d1.at
cin>>d1.bt
if(i==0)
{
d1.ct=d1.at+d1.bt;
prev=d1.ct;
}
else
{
 d1.ct=prev+d1.bt;
 prev=d1.ct;
}

d1.tat=ct-d1.ct-d1.bt;
d1.wt=d1.tat-d1.bt;
v1.push_back(d1);
}
int avg_tat=0;
int avg_wt=0;
for(int i=0;i<n;i++)
{
avg_tat+=v1[i].tat;
avg_wt+=v1[i].wt;


}
avg_tat/=n;
avg_wt/=n;
cout<<"avg_tat = "<<avg_tat<<endl;
cout<<"avg_wt = "<<avg_wt<<endl;


}//main ends
