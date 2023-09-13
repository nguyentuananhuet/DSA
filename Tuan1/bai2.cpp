#include <iostream>
#include <cmath>

class Point {
public:
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

class Line {
public:
    Point start, end;
    Line(Point _start, Point _end) : start(_start), end(_end) {}
};

// Hàm kiểm tra xem hai đoạn thẳng có giao nhau không
bool doLinesIntersect(Line AB, Line CD, Point& intersection) {
    double x1 = AB.start.x, y1 = AB.start.y;
    double x2 = AB.end.x, y2 = AB.end.y;
    double x3 = CD.start.x, y3 = CD.start.y;
    double x4 = CD.end.x, y4 = CD.end.y;

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denominator == 0) {
        // Hai đoạn thẳng song song hoặc trùng nhau
        return false;
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        // Điểm giao nhau nằm trong hai đoạn thẳng
        intersection.x = x1 + t * (x2 - x1);
        intersection.y = y1 + t * (y2 - y1);
        return true;
    }

    return false; // Hai đoạn thẳng không giao nhau trong phạm vi đoạn
}

int main() {
    Point A, B, C, D;
    std::cout << "Nhập tọa độ điểm A (x y): ";
    std::cin >> A.x >> A.y;
    std::cout << "Nhập tọa độ điểm B (x y): ";
    std::cin >> B.x >> B.y;
    std::cout << "Nhập tọa độ điểm C (x y): ";
    std::cin >> C.x >> C.y;
    std::cout << "Nhập tọa độ điểm D (x y): ";
    std::cin >> D.x >> D.y;

    Line AB(A, B);
    Line CD(C, D);

    Point intersection;

    if (doLinesIntersect(AB, CD, intersection)) {
        std::cout << "Điểm giao nhau: " << intersection.x << " " << intersection.y << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

