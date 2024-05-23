#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    srand(std::time(nullptr));  // Seed for random number generation

    int N, Q;
    N = rand() % 100000;
    Q = rand() % N;
    cout << N << " " << Q << endl;
    // Generate N random numbers
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        numbers[i] = std::rand() % 100000;  // Generate a random number
    }

    // Print the N random numbers space-separated
    for (int i = 0; i < N; ++i) {
        cout << numbers[i];
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << std::endl;

    // Generate Q random queries
    for (int i = 0; i < Q; ++i) {
        int a = std::rand() % N;
        cout << a  << endl;
    }

    return 0;
}
