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
            line.b = point1.y - a * point1.x;
            lines.push_back(line);
        }
    }

    return lines;
}

size_t CountNumberPointsOnSameLine(const std::vector<Line>& lines) { return 0; }

int main() {
    std::vector<Point> points = {{-1, 1}, {0, 0}, {1, 1},
                                 {2, 2},  {3, 3}, {3, 4}};

    auto lines = ComputeLines(points);
    size_t num_points = CountNumberPointsOnSameLine(lines);

    return 0;
}
