
#include <iostream>
using namespace std;

void ananas(int n, int A, int C, int B) // przenies n elementow z A na C przy pomocy B
{
    //bazowy
    if(n==1)
    {
        cout<<A<<' '<<C<<'\n'; // przenoes jeden element z A na C
        return;
    }
    ananas(n-1, A, B, C);// przenies n-1 elementow z A na B przy pomocy C
    cout<<A<<' '<<C<<'\n'; 
    ananas(n-1, B, C, A);// przenies n elementow z B na C przy pomocy A
}

int main(){
    
    int n;
    cin>>n;
    
    int A=1, B=2, C=3;
    ananas(n, A, C, B);
    return 0;
}