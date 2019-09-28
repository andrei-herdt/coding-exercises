#ifndef IMAGE_H_
#define IMAGE_H_

class Image
{
  public:
    Image(int jpeg) : jpeg_(jpeg){};
    int GetImage() const
    {
        return jpeg_;
    };

  private:
    int jpeg_;
};

inline bool operator==(const Image& a, const Image& b)
{
    return a.GetImage() == b.GetImage();
};

#endif  // IMAGE_H_
