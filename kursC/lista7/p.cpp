
#include <iostream>
using namespace std;

void ananas(int n, int A, int C, int B)
{
    //bazowy
    if(n==1)
    {
        cout<<A<<' '<<C<<'\n';
        return;
    }
    ananas(n-1, A, B, C);
    cout<<A<<' '<<C<<'\n';
    ananas(n-1, B, C, A);
}

int main(){
    
    int n;
    cin>>n;
    
    int A=1, B=2, C=3;
    ananas(n, A, C, B);
    return 0;
}