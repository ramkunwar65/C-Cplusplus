#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout<<"Working\n";

	int n;
	int S;
	cin>>n;
	cin>>S;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int i;
	int j;
	i = j = 0;

	int prevSum = 0;
	while(j<n){
		if(arr[j] + prevSum == S)
			break;
		else if(arr[j] + prevSum < S){
			prevSum += arr[j];
			j++;
		}
		else{
			if(i==j){
				i++;
				j++;
			}
			else{
				prevSum -= arr[i];
				i++;
			}
		}
	}

	if(j<n)
		cout<<"Indices : "<<i<<" : "<<j<<endl;
	else
		cout<<"No such subarray exists"<<endl;
	return 0;
}