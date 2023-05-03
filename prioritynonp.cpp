#include<bits/stdc++.h>
using namespace std;
void priority_non_preemptive(int at[],int bt[],int wt[],int tat[],int priority[],int n){
int c=0;
int t=0;
vector<bool>done(n,false);
while(c<n){
   
    int pro=INT_MAX;
    int a=-1;
    for(int i=0;i<n;i++){
if(!done[i]&&t>=at[i]&&pro>priority[i]){

pro=priority[i];
a=i;
}}
if(a!=-1){
wt[a]=t-at[a];
tat[a]=t+bt[a]-at[a];
t+=bt[a];
c++;
done[a]=true;
}
else
t++;
}
cout<<t<<endl;
cout<<"PId\t"<<"AT\t"<<"BT\t"<<"WT\t"<<"TAT\t"<<endl;
for(int i=0;i<n;i++){
    cout<<"P"<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
}
}
int main(){
    int n;
    cout<<"enter the number of processes "<<endl;
    cin>>n;
    int at[n],bt[n],wt[n],tat[n];
    int priority[n];
    cout<<"enter the arrival time "<<endl;
    for(int i=0;i<n;i++)
    cin>>at[i];
    cout<<"enter the burst time "<<endl;
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    cout<<"enter the priorities "<<endl;
    for(int i=0;i<n;i++)
    cin>>priority[i];
    cout<<"executing algo "<<endl;
    priority_non_preemptive(at,bt,wt,tat,priority,n);
     float awt=0;
    float atat=0;
     for(int i=0;i<n;i++){
    awt+=(wt[i]);
    atat+=(tat[i]);
  }
  awt=float(awt/n);
  atat=float(atat/n);
  cout<<"average waiting time is "<<awt<<" and average turnaround time is "<<atat<<endl;
}