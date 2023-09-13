#include<iostream>

using namespace std;

int ucln(int m , int n) // ham tim uoc chung lon nhat bang de quy
{
    if(n == 0) return m;
    else return ucln(n, m % n);
}

int main()
{
    int m, n ;
    cin >> m >> n;
    cout << ucln(m,n);
    return 0;
}
