#include<bits/stdc++.h>
using namespace std;
void fcfs(vector<int>request,int current,int n){
    int count=0;
    count+=abs(current-request[0]);
    for(int i=1;i<n;i++){
        count+=abs(request[i]-request[i-1]);
    }
    cout<<count<<endl;
    cout<<"Seek sequence is "<<endl;
    for(int i=0;i<n;i++){
        cout<<request[i]<<" ";
    }
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
        if(a<starting||a>ending){
            cout<<"please enter valid track request "<<endl;
            i--;
            continue;
        }
        request.push_back(a);
    }
    cout<<"Total no of tracks movement in fcfs is ";
    fcfs(request,current,n);
    return 0;
}