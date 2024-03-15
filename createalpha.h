#ifndef CREATEALPHA_H
#define CREATEALPHA_H
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

class CreateAlpha
{
public:
    CreateAlpha(){};
    cv::Mat createAlphaChannel(cv::Mat& src);
    int addAlpha(cv::Mat& src, cv::Mat& dst, cv::Mat& alpha);
};

#endif // CREATEALPHA_H
