#include<bits/stdc++.h>
using namespace std;
bool hit(vector<int> &frame,int a){
for(int i=0;i<frame.size();i++){
    if(frame[i]==a)
    return true;
}
return false;
}
int predict(vector<int> frame,vector<int> sequence,int a){
    int farthest=-1;
    int result=-1;
    int i,j;
    for(i=0;i<frame.size();i++){
        for(j=a+1;j<sequence.size();j++){
            if(frame[i]==sequence[j]){
                if(j>farthest){
                farthest=j;
                result=i;
                }
                break;
            }
        }
        if(j==sequence.size())
        return i;
    }
    if(result==-1)
    return 0;
    return result;
}
void place(vector<int>&frame,int a,vector<int>sequence){
    for(int i=0;i<frame.size();i++){
        if(frame[i]==-1){
            frame[i]=sequence[a];
            return;
        }
        
    }
   int b=predict(frame,sequence,a);
   frame[b]=sequence[a];
}
pair<int,int> opr(vector<int>sequence,vector<int> &frame){
int pf=0;
int ht=0;
for(int i=0;i<sequence.size();i++){
    if(hit(frame,sequence[i])){
        ht++;
        continue;
    }
    else{
        pf++;
       place(frame,i,sequence);
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
    pair<int,int>a=opr(sequence,frame);
    cout<<"No of Page Faults is "<<a.first<<" No of Hits is "<<a.second<<endl;
    return 0;
    }