5. Given a full m-ary tree with i internal vertices, Write a Program to find the number of leaf nodes.

#include <iostream>
using namespace std;
 
// Function to calculate
// leaf nodes in m-ary tree
int calcNodes(int N, int I)
{
    int result = 0;
 
    result = I * (N - 1) + 1;
 
    return result;
}
 
int main()
{
    int N = 5, I = 2;
 
    cout << "Leaf nodes = " << calcNodes(N, I);
 
    return 0;
}

Output: 

Leaf nodes = 9
