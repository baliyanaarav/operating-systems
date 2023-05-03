#include<bits/stdc++.h>
using namespace std;
void solve(int trackreq[],int n,int init,int start,int end){
int trackchange=0;
sort(trackreq,trackreq+n);
trackchange+=(end-init);
trackchange+=(end-start);
vector<int>sequence;
int a;
for( a=0;a<n;a++){
    if(trackreq[a]>init){
        break;
    }
}
for(int i=a;i<n;i++){
    sequence.push_back(trackreq[i]);
}
trackchange+=(trackreq[a-1]-start);
for(int i=a-1;i>=0;i--){
    sequence.push_back(trackreq[i]);
}

cout<<"Sequenece of adressing the requests is "<<endl;
for(int i=0;i<sequence.size();i++)
cout<<sequence[i]<<" ";
cout<<endl;
cout<<trackchange<<endl;
}
int main(){
    int start,end;
    cout<<"enter the starting and ending track no "<<endl;
    cin>>start>>end;
    int init;
    cout<<"enter the initial postion of read write head "<<endl;
    cin>>init;
    int n; 
    cout<<"enter the no of track requests "<<endl;
    cin>>n;
     cout<<"enter the track requests "<<endl;
    int trackreq[n];
    for(int i=0;i<n;i++){
     cin>>trackreq[i];
     if(trackreq[i]<start||trackreq[i]>end){
        cout<<"enter valid "<<endl;
        i--;
     }
    }
    solve(trackreq,n,init,start,end);

}