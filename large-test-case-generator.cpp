#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    cerr<<"Time: "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<" ms\n";
    registerGen(argc, argv, 1);
    int t = rnd.next(1, 100);
    // Generate n such that 1 <= n <= 100000
    int n = rnd.next(1, 100000);

    // Generate q such that 1 <= q <= n
    int q = rnd.next(1, n);

    // Output n and q
    std::cout << n << " " << q << std::endl;

    // Generate array of n numbers such that 1 <= ai <= 1e9
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = rnd.next(0, 1000000000);
    }

    // Output the array
    for (int i = 0; i < n-1; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << array[n-1] << std::endl;

    // Generate q distinct integers such that 0 <= qi <= n-1
    std::set<int> indices;
    while (indices.size() < q) {
        indices.insert(rnd.next(0, n-1));
    }

    // Output the q distinct integers
    for (int index : indices) {
        std::cout << index << endl;
    }
    return 0;
}
