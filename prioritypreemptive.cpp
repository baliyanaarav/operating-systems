#include<iostream>
using namespace std;
void solve(int at[],int bt[],int wt[],int tat[],int left[],int priority[],int n){
    int c=0;
    int t=0;
    while(c<n){
        int pro=100000;
        int a=-1;
        for(int i=0;i<n;i++){
            if(left[i]!=0&&t>=at[i]&&pro>priority[i]){
                pro=priority[i];
                a=i;
            }
        }
        if(a!=-1){
          
          if(left[a]==1)
          wt[a]=t-(bt[a]-1)-at[a];
          left[a]--;
          if(left[a]==0){
          tat[a]=t+1-at[a];
          c++;}
        }
        
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
    cout<<"enter the no of processes "<<endl;
    cin>>n;
    int at[n],bt[n],priority[n],left[n],wt[n],tat[n];
    cout<<"enter the arrival time "<<endl;
    for(int i=0;i<n;i++)
    cin>>at[i];
    cout<<"enter the burst time "<<endl;
    for(int i=0;i<n;i++){
    cin>>bt[i];
    left[i]=bt[i];}
    cout<<"enter the priorities "<<endl;
    for(int i=0;i<n;i++)
    cin>>priority[i];
    solve(at,bt,wt,tat,left,priority,n);
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