#ifndef PIECEOFIMAGE_H
#define PIECEOFIMAGE_H
#include <map>
#include <opencv2/opencv.hpp>

class Location
{
public:
    Location();
    unsigned long row;
    unsigned long col;

    Location(long irow,long icol):row(irow),col(icol){}
};
class SizeOfImage
{
public:
    SizeOfImage();
    unsigned long wide;
    unsigned long height;
    SizeOfImage(long iwide,long iheight):wide(iwide),height(iheight){}
};

class PieceOfImage
{
public:
    PieceOfImage();
    Location location={0,0};
    std::map<std::string,int> sidesCode={{"左边",0},{"上边",0},{"右边",0},{"下边",0}};
    SizeOfImage size;
    std::string type;
    cv::Mat image;
};

class ImageToTest{
public:
    ImageToTest();
    Location location={0,0};
    std::map<std::string,int> sidesCode={{"左边",0},{"上边",0},{"右边",0},{"下边",0}};
    std::string type;
};

#endif // PIECEOFIMAGE_H
