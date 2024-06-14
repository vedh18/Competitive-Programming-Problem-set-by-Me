#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    cerr<<"Time: "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<" ms\n";
    registerGen(argc, argv, 1);
    int t = rnd.next(1, 100);
    // Generate n such that 1 <= n <= 100000
    int n = 100000;
 
    // Generate q such that 1 <= q <= n
 
    // Output n and q
    std::cout << n << " " << 100000<< std::endl;
 
    // Generate array of n numbers such that 1 <= ai <= 1e9
    std::vector<int> array(n);
    array[0] = 536870912;
    for (int i =1; i < n-2; i++) {
        array[i] = rnd.next(0, 33554432);
    }
    array[n-1] = 536870912;
 
    // Output the array
    for (int i = 0; i < n-1; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << array[n-1] << std::endl;
 
    // Generate q distinct integers such that 0 <= qi <= n-1
    for (int i = 0; i<100000; i++){
        cout << i << endl;
    }
    return 0;
}
