#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	cout<<"Enter no of memory block";
	int m;//no of memory block
	cin>>m;
	cout<<"Enter no of process"<<endl;
	int n;
	cin>>n;//no of process
	vector<int>v1(m,0);
	
	vector<int>v2;
	cout<<"Enter memory block "<<endl;
	for(int i=0;i<m;i++)
	   cin>>v1[i];
	   
	   v2=v1;//copy of v2 in v1
	vector<int>v3(n,0);//process
	cout<<"Enter process "<<endl;
	
	for(int i=0;i<n;i++)
	 cin>>v3[i];
	 
	 int pos1=-1;
	 int pos=0;
	 int flag=0;
	 int flag1=0;
	 for(int i=0;i<n;i++)
	 { 
	   pos=0;
	    flag=0;
	 	 for(int j=0;j<m;j++)//memory is m
	 	 {
	 	 	if(v3[i]<v2[j])//process small than memory
	 	 	{
	 	 		flag=1;
	 	 		pos=j;
	 	 		break;
			  }
		  }
		  pos1=-1;
		  if(pos<m-1 && flag)
		  {
		  	for(int j=pos+1;j<m;j++)
	 	    {
	 	 	if(v3[i]<v2[j])//process small than memory
	 	 	{
	 	 		flag1=1;
	 	 		pos1=j;
	 	 		cout<<"Next fit for process "<<v3[i]<<" is "<<v2[j]<<endl;
	 	 		break;
			  }
		 }
		  }
		  else
		  {
		  	cout<<"No next fit for process"<<v3[i]<<endl;
		  }
		  
		  v2[pos1]=0;
		  
	 	
	 }//block for process
	 
	
}
