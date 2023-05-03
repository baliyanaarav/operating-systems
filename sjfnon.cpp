#include<bits/stdc++.h>
using namespace std;
void sjf(vector<pair<int,pair<int,int>>>v,int n,int wt[],int tat[]){
int ct=0;
int complete=0;
bool check=false;
int minm=INT_MAX;
int shortest=0;
int finish_time=0;
vector<int>rt(n);
for( int i=0;i<n;i++){
    rt[i]=v[i].second.second;
}
while(complete!=n){
    for(int i=0;i<n;i++){
        if(v[i].second.first<=ct&&rt[i]<minm&&rt[i]>0){
            shortest=i;
            minm=rt[i];
            check=true;
        }}
        if(check==false){
            ct++;
            continue;
        }
        
           ct+=rt[shortest];
           rt[shortest]=0;
            minm=INT_MAX;
            complete++;
            check=false;
            
            
            wt[shortest]=ct-v[shortest].second.second-v[shortest].second.first;
            if(wt[shortest]<0)
            wt[shortest]=0;
        
       
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+v[i].second.second;
    }
    cout<<"pid\t\t"<<"AT\t\t"<<"BT\t\t"<<"WT"<<"TAT"<<endl;
    for(int i=0;i<n;i++){
    cout<<"p"<<v[i].first<<"\t\t"<<v[i].second.first<<"\t\t"<<v[i].second.second<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    
  }
    float awt=0,atat=0;
  for(int i=0;i<n;i++){
    awt+=wt[i];
    atat+=tat[i];
  }
  awt=float(awt/n);
  atat=float(atat/n);
  cout<<"average waiting time is "<<awt<<" and average turnaround time is "<<atat<<endl;
}
int main(){ 
   int n;
  cout<<"enter the number of processes"<<endl;
  cin>>n;
  vector<pair<int,pair<int,int>>>v;
  cout<<"sjf non preemptive algorithm"<<endl;
 for(int i=0;i<n;i++){
    int a;
    int b;
    int c;
    cout<<"enter the pid "<<endl;
    cin>>c;
    cout<<"enter the arrival time and burst time for process "<<c<<endl;
    cin>>a>>b;
    v.push_back(make_pair(c,make_pair(a,b)));
  }
  int wt[n];
  int tat[n];
  sjf(v,n,wt,tat);
  
  return 0;
  }