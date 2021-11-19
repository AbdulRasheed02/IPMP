#include<iostream>
#include <iomanip> 
#include <cmath>
#include<vector>
#include<utility>
#include<set>
#include<tuple>
using namespace std;
 
void func(vector<int> v){
    v.pop_back();
    v.pop_back();
    for(auto i=v.begin();i!=v.end();i++)
         cout<<*i<<"";
    cout<<endl;
}
void func1(vector<int> &v){
    v.pop_back();
    v.pop_back();
}
int main(){
    int number;
    cout<<"Hello World\n";
    cin>>number;
    cout<<"Input Number:"<<number;
   

    //setPrecision,floor,ceil,trunc,round

    float x=1.2;
    cout<<floor(x)<<endl;
    cout<<ceil(x)<<endl;
    cout<<trunc(3.653)<<endl;
    cout<<round(1.3)<<endl;
    cout<<round(1.6)<<endl;
    cout<<fixed<<setprecision(2)<<1.345<<endl;
    cout<<fixed<<setprecision(7)<<1.345<<endl;

    vector<int> a={4,1,6,8};
    vector<int>::iterator iter;
    for(auto i=a.begin();i!=a.end();i++)
        cout<<*i<<"";
        cout<<endl;
    for(auto i=a.cbegin();i!=a.cend();i++)
        cout<<*i<<"";
        cout<<endl;
    for(auto i=a.rbegin();i!=a.rend();i++)
        cout<<*i<<"";
        cout<<endl;
    for(auto i=a.crbegin();i!=a.crend();i++)
        cout<<*i<<"";
        cout<<endl;

    iter=a.begin()+3;
    a.erase(iter);
    for(auto i=a.begin();i!=a.end();i++)
         cout<<*i<<"";
    cout<<endl;

    cout<<a.size()<<endl;
    a.clear();
    cout<<a.size();

    a={3,6,7};
    a.push_back(5);
    for(auto i=a.begin();i!=a.end();i++)
         cout<<*i<<"";
    cout<<endl;
    a.pop_back();
    for(auto i=a.begin();i!=a.end();i++)
         cout<<*i<<"";
    cout<<endl;
    func(a);
     for(auto i=a.begin();i!=a.end();i++)
         cout<<*i<<"";
    cout<<endl;
    func1(a);
     for(auto i=a.begin();i!=a.end();i++)
         cout<<*i<<"";
    cout<<endl;

    vector<int> v;
    v.push_back(5);
    for(auto i=v.begin();i!=v.end();i++)
          cout<<*i<<"";
     cout<<endl;
    int n=5;
    vector<int> v1(5,0);
    for(auto i=v1.begin();i!=v1.end();i++)
          cout<<*i<<"";
     cout<<endl;
    vector<int> v2{1,2,3};
    for(auto i=v2.begin();i!=v2.end();i++)
          cout<<*i<<"";
     cout<<endl;

    int arr[] = { 15, 20, 8 };
    n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr,arr+n);
 
    for (int x : vect)
        cout << x << " ";
     pair<int,char> p;
     p.first=3;
     p.second='A';

    pair<int,char> p3 (2,'A');
    pair p2 (2,'A');
    p2=make_pair(2,'a');
    p3=make_pair(3,'b');
    p2.swap(p3);
    cout << p2.first<< p2.second ;

    int a2;
    char b2;
    tie(a2,b2)=p;
    cout << a2 << b2;
    

    set<int> s;
    s.insert(50);
    s.insert(20);
    s.insert(80);
    s.insert(25);
    s.insert(50);

    set<int>:: iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl<<s.size()<<endl;

    set<int> s2;
    s2.insert(s.find(50),s.end());
    s2.insert(s2.find(50),70);
     for (it = s2.begin(); it != s2.end(); it++)
    {
        cout<<*it<<" ";
    }

    set<int> s3={1,2,3,4,5,6,7,8,9,10};
    set<int>:: iterator it1,it2,it3;
    it1=s3.begin();
    s3.erase(it1);
    it1=s3.begin();
    it2=s3.end();
    it1++;
    it2--;
    for (it = it1; it != it2; it++)
    {
        cout<<*it<<" ";
    }
    set<int> s4={1,7,8,9,10};
    it3=s4.begin();
    for(int i=s4.size();i>0;i--){
        if((*it3)%2==0){
            it3=s4.erase(it3);
        }
        it3++;
    }
    for (it = s4.begin(); it != s4.end(); it++)
    {
        cout<<*it<<" ";
    }

    auto fin=s4.find(10);
    cout<<*fin;

    s4.clear();
    for (it = s4.begin(); it != s4.end(); it++)
     {
        cout<<*it<<" ";
    }

    it1=s4.lower_bound(2);
    it2=s4.upper_bound(9);
    cout<<*it1<<" "<<*it2;



    return 0;
}
