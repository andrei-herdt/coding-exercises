#include <array>
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

struct Line {
    double a, b;
};

std::vector<Line> ComputeLines(const std::vector<Point>& points) {
    std::vector<Line> lines;
    for (auto point1 : points) {
        for (auto point2 : points) {
            Line line;
            line.a = (point2.y - point1.y) / (point2.x - point1.x);
            line.b = point1.y - line.a * point1.x;
            lines.push_back(line);
        }
    }

    return lines;
}

int main() {
    std::vector<Point> points = {{-1, 1}, {0, 0}, {1, 1},
                                 {2, 2},  {3, 3}, {3, 4}};

    auto lines = ComputeLines(points);

    auto IsSame = [](const Line& line1, const Line& line2) {
        return line1.a == line2.a && line1.b == line2.b;
    };

    size_t num_same_line{2};
    for (auto line1 : lines) {
        for (auto line2 : lines) {
            if (IsSame(line1, line2)) {
                num_same_line += 2;
            }
        }
    }

    return 0;
}
