#include <bits/stdc++.h>
using namespace std;

// Calculate distance
double calcDistance(int x1, int y1, int x2, int y2){
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    return distance;
}

int main() {
    // Initializing the points
    pair<int,int> A = {2,1};
    pair<int,int> B = {5,1};
    pair<int,int> C = {6,4};
    pair<int,int> D = {3,6};
    pair<int,int> E = {1,4};

    // Calculating perimeter
    double perimeter = 0;
    perimeter += calcDistance(A.first, A.second, B.first, B.second);
    perimeter += calcDistance(B.first, B.second, C.first, C.second);
    perimeter += calcDistance(C.first, C.second, D.first, D.second);
    perimeter += calcDistance(D.first, D.second, E.first, E.second);
    perimeter += calcDistance(E.first, E.second, A.first, A.second);

    // Output
    cout<<"Perimeter of polygon = "<<perimeter<<endl;

    return 0;
}

