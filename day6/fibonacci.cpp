// memoization :

#include <iostream>
#include <vector>
using namespace std;

int  fib( int n , vector<int> &x){
    

    if(x[n] != -1 ){
        return x[n];
    }
    else{
        if(n<=1){
            x[n]=n;
         
        }
        else{
            x[n] = fib(n-2,x) + fib(n-1,x);
        }
    }
    return x[n];

}


int main()
{

    int n;
    cout<<"the for which u want to generate the fibonacci "<<endl; 
    cin >>n;
    vector<int> x(n+1,-1);

   fib(n,x);

   cout<<"the fibonacci is :"<<endl;

for(int i=0;i<x.size();i++){
    cout<<x[i]<<" ";
}

    return 0;
}