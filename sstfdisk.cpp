#include<bits/stdc++.h>
using namespace std;
void sstf(vector<int> request,int current,int n){
sort(request.begin(),request.end());
vector<int>::iterator it;
it=find(request.begin(),request.end(),current);
int index = it-request.begin();
if(index==0){
    cout<<request[n]-request[0];
    return;
}
if(index==n){
    cout<<request[n]-request[0];
    return;
}
int a=index-1;
int b=index+1;
int seek=0;
vector<int>sequence;
while(a>=0&&b<=n){
if(request[index]-request[a]<request[b]-request[index]){
seek+=abs(request[index]-request[a]);
sequence.push_back(request[a]);
index=a;
a--;

}
else{

seek+=abs(request[index]-request[b]);
sequence.push_back(request[b]);
index=b;

b++;
}
}
if(a<0){
    seek+=abs(request[n]-request[index]);
    for(;b<=n;b++){
        sequence.push_back(request[b]);
    }
}
if(b>n){
    seek+=abs(request[index]-request[0]);
     for(;a>=0;a--){
        sequence.push_back(request[a]);
    }
}
cout<<seek<<endl;
for(int i=0;i<sequence.size();i++)
cout<<sequence[i]<<" ";
}
int main(){
    int starting,ending;
    cout<<"enter the starting and ending cylinders "<<endl;
    cin>>starting>>ending;
    int current;
    cout<<"enter the current position of read write head "<<endl;
    cin>>current;
    int n;
    cout<<"enter the number of tracks request "<<endl;
    cin>>n;
    cout<<"enter the requests "<<endl;
    vector<int>request;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<starting&&a>ending){
            cout<<"please enter valid track request "<<endl;
            i--;
            continue;
        }
        request.push_back(a);
    }
    request.push_back(current);
    cout<<"Total no of tracks movement in sstf is ";
    sstf(request,current,n);
    return 0;
}