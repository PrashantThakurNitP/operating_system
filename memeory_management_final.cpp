#include<bits/stdc++.h>
//           PRASHANT THAKUR
//            1706001
//           MEMORY MANAGEMENT
using namespace std;
int main()
{      
cout<<"MEMORY MANAGEMENT ROLL 1706001"<<endl;
	cout<<"Enter no of memory block  ";
	int n;
	cin>>n;;
	cout<<"Enter no of process  ";
	int m;
	cin>>m;
	vector<int>memory(n,0);
	vector<int>process(m,0);
	cout<<"Enter memeory block size"<<endl;
	for(int i=0;i<n;i++)
		cin>>memory[i];
	cout<<"Enter process size"<<endl;
	for(int i=0;i<m;i++)
		cin>>process[i];
		
			vector<int>memory1;
			vector<int>memory2;
			vector<int>memory3;
			vector<int>memory4;
			memory1=memory;//first
			memory2=memory;//best
			memory3=memory;//next
			memory4=memory;//worst
		
	//	cout<<"Enter 1 to print first  best next and worst"
//	cout<<"Enter 1 for first 2 for best 3 for next 4 for worst"<<endl;
//	int a;
	//cin>>a;
	int pos1=-1;  
	
	bool flag=0;int min1,max1,pos;
	switch(1)
	{
       case 1://first
       
       for(int i=0;i<m;i++)//m reprseent no of process
       {
       	 flag=0;
       	for(int j=0;j<n;j++)
       	{
          if(memory1[j]>process[i])
          {
          	cout<<memory1[j]<<" is the first fit for the process "<<process[i]<<endl;
          	memory1[j]=0;
          	
          	flag=1;
          	break;
          }
       	}
       	 if(!flag)
       	cout<<"No first fit for  "<<process[i]<<endl;
       }
      

     //  break;
	cout<<endl;
	
       case 2://best fit
       for(int i=0;i<m;i++)
       {
       	 min1=9999;
       	 flag=0;
       	 pos1=-1;
       	for(int j=0;j<n;j++)
       	{
          if(memory2[j]>process[i] && memory2[j]<min1)
          {
          	min1=memory2[j];
          	flag=1;
          	pos1=j;
          	//
          	//break;
          }
       	}
       	if(flag)
       	{
		   
       	cout<<min1<<" is the best fit for the process "<<process[i]<<endl;
       	memory2[pos1]=0;//utilized
       }
       else cout<<"no best fit for "<<process[i]<<endl;
       }

       //break;
       cout<<endl;
       
       case 3://next fit

      ////
      pos=0;
      flag=0;
       for(int i=0;i<m;i++)//no of process m
	 { 
	  // pos=0;
	    flag=0;
	 	 for(int j=pos;j<n;j++)//memory is n
	 	 {
	 	 	if(process[i]<memory[j])//process small than memory
	 	 	{
	 	 		flag=1;
	 	 		pos=j+1;
	 	 		cout<<"Next fit for process "<<process[i]<<" is "<<memory[j]<<endl;
	 	 		
	 	 		break;
			  }
		  }
		  if(!flag)
		  {
		  	cout<<"No next fit for process"<<process[i]<<endl;
		  }
		  
		 // v2[pos1]=0;
		  
	 	
	 }//block for process
	 
      cout<<endl;
       case 4://worst fit
       	pos1=-1;
        for(int i=0;i<m;i++)
       {
       	 max1=0;
       	 flag=0;
       	 pos1=-1;
       	for(int j=0;j<n;j++)
       	{
          if(memory4[j]>process[i] && memory4[j]>max1)
          {
          	max1=memory4[j];
          	pos1=j;
          	flag=1;
          	//
          	//break;
          }
       	}
       	if(flag)
       	{
       		memory4[pos1]=0;
       		cout<<max1<<" is the worst fit for the process "<<process[i]<<endl;
		   }
       	
       else cout<<"no worst  fit for process "<<process[i]<<endl;
       }

       break;
	}
}

