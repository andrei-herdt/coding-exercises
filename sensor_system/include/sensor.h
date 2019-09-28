#ifndef SENSOR_H_
#define SENSOR_H_

#include <functional>

template <class DataT>
class Sensor
{
    using CallBackType = std::function<void(DataT)>;

  public:
    bool Start()
    {
        return true;
    }

    void Register(const CallBackType& call_back)
    {
        consumer_call_back_ = call_back;
    }

    void Send(const DataT& data) const
    {
        consumer_call_back_(data);
    }

  private:
    CallBackType consumer_call_back_;
};

#endif  // SENSOR_H_
