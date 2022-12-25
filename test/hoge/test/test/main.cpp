//
//  main.cpp
//  test
//
//  Created by Hisaki Kobayashi on 2022/09/25.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> A;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> V;
    V.assign(10,5);
    cout << V[5] << endl;
    
    A.resize(10000,1000);
    cout << A[5555] << endl;
    
    return 0;
}
