#include "../include/robot.h"

bool Robot::Start()
{
    return true;
}

void Robot::Update(const PointCloud& point_cloud)
{
    point_clouds_.push_back(point_cloud);
}

void Robot::Update(const Image& image)
{
    images_.push_back(image);
}

const PointCloud& Robot::GetLatestPointCloud() const
{
    return point_clouds_.back();
}

const Image& Robot::GetLatestImage() const
{
    return images_.back();
}
