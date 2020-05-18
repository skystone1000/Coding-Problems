#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    int count=0;
    // game loop
    while (1) {
        int myScore;
        cin >> myScore; cin.ignore();
        int enemyScore1;
        cin >> enemyScore1; cin.ignore();
        int enemyScore2;
        cin >> enemyScore2; cin.ignore();
        int myRage;
        cin >> myRage; cin.ignore();
        int enemyRage1;
        cin >> enemyRage1; cin.ignore();
        int enemyRage2;
        cin >> enemyRage2; cin.ignore();
        int unitCount;
        cin >> unitCount; cin.ignore();

        int reachX,reachY;
        int currX,currY;
        for (int i = 0; i < unitCount; i++) {
            int unitId;
            int unitType;
            int player;
            float mass;
            int radius;
            int x;
            int y;
            int vx;
            int vy;
            int extra;
            int extra2;
            cin >> unitId >> unitType >> player >> mass >> radius >> x >> y >> vx >> vy >> extra >> extra2; cin.ignore();
            currX = x;
            currY = y;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // cout << x << y << " THROTTLE"<< endl;
        // cout << "WAIT" << endl;
        // cout << "WAIT" << endl;

        if(count % 3 == 0){
            cout << currX <<" "<< currY << " 300"<< endl;
            cout << "WAIT" << endl;
            cout << "WAIT" << endl;

            reachX = currX;
            reachY = currY;
            // cout<<endl;
            count++;
        }else{
            cout << reachX <<" "<< reachY << " 200"<< endl;
            cout << "WAIT" << endl;
            cout << "WAIT" << endl;
            // cout<<endl;
            count++;            
        }

    }
}