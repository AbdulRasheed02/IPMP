#include<iostream>
#include<iterator>
#include<map>
#include<iomanip> 
#include<cmath>
#include<vector>
#include<utility>
#include<unordered_map>
#include<stack>

using namespace std;
int main(){
    map<int,int> m1;
    m1.insert(pair<int,int>(3,5));
    m1.insert(pair<int,int>(3,8));
    m1.insert(pair<int,int>(4,8));
    m1.insert(pair<int,int>(5,9));

    map<int, int>::iterator itr;
    for(itr=m1.begin();itr!=m1.end();itr++){
        cout<<itr->first<<itr->second<<endl;
    }

    int n,sum;
    cin>>n;
    vector<int> v (n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2==1){
        cout<<"NO";
        return 0;
    }
    map<int,int> a,b;
    a[v[0]]=1;
    for(int i=1;i<n;i++){
        b[v[i]]++;
    }
    int sdash;
    for(int i=0;i<n;i++){
        sdash+=v[i];
        if(sdash==(sum/2)){
            cout<<"YES";
            return 0;
        }
        if(sdash>sum/2){
            int x=sdash-sum/2;
            if(a[x]>0){
                cout<<"YES";
                return 0;
            }
        }
        else{
            int x=sum/2-sdash;
            if(b[x]>0){
                cout<<"YES";
                return 0;
            }

        }
        a[v[i+1]]++;
        b[v[i+1]]--;

    }
    cout<<"NO"<<endl;

    string s;
    stack<char> stck;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stck.push(s[i]);
        }
        else if (s[i]==')' || s[i]=='}' || s[i]==']'){
            if(stck.empty()){
                cout<<"Not Balanced";
                return 0;
            }
            char c=s[i];
            if((c==')' && stck.top()=='(') || (c=='}' && stck.top()=='{') || (c==']' && stck.top()=='[')){ 
                stck.pop();
            }
            else{
                cout<<"Not Balanced";
                return 0;
            }
        }
    }
    if(stck.empty()){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
    return 0;   
}