#include<iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int a,int b)  :
        x(a),y(b)
    {

    };
};


//Given 4 points 2 of each rectangle (upperleft and lowerright)
bool isOverlap(Point& p1,Point& p2,Point& p3,Point& p4) {

    //  p1       p3         
    //      p2      p4 
    //  p3
    //      p4
    //Think negative what if 2 rectangles are not overlap with each other

    //~(p2.x < p3.x || p4.x < p1.x || p2.y > p3.y || p4.y > p1.y) 
    if (p2.x >= p3.x && p4.x >= p1.x && p2.y <= p3.y && p4.y >= p1.y) {
        return true;
    }
    return false;
}


int main () {

}
