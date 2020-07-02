#include <iostream>
using namespace std;
int min(int a,int b,int c){
    if(a<b){
        if(a<c){
            return a;
        }
        else{
            return c;
        }
    }
    return b;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    unsigned int n;
	    cin>>n;
	    unsigned long ugly[n]; // To store ugly numbers 
        unsigned long i2 = 0, i3 = 0, i5 = 0; 
        unsigned long next_multiple_of_2 = 2; 
        unsigned long next_multiple_of_3 = 3; 
        unsigned long next_multiple_of_5 = 5; 
        unsigned long next_ugly_no = 1; 
      
        ugly[0] = 1; 
        for (int i=1; i<n; i++) 
        { 
           next_ugly_no = min(next_multiple_of_2, 
                               min(next_multiple_of_3, 
                                   next_multiple_of_5)); 
           ugly[i] = next_ugly_no; 
           if (next_ugly_no == next_multiple_of_2) 
           { 
               i2 = i2+1; 
               next_multiple_of_2 = ugly[i2]*2; 
           } 
           if (next_ugly_no == next_multiple_of_3) 
           { 
               i3 = i3+1; 
               next_multiple_of_3 = ugly[i3]*3; 
           } 
           if (next_ugly_no == next_multiple_of_5) 
           { 
               i5 = i5+1; 
               next_multiple_of_5 = ugly[i5]*5; 
           } 
        } /*End of for loop (i=1; i<n; i++) */
       cout<<next_ugly_no<<endl; 
	}
	return 0;
}