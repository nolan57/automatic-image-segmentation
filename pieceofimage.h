#ifndef PIECEOFIMAGE_H
#define PIECEOFIMAGE_H
#include <map>
#include <opencv2/opencv.hpp>

class RectangleScope{
public:
    RectangleScope(){}
    cv::Point ltp;
    cv::Point rtp;
    cv::Point rbp;
    cv::Point lbp;
    int getWidth(){return rtp.x-ltp.x;}
    int getHeight(){return rbp.y-ltp.y;}
};

class CircleScope{
public:
    CircleScope(){}
    cv::Point center;
    int r;
    int code;
};

struct KeyPoints{
    RectangleScope externalScope;
    RectangleScope internalScope;
    std::vector<CircleScope> circleScopes;
};

class Location
{
public:
    Location(){};
    int row;
    int col;

    Location(long irow,long icol):row(irow),col(icol){}
};
class SizeOfImage
{
public:
    SizeOfImage(){};
    int width;
    int height;
    SizeOfImage(long iwidth,long iheight):width(iwidth),height(iheight){}
};

class PieceOfImage
{
public:
    PieceOfImage(){};
    Location location={0,0};
    std::map<std::string,int> sidesCode={{"左边",0},{"上边",0},{"右边",0},{"下边",0}};
    SizeOfImage size;
    std::string type;
    cv::Mat image;
    int r;
    cv::Mat shapedImage;
    KeyPoints getKeyPoints();
    void setKeyPoints();
private:
    KeyPoints keyPoints;
};

class ImageToTest{
public:
    ImageToTest(){};
    Location location={0,0};
    std::map<std::string,int> sidesCode={{"左边",0},{"上边",0},{"右边",0},{"下边",0}};
    std::string type;
};

#endif // PIECEOFIMAGE_H
