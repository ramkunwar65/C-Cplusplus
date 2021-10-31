// Printing prime numbers in range
#include <iostream>
using namespace std;

void call(int n){
	int prime[100]={0};

	for(int i=2;i<=n;i++){
		if(prime[i]==0){// prime[i] has not been marked yet'
			for(int j = i*i;j<=n;j += i){
				prime[j]=1;
			}
		}
	}

	cout<<"Prime numbers are: "<<endl;
	for(int i=2;i<=n;i++){
		if(prime[i]==0){
			cout<<i<<" ";
		}
	}
}
int main(){
	int n;
	cin>>n;

	call(n);
	return 0;
}