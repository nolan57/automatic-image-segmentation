#include "pieceofimage.h"

void PieceOfImage::setKeyPoints(){

    if(image.empty()){
        return;
    }

    //keyPoints = KeyPoints();
    //keyPoints.circleScopes = std::vector<CircleScope>();
    keyPoints.externalScope.ltp = cv::Point(0,0);
    keyPoints.externalScope.rtp = cv::Point(size.width,0);
    keyPoints.externalScope.rbp = cv::Point(size.width,size.height);
    keyPoints.externalScope.lbp = cv::Point(0,size.height);

    keyPoints.internalScope.ltp = cv::Point(0,0);
    keyPoints.internalScope.rtp = cv::Point(size.width,0);
    keyPoints.internalScope.rbp = cv::Point(size.width,size.height);
    keyPoints.internalScope.lbp = cv::Point(0,size.height);

    CircleScope circleScope = CircleScope();
    // circleScope.center = cv::Point(0,0);
    // circleScope.r = 0;
    // circleScope.code = 0;
    //keyPoints.circleScopes = std::vector<CircleScope>();
    keyPoints.circleScopes.push_back(circleScope);
    keyPoints.circleScopes.push_back(circleScope);
    keyPoints.circleScopes.push_back(circleScope);
    keyPoints.circleScopes.push_back(circleScope);

    if(sidesCode.at("上边") == 1){
        keyPoints.internalScope.ltp =
            cv::Point(0,size.height/4)+keyPoints.internalScope.ltp;
        keyPoints.internalScope.rtp =
            cv::Point(0,size.height/4)+keyPoints.internalScope.rtp;
    }
    if(sidesCode.at("左边")==1){
        keyPoints.internalScope.ltp =
            cv::Point(size.width/4,0)+keyPoints.internalScope.ltp;
        keyPoints.internalScope.lbp =
            cv::Point(size.width/4,0)+keyPoints.internalScope.lbp;
    }
    if(sidesCode.at("右边")==1){
        keyPoints.internalScope.rtp =
            cv::Point(-size.width/4,0)+keyPoints.internalScope.rtp;
        keyPoints.internalScope.rbp =
            cv::Point(-size.width/4,0)+keyPoints.internalScope.rbp;
    }
    if(sidesCode.at("下边")==1){
        keyPoints.internalScope.lbp =
            cv::Point(0,-size.height/4)+keyPoints.internalScope.lbp;
        keyPoints.internalScope.rbp =
            cv::Point(0,-size.height/4)+keyPoints.internalScope.rbp;
    }
    keyPoints.circleScopes[0].code = sidesCode.at("上边");
    keyPoints.circleScopes[0].center = (keyPoints.internalScope.ltp+keyPoints.internalScope.rtp)/2;
    //keyPoints.circleScopes[0].r = keyPoints.internalScope.getHeight()/4;
    keyPoints.circleScopes[0].r = r;
    std::cout << "圆半径:" << keyPoints.circleScopes[0].r<<"\n";

    keyPoints.circleScopes[1].code = sidesCode.at("右边");
    keyPoints.circleScopes[1].center = (keyPoints.internalScope.rtp+keyPoints.internalScope.rbp)/2;
    //keyPoints.circleScopes[1].r = keyPoints.internalScope.getWidth()/4;
    keyPoints.circleScopes[1].r = r;
    std::cout << "圆半径:" << keyPoints.circleScopes[1].r<<"\n";

    keyPoints.circleScopes[2].code = sidesCode.at("下边");
    keyPoints.circleScopes[2].center = (keyPoints.internalScope.lbp+keyPoints.internalScope.rbp)/2;
    //keyPoints.circleScopes[2].r = keyPoints.internalScope.getHeight()/4;
    keyPoints.circleScopes[2].r = r;
    std::cout << "圆半径:" << keyPoints.circleScopes[2].r<<"\n";

    keyPoints.circleScopes[3].code = sidesCode.at("左边");
    keyPoints.circleScopes[3].center = (keyPoints.internalScope.ltp+keyPoints.internalScope.lbp)/2;
    //keyPoints.circleScopes[3].r = keyPoints.internalScope.getWidth()/4;
    keyPoints.circleScopes[3].r = r;
    std::cout << "圆半径:" << keyPoints.circleScopes[3].r<<"\n";

    std::cout << "图片大小:" << size.width <<"," <<size.height<<"\n";
    std::cout << "外矩形:" << keyPoints.externalScope.ltp<<","<<keyPoints.externalScope.rbp<<"\n";
    std::cout << "内矩形:" << keyPoints.internalScope.ltp<<","<<keyPoints.internalScope.rbp<<"\n";
    std::cout << "内矩形宽高:" << keyPoints.internalScope.getWidth()<<","<<keyPoints.internalScope.getHeight()<<"\n";
}

KeyPoints PieceOfImage::getKeyPoints(){
    return keyPoints;
}
