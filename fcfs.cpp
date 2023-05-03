#include<bits/stdc++.h>

using namespace std;
bool cmp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
  return a.second.first<b.second.first;
}
void findwaitingtime(vector<pair<int,pair<int,int>>>v,int n,int wt[]){
  int i=1;
  for(;i<n;i++){
    wt[i]=v[i-1].second.second+wt[i-1];
  }
}
void findtat(vector<pair<int,pair<int,int>>>v,int n,int tat[]){
  tat[0]=v[0].second.second;
  for(int i=1;i<n;i++){
    tat[i]=tat[i-1]+v[i].second.second;
  }
}
void fcfs(vector<pair<int,pair<int,int>>>v,int n,int wt[],int tat[]){
  
  sort(v.begin(),v.end(),cmp);
  wt[0]=0;
  findwaitingtime(v,n,wt);
  findtat(v,n,tat);
  cout<<"pid\t\t"<<"AT\t\t"<<"BT\t\t"<<"WT\t\t"<<"TAT"<<endl;
  for(int i=0;i<n;i++){
    cout<<"p"<<v[i].first<<"\t\t"<<v[i].second.first<<"\t\t"<<v[i].second.second<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
  }
}
int main(){ 
   int n;
  cout<<"enter the number of processes"<<endl;
  cin>>n;
  vector<pair<int,pair<int,int>>>v;
  cout<<"fcfs algorithm"<<endl;
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
  fcfs(v,n,wt,tat);
  float awt=0,atat=0;
  for(int i=0;i<n;i++){
    awt+=(wt[i]-v[i].second.first);
    atat+=(tat[i]-v[i].second.first);
  }
  awt=float(awt/n);
  atat=float(atat/n);
  cout<<"average waiting time is "<<awt<<" and average turnaround time is "<<atat<<endl;
  return 0;
  }