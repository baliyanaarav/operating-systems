#include<bits/stdc++.h>
using namespace std;
void accomodate(vector<bool>filled,vector<pair<int,int>>partition){
    int m;
cout<<"enter the no of processes "<<endl;
    cin>>m;
    cout<<"enter the processes size "<<endl;
    int inf=0;
    
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        int j=0;
        for( j=0;j<partition.size();j++){
            if(!filled[j]&&partition[j].first>=a){
                filled[j]=true;
                partition[j].second=a;
                cout<<"Internal Fragmentation for P"<<i+1<<" is "<<(partition[j].first-a)<<endl;
                inf+=(partition[j].first-a);
                break;
            }
        }
        if(j==partition.size()){
           
          cout<<"P"<<i+1<<" cant be allocated "<<endl;
        }
        else{
            cout<<"P"<<i+1<<" allocated "<<endl;
        }
    }
    cout<<"Total Internal Fragmentation is "<<inf<<endl;
}
int main(){
    int size;
    cout<<"enter the memory size "<<endl;
    cin>>size;
    int n;
    cout<<"enter the no of partitions "<<endl;
    cin>>n;
    cout<<"Is size of every paritition same ?(enter Y/N)"<<endl;
    char ans;
    cin>>ans;
    vector<pair<int,int>>partition(n,make_pair(0,0));
    vector<bool>filled(n,false);
    if(ans=='Y'){
        for(int i=0;i<n;i++)
    {
        
        partition[i].first=(size/n);
        filled[i]=false;
    }
    }
    else{
     cout<<"enter the partition sizes "<<endl;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        partition[i].first=a;
        filled[i]=false;
    }
    }
  accomodate(filled,partition); 
}