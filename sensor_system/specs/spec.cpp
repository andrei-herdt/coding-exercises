#include "../include/image.h"
#include "../include/point_cloud.h"
#include "../include/robot.h"
#include "../include/sensor.h"

#include <gtest/gtest.h>

using Lidar = Sensor<PointCloud>;
using Camera = Sensor<Image>;

TEST(Creation, CreateRobotWhenAlone)
{
    Robot robot;
    EXPECT_TRUE(robot.Start());
}

TEST(Creation, CreateRobotAndOneLidar)
{
    Robot robot;
    EXPECT_TRUE(robot.Start());
    Lidar lidar;
    EXPECT_TRUE(lidar.Start());
}

TEST(DataFlow, ReceiveDataWhenOneLidar)
{
    Robot robot;
    Lidar lidar;
    lidar.Register([&](const PointCloud& point_cloud) { robot.Update(point_cloud); });

    PointCloud expected_point_cloud{1};
    lidar.Send(expected_point_cloud);
    EXPECT_EQ(robot.GetLatestPointCloud(), expected_point_cloud);
}

TEST(DataFlow, ReceiveDataWhenSeveralLidars)
{
    Robot robot;
    Lidar lidar_front;
    lidar_front.Register([&](const PointCloud& point_cloud) { robot.Update(point_cloud); });
    Lidar lidar_back;
    lidar_back.Register([&](const PointCloud& point_cloud) { robot.Update(point_cloud); });

    lidar_front.Send(1);
    PointCloud expected_point_cloud{2};
    lidar_back.Send(expected_point_cloud);
    EXPECT_EQ(robot.GetLatestPointCloud(), expected_point_cloud);
}

TEST(DataFlow, ReceiveDataWhenLidarsAndCamera)
{
    Robot robot;
    Lidar lidar_front;
    lidar_front.Register([&](const PointCloud& point_cloud) { robot.Update(point_cloud); });
    PointCloud expected_point_cloud{1};
    lidar_front.Send(expected_point_cloud);
    EXPECT_EQ(robot.GetLatestPointCloud(), expected_point_cloud);

    Lidar lidar_back;
    lidar_back.Register([&](const PointCloud& point_cloud) { robot.Update(point_cloud); });
    lidar_front.Send(1);
    PointCloud expected_point_cloud2{2};
    lidar_back.Send(expected_point_cloud2);
    EXPECT_EQ(robot.GetLatestPointCloud(), expected_point_cloud2);

    Camera camera;
    camera.Register([&](const Image& image) { robot.Update(image); });
    Image expected_image{2};
    camera.Send(expected_image);
    EXPECT_EQ(robot.GetLatestImage(), expected_image);
}
