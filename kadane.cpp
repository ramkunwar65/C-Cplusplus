#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int kadane(vector<int> v);
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int ele;
	std::vector<int> v;

	for(int i=0;i<n;i++){
		cin>>ele;
		v.push_back(ele);
	}

	int maxi = kadane(v);

	cout<<"Max Sum= "<<maxi<<endl;
	return 0;
}

int kadane(std::vector<int> v){
	int maxi = INT_MIN;
	int cs = 0;
	for(auto ele:v){
		cs = max(cs + ele,ele);
		maxi = max(maxi,cs);
	}

	return maxi;
}