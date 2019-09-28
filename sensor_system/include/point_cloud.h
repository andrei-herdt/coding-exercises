#ifndef POINT_CLOUD_H_
#define POINT_CLOUD_H_

class PointCloud
{
  public:
    PointCloud(int position) : position_(position){};
    int GetPosition() const
    {
        return position_;
    };

  private:
    int position_;
};

inline bool operator==(const PointCloud& a, const PointCloud& b)
{
    return a.GetPosition() == b.GetPosition();
};

#endif  // POINT_CLOUD_H_
