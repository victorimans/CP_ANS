#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

double distanceSquared(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool isRightTriangle(const Point& p1, const Point& p2, const Point& p3) {
    double d1 = distanceSquared(p1, p2);
    double d2 = distanceSquared(p2, p3);
    double d3 = distanceSquared(p1, p3);
    
    // Check if any combination satisfies the Pythagorean theorem
    return (d1 + d2 == d3) || (d1 + d3 == d2) || (d2 + d3 == d1);
}

int main() {
    Point p1, p2, p3;
    std::cin >> p1.x >> p1.y;
    std::cin >> p2.x >> p2.y;
    std::cin >> p3.x >> p3.y;
    
    if (isRightTriangle(p1, p2, p3)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
