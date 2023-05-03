#include<bits/stdc++.h>
using namespace std;
bool hit(vector<int> &frame,int a){
    int i;
for(i=0;i<frame.size();i++){
    if(frame[i]==a)
    {
        
    for(int j=i;j<frame.size()-1;j++)
     frame[j]=frame[j+1];
       frame[frame.size()-1]=a;
       return true;
    }
    
}

return false;


}
void place(vector<int>&frame,int a){
    for(int i=0;i<frame.size();i++){
        if(frame[i]==-1){
            frame[i]=a;
            
            return;
        }
    }
    for(int i=0;i<frame.size()-1;i++)
    frame[i]=frame[i+1];
    frame[frame.size()-1]=a;
}
pair<int,int> lru(vector<int>sequence,vector<int> &frame){
int pf=0;
int ht=0;
for(int i=0;i<sequence.size();i++){
    if(hit(frame,sequence[i])){
        ht++;
        continue;
    }
    else{
        pf++;
       place(frame,sequence[i]);
    }
}
return make_pair(pf,ht);
}
int main(){
    int no_of_frame;
    cout<<"enter the no of frames "<<endl;
    cin>>no_of_frame;
    vector<int>sequence;
    cout<<"enter the sequence (enter -1 when finished )"<<endl;
    while(true){
     int a;
     cin>>a;
     if(a<0)
     break;
     sequence.push_back(a);
    }
    vector<int>frame(no_of_frame,-1);
    pair<int,int>a=lru(sequence,frame);
    cout<<"No of Page Faults is "<<a.first<<" No of Hits is "<<a.second<<endl;
    return 0;
    }