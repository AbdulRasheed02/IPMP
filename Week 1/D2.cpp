#include<iostream>
#include<map>
#include<set>
#include<utility>
using namespace std;

int main(){
	int n;
	cout<<"No. of Elements"<<endl;
	cin>>n;
	int A[n];
	map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>A[i];
		m[A[i]]++;
	}
	cout<<"Enter x"<<endl;
	int x;
	cin>>x;
	for(int i=0;i<n;i++){
		int element2=x-A[i];
		if(m[element2]>0){
			if(element2==A[i] && m[element2]==1){
				
			}
			else{
			cout<<"Elements exist: "<<element2<<" and "<<A[i];
			return 0;
			}
			
		}
	}
	cout<<"Elements do not exist";
	return 0;
}