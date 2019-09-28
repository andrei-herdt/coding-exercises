#ifndef ROBOT_H
#define ROBOT_H

#include "image.h"
#include "point_cloud.h"

#include <vector>

class Robot
{
  public:
    bool Start();

    void Update(const PointCloud& point_cloud);
    void Update(const Image& image);

    const PointCloud& GetLatestPointCloud() const;
    const Image& GetLatestImage() const;

  private:
    std::vector<PointCloud> point_clouds_;
    std::vector<Image> images_;
};

#endif  // ROBOT_H
