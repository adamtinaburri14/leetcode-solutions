#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 3, 6, 2, 9};

    // Search an element 6
    auto it = find(v.begin(), v.end(), 9);
    // cout << &v[2] << endl;
    // cout << *v.begin() << endl;
    cout << &*(v.end()) << endl;

	// Print index
    cout << &v[distance(v.begin(), it)];
  
    if (it == v.end()){
        cout << endl << "YES" << endl;
    }
    return 0;
}