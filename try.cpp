#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>avail,int need[]){
for(int i=0;i<avail.size();i++){
   
    if(need[i]>avail[i])
    return false;
}
return true;
}
void sum(vector<int> &avail,int need[]){
    for(int i=0;i<avail.size();i++){
        avail[i]+=need[i];
    }
}
int main(){
    int n;
    cout<<"enter the number of processes "<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of resources "<<endl;
    cin>>m;
    int alloc[n][m];
    int max[n][m];
    
    vector<int>avail(m);
  
 
   int need[m][n];
  
 
    vector<bool>flag(n,false);
    cout<<"enter the max matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>max[i][j];
    }
    cout<<"enter the allocated matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>alloc[i][j];
    }
    cout<<"enter the available instances of resources "<<endl;
    for(int i=0;i<m;i++)
    cin>>avail[i];
    cout<<"the need matrix is "<<endl;
    vector<string>sequence;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        need[i][j]=max[i][j]-alloc[i][j];
    }
    while(true){
        int pt=INT_MAX;
        for(int i=0;i<n;i++){
            if(flag[i]==false&&cmp(avail,need[i])){
                
                pt=i;
                sum(avail,alloc[i]);
                flag[i]=true;
                 sequence.push_back("P"+to_string(i));

            }
            
        }
        if(pt==INT_MAX)
        goto abc;
    }
    abc:
     for(int i=0;i<m;i++){
        if(flag[i]==false){
            cout<<"safe sequence doesn't exist "<<endl;
            exit(0);
        }
     }
     cout<<"safe sequence is "<<endl;
     for(int i=0;i<sequence.size();i++)
     cout<<sequence[i]<<" ";
    return 0;
}