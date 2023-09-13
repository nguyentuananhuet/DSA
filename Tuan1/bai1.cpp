#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int l = s.length();
	for(int i = l - 1; i >=0; i--)
	{
		cout<<s[i];
	}
}
