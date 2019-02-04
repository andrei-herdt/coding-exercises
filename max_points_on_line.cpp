#include <array>
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

struct Line {
    double a, b;
};

std::vector<Line> ComputeLines(const std::vector<Point>& points) { return {}; }

size_t CountNumberPointsOnSameLine(const std::vector<Line>& lines) { return 0; }

int main() {
    std::vector<Point> points = {{-1, 1}, {0, 0}, {1, 1},
                                 {2, 2},  {3, 3}, {3, 4}};

    auto lines = ComputeLines(points);
    size_t num_points = CountNumberPointsOnSameLine(lines);

    return 0;
}
