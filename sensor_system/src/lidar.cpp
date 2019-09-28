#include "../include/lidar.h"

bool Lidar::Start()
{
    return true;
}

void Lidar::Register(const CallBackType& call_back)
{
    consumer_call_back_ = call_back;
}

void Lidar::Send(const PointCloud& data) const
{
    consumer_call_back_(data);
}
