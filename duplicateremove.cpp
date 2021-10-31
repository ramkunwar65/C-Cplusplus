#include<iostream>
using namespace std;

string duprem(string s)
{
	if(s.length()==0)
	{
		return "";
	}
	char ch=s[0];
	string ans=duprem(s.substr(1));
	if(ch==ans[0])
	{return ans;
	}
	return ch+ans;
}

int main()
{
	string s= duprem("aaaabbbbccccdededd");
	cout<<s;
	return 0;
}
