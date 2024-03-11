#ifndef TOOLS_H
#define TOOLS_H
#include <pieceofimage.h>

class SizeOfPartition{
public:
    SizeOfPartition();
    int ltx;
    int lty;
    int wide;
    int height;
};

class Tools
{
public:
    Tools();
    int randCode();
    std::vector<PieceOfImage> toSideCode(std::vector<PieceOfImage> images,unsigned long cols);
    void toTestSideCode(unsigned long rows,unsigned long cols);
    std::vector<PieceOfImage> toPartition(const cv::Mat &image,unsigned long rows,unsigned long cols);
    std::string setType(Location loc,unsigned long rows,unsigned long cols);
    SizeOfPartition setSizeOfPartition(const std::string type,
                                       const std::map<std::string,int> sidesCode,
                                       const unsigned long col,unsigned long row,
                                       const unsigned long samllWidth,unsigned long smallHeight,
                                       const unsigned long cols,unsigned long rows);
};

#endif // TOOLS_H
