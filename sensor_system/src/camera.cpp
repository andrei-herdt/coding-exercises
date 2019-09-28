#include "../include/camera.h"

bool Camera::Start()
{
    return true;
}

void Camera::Register(const CallBackType& call_back)
{
    consumer_call_back_ = call_back;
}

void Camera::Send(Image data) const
{
    consumer_call_back_(data);
}
