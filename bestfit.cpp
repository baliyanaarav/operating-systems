#include<iostream>
using namespace std;
void fixed(int block[],int process[],int m,int n){
int allocated[m];
int inf=0;
for(int i=0;i<m;i++)
allocated[i]=-1;
cout<<"P.No\t\tB.No\t\tP.Size\t\tB.size"<<endl;
for(int i=0;i<n;i++){
    int index=-1;
    for(int j=0;j<m;j++){
        if(allocated[j]==-1&&block[j]>process[i]){
           
            if(index==-1){

            index=j;
            inf+=(block[j]-process[i]);
            break;}
            
        }}
        if(index==-1){
          continue;
        }
        else{
          allocated[index]=1;
          cout<<i+1<<"\t\t"<<index+1<<"\t\t"<<process[i]<<"\t\t"<<block[index]<<endl;
        }
    }
  cout<<"Internal Fragmentation is "<<inf<<endl;
}
void best_fit(int block[],int process[],int m,int n){
int allocated[m];
for(int i=0;i<m;i++)
allocated[i]=-1;
cout<<"P.No\t\tB.No\t\tP.Size\t\tB.size"<<endl;
for(int i=0;i<n;i++){
    int index=-1;
    for(int j=0;j<m;j++){
        if(allocated[j]==-1&&block[j]>process[i]){
            if(index!=-1&&block[index]>block[j]){
                index=j;
            }
            if(index==-1)
            index=j;
            
        }}
        if(index==-1){
          cout<<"P"<<i+1<<" has to wait"<<endl;
        }
        else{
          allocated[index]=1;
          cout<<i+1<<"\t\t"<<index+1<<"\t\t"<<process[i]<<"\t\t"<<block[index]<<endl;
            block[index]-=process[i];
        }
    }

}
void worst_fit(int block[],int process[],int m,int n){
int allocated[m];
for(int i=0;i<m;i++)
allocated[i]=-1;
cout<<"P.No\t\tB.No\t\tP.Size\t\tB.size"<<endl;
for(int i=0;i<n;i++){
    int index=-1;
    for(int j=0;j<m;j++){
        if(allocated[j]==-1&&block[j]>process[i]){
            if(index!=-1&&block[index]<block[j]){
                index=j;
            }
            if(index==-1)
            index=j;
            
        }}
        if(index==-1){
          cout<<"P"<<i+1<<" has to wait"<<endl;
        }
        else{
          allocated[index]=1;
          cout<<i+1<<"\t\t"<<index+1<<"\t\t"<<process[i]<<"\t\t"<<block[index]<<endl;
            block[index]-=process[i];
        }
    }

}
void first_fit(int block[],int process[],int m,int n){
int allocated[m];
for(int i=0;i<m;i++)
allocated[i]=-1;
cout<<"P.No\t\tB.No\t\tP.Size\t\tB.size"<<endl;
for(int i=0;i<n;i++){
    int index=-1;
    for(int j=0;j<m;j++){
        if(allocated[j]==-1&&block[j]>process[i]){
           
            if(index==-1){

            index=j;
            break;}
            
        }}
        if(index==-1){
         cout<<"P"<<i+1<<" has to wait"<<endl;
        }
        else{
          allocated[index]=1;
          cout<<i+1<<"\t\t"<<index+1<<"\t\t"<<process[i]<<"\t\t"<<block[index]<<endl;
          block[index]-=process[i];
        }
    }

}
int main(){
int n;
cout<<"enter the number of processes "<<endl;
cin>>n;
int process[n];
cout<<"enter size of processes "<<endl;
for(int i=0;i<n;i++)
cin>>process[i];
int m;
cout<<"enter the number of blocks "<<endl;
cin>>m;
int block[m];
cout<<"enter size of blocks "<<endl;
for(int i=0;i<m;i++)
cin>>block[i];
cout<<"enter your choice (1 for fixed partitioning 2 for variable partitioning )"<<endl;
int x;
cin>>x;
if(x==1){
    cout<<"fixed partitioning "<<endl;
fixed(block,process,m,n);

}
else if(x==2){
    cout<<"variable  partitioning "<<endl;
int y;
cout<<"enter your choice (1 for best_fit  2 for worst_fit 3 for first_fit)"<<endl;
cin>>y;
if(y==1){
    cout<<"BEST FIT"<<endl;
best_fit(block,process,m,n);
}
else if(y==2){
    cout<<"WORST FIT"<<endl;
worst_fit(block,process,m,n);
}
else if(y==3){
    cout<<"FIRST FIT"<<endl;
first_fit(block,process,m,n);
}
else{
    cout<<"enter valid choice "<<endl;
}
}
else{
    cout<<"valid choice "<<endl;
}
    return 0;
}