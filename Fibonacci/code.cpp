#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        unsigned int n;
        cin>>n;
        unsigned long long fib[n];
        fib[0] = 1;
        fib[1] = 1;
        for(int i=2;i<n;i++){
            fib[i] = fib[i - 1] + fib[i - 2] > 1000000007 ? 
				(fib[i - 1] + fib[i - 2]) % 1000000007
						: fib[i - 1] + fib[i - 2];
        }
        cout<< (fib[n-1])<<endl;
    }
	return 0;
}