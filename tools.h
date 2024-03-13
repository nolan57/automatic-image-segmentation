#ifndef TOOLS_H
#define TOOLS_H
#include <pieceofimage.h>

class SizeOfPartition{
public:
    SizeOfPartition();
    int col;
    int row;
    int width;
    int height;
    int lta;
};

class Tools
{
public:
    Tools();
    int randCode();
    std::vector<PieceOfImage> toSideCode(std::vector<PieceOfImage> images,const int cols);
    void toTestSideCode(const int rows,const int cols);
    std::vector<PieceOfImage> toPartition(const cv::Mat &image,int rows,int cols);
    std::string setType(Location loc,int rows,int cols);
    SizeOfPartition setSizeOfPartition(const std::string type,
                                       const std::map<std::string,int> sidesCode,
                                       const int col,const int row,
                                       const int samllWidth,const int smallHeight,
                                       const int cols,int rows);
    bool inScope(cv::Point point,RectangleScope scope);
    bool inScope(cv::Point point,CircleScope scope);
    int inScopes(cv::Point point,std::vector<CircleScope> circleScopes);
    void toShapeImage(PieceOfImage &image);
    cv::Mat toAlphaImage(const cv::Mat &inputImage);
};

#endif // TOOLS_H
