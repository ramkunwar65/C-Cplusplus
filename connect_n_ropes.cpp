#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int> v){
    priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());

    int totalCost = 0;
    int n = v.size();
    while(n>1){
        int f = pq.top();
        pq.pop();

        int s = pq.top();
        pq.pop();

        int sum = f + s;
        totalCost += sum;
        pq.push(sum);
        n--;
    }

    return totalCost;

}
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v = {5,4,2,8};
    cout<<"Minimum cost : "<<connectNRopes(v);
    return 0;

}
