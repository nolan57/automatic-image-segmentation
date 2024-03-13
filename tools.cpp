#include "tools.h"
#include <cstdlib>

SizeOfPartition::SizeOfPartition(){}

Tools::Tools() {}
int Tools::randCode(){
    srand(time(0));
    // 生成一个在-1到1之间的随机数并输出
    int randomNumber;
    do{
        //randomNumber = arc4random() % 3 - 1;
        randomNumber = rand() % 3 - 1;
    }while(randomNumber == 0);
    return randomNumber;
}
std::vector<PieceOfImage> Tools::toSideCode(std::vector<PieceOfImage> images,const int cols)
{
    //std::cout<<"size of images"<<images.size()<<"\n";
    for(int i=0;i<images.size();i++){
        std::string type = images[i].type;
        if(type == "左上角"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右上角"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右下角"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = 0;
            continue;
        }
        if(type == "左下角"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = 0;
            continue;
        }

        if(type == "左边"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "上边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "下边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = 0;
            continue;
        }
        images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
        images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
        images[i].sidesCode.at("右边") = randCode();
        images[i].sidesCode.at("下边") = randCode();
    }
    return images;
}

std::string Tools::setType(const Location loc,const int rows,const int cols){

    if(loc.row == 0 && loc.col == 0){
        return "左上角";
    }
    if(loc.row == 0 && loc.col == cols-1){
        return "右上角";
    }
    if(loc.row == rows-1 && loc.col == cols-1){
        return "右下角";
    }
    if(loc.row == rows-1 && loc.col == 0){
        return "左下角";
    }
    if(loc.col == 0){
        return "左边";
    }
    if(loc.col == cols-1){
        return "右边";
    }
    if(loc.row == 0){
        return "上边";
    }
    if(loc.col == cols-1){
        return "下边";
    }
    return "其他";
}

SizeOfPartition Tools::setSizeOfPartition(const std::string type,
                                          const std::map<std::string,int> sidesCode,
                                          const int col,const int row,
                                          const int smallWidth,const int smallHeight,
                                          const int cols,const int rows){
    SizeOfPartition sizeOfpartition=SizeOfPartition();
    sizeOfpartition.col = col;
    sizeOfpartition.row = row;
    sizeOfpartition.width = smallWidth;
    sizeOfpartition.height = smallHeight;
    int lta = std::min(smallWidth,smallHeight) /4;
    sizeOfpartition.lta = lta;


    std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
    std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
    std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")->";
    //std::cin.get();


    if(type == "左上角"){
        if(sidesCode.at("右边")==1){
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<1;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右上角"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.col = col-lta;//smallWidth/4;
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<3;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右下角"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.col = col-lta;//smallWidth/4;
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("上边")==1){
            sizeOfpartition.row = row-lta;//smallHeight/4;
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<5;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }

    if(type == "左下角"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.row = row-lta;//smallHeight/4;
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<7;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }

    if(type == "左边"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.row = row-lta;//smallHeight/4;
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = sizeOfpartition.height+lta;//smallHeight/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.width = smallWidth+lta;//smallWidth / 4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<8;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }
    if(type == "上边"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.col = col-lta;//smallWidth/4;
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.width = sizeOfpartition.width+lta;//smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<2;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右边"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.row = row-lta;//smallHeight/4;
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sidesCode.at("左边")==1){
            sizeOfpartition.col = col-lta;//smallWidth/4;
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = sizeOfpartition.height+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<3;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }
    if(type == "下边"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.col = col-lta;//smallWidth/4;
            sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.width = sizeOfpartition.width + lta;//smallWidth/4;
        }
        if(sidesCode.at("上边")==1){
            sizeOfpartition.row = row-lta;//smallHeight/4;
            sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
        }
        if(sizeOfpartition.col+sizeOfpartition.width>cols){
            sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
        }
        if(sizeOfpartition.row+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
        }
        std::cout<<6;
        std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
        //std::cin.get();
        return sizeOfpartition;
    }
    if(sidesCode.at("左边")==1){
        sizeOfpartition.col = col-lta;//smallWidth/4;
        sizeOfpartition.width = smallWidth+lta;//smallWidth/4;
    }
    if(sidesCode.at("上边")==1){
        sizeOfpartition.row = row-lta;//smallHeight/4;
        sizeOfpartition.height = smallHeight+lta;//smallHeight/4;
    }
    if(sidesCode.at("右边")==1){
        sizeOfpartition.width = sizeOfpartition.width+lta;//smallWidth/4;
    }
    if(sidesCode.at("下边")==1){
        sizeOfpartition.height = sizeOfpartition.height+lta;//smallHeight/4;
    }
    if(sizeOfpartition.col+sizeOfpartition.width>cols){
        sizeOfpartition.width = sizeOfpartition.width-(sizeOfpartition.col+sizeOfpartition.width-cols);
    }
    if(sizeOfpartition.row+sizeOfpartition.height>rows){
        sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.row+sizeOfpartition.height-rows);
    }
    std::cout<<9;
    std::cout<<"("<<sizeOfpartition.col<<","<<sizeOfpartition.row<<")";
    std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
    std::cout<<"("<<sizeOfpartition.width<<","<<sizeOfpartition.height<<")\n";
    //std::cin.get();
    return sizeOfpartition;
}


std::vector<PieceOfImage> Tools::toPartition(const cv::Mat &originalImage,const int rows,const int cols){

    std::vector<PieceOfImage> images=std::vector<PieceOfImage>();
    SizeOfPartition sizeOfPartition=SizeOfPartition();
    int smallWidth = originalImage.cols / cols;
    int smallHeight = originalImage.rows / rows;
    std::cout<<"original image's rows:"<<originalImage.rows<<";";
    std::cout<<"original image's cols:"<<originalImage.cols<<"\n";
    std::cout<<"small width:"<<smallWidth<<",";
    std::cout<<"small height:"<<smallHeight<<"\n";
    //std::cin.get();

    // 划分原始图片为N*M个小图片
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            PieceOfImage image=PieceOfImage();

            image.location.row = i;
            image.location.col = j;
            image.size.width = smallWidth;
            image.size.height = smallHeight;
            image.type = setType(image.location,rows,cols);
            images.push_back(image);
        }
    }
    images = toSideCode(images,cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            PieceOfImage image=images[i*cols+j];
            std::string type = image.type;
            std::map<std::string,int> sidesCode = image.sidesCode;
            sizeOfPartition = setSizeOfPartition(type,sidesCode, j * smallWidth,i * smallHeight, smallWidth, smallHeight,originalImage.cols,originalImage.rows);

            cv::Rect roi(sizeOfPartition.col, sizeOfPartition.row, sizeOfPartition.width, sizeOfPartition.height);
            cv::Mat smallImage = originalImage(roi).clone();
            images[i*cols+j].image = smallImage;
            images[i*cols+j].r = sizeOfPartition.lta;
            // 保存小图片
            std::string filename = "small_image_" + std::to_string(i) + "_" + std::to_string(j) + ".jpg";
            cv::imwrite(filename, smallImage);
        }
    }
    return images;
}

bool Tools::inScope(cv::Point point,RectangleScope scope){
    // 使用叉乘的方法判断点是否在四边形内部
    int cross1 = (scope.rtp.x - scope.ltp.x) * (point.y - scope.ltp.y) - (scope.rtp.y - scope.ltp.y) * (point.x - scope.ltp.x);
    int cross2 = (scope.rbp.x - scope.rtp.x) * (point.y - scope.rtp.y) - (scope.rbp.y - scope.rtp.y) * (point.x - scope.rtp.x);
    int cross3 = (scope.lbp.x - scope.rbp.x) * (point.y - scope.rbp.y) - (scope.lbp.y - scope.rbp.y) * (point.x - scope.rbp.x);
    int cross4 = (scope.ltp.x - scope.lbp.x) * (point.y - scope.lbp.y) - (scope.ltp.y - scope.lbp.y) * (point.x - scope.lbp.x);

    if ((cross1 >= 0 && cross2 >= 0 && cross3 >= 0 && cross4 >= 0) ||
        (cross1 <= 0 && cross2 <= 0 && cross3 <= 0 && cross4 <= 0)) {
        return true;
    } else {
        return false;
    }
}
bool Tools::inScope(cv::Point point,CircleScope scope){
    // 计算点 (x, y) 到圆心 (n, m) 的距离
    double distance = sqrt((point.x - scope.center.x) * (point.x - scope.center.x) + (point.y - scope.center.y) * (point.y - scope.center.y));

    // 如果距离小于等于半径 r，则点在圆内
    if (distance < scope.r) {
        return true;
    } else {
        return false;
    }
}

void Tools::toShapeImage(PieceOfImage &image){

    //cv::Mat inputImage = image.image.clone();
    cv::Mat ShapedImage = image.image.clone();
    KeyPoints keyPoints = image.getKeyPoints();

    //ßcv::cvtColor(inputImage,ShapedImage,cv::COLOR_BGR2BGRA);

    for(int col =0;col<image.image.cols;col++){
        for(int row = 0;row<image.image.rows;row++){
            cv::Point point=cv::Point(col,row);
            //bool seted = false;
            //判断点是不是在内矩形中
            if(inScope(point,keyPoints.internalScope)){
                //如果在内矩形中，则遍历所有圆
                for(CircleScope circleSope:keyPoints.circleScopes){
                    if(inScope(point,circleSope)){
                        //判断是不是在空圆内
                        if(circleSope.code==-1){
                            //若是在空圆中，则设为透明
                            //ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                            //cv::circle(ShapedImage, cv::Point(point.x, point.y), 2, cv::Scalar(0, 0, 0,0), 1);
                            ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                            //seted = true;
                            //退出遍历圆
                            break;
                        }
                    }
                }
            }else{
                //如果不在内矩形内
                bool seted = false;
                //则遍历所有圆
                for(CircleScope circleSope:keyPoints.circleScopes){
                    //判断是不是在某个圆内
                    if(inScope(point,circleSope)){
                        //判断是否不在实圆内
                        if(circleSope.code !=1){
                            //不在实圆内，就设为透明
                            //ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                            //cv::circle(ShapedImage, cv::Point(point.x, point.y), 2, cv::Scalar(0, 0, 0,0), 1);
                            ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                            seted = true;
                            break;
                        }
                    }
                }
                if(!seted){
                    //ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                    //cv::circle(ShapedImage, cv::Point(point.x, point.y), 2, cv::Scalar(0, 0, 0,0), 1);
                    ShapedImage.at<cv::Vec4b>(point.x,point.y)[3]=0;
                }
            }
        }
    }
    image.shapedImage = ShapedImage.clone();
    std::string filename = "shapedImage_[" +
                           std::to_string(image.location.col) + "," +
                           std::to_string(image.location.row) + "]" + "_" + ".jpg";
    cv::imwrite(filename, ShapedImage);

    // 显示绘制后的图片
    cv::imshow("Image with shapes", ShapedImage);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

cv::Mat Tools::toAlphaImage(const cv::Mat &inputImage){
    // 创建一个新的Mat对象，包含4个通道（3个颜色通道 + 1个alpha通道）
    cv::Mat image_with_alpha(inputImage.rows, inputImage.cols, CV_8UC4);

    // 将JPEG图像的颜色通道复制到新的Mat对象中
    cv::cvtColor(inputImage, image_with_alpha, cv::COLOR_BGR2BGRA);

    // 将alpha通道设置为255（不透明）
    for (int i = 0; i < image_with_alpha.rows; i++) {
        for (int j = 0; j < image_with_alpha.cols; j++) {
            image_with_alpha.at<cv::Vec4b>(i, j)[3] = 255;
        }
    }
    return image_with_alpha;
}

void Tools::toTestSideCode(const int rows,const int cols){

    //const int c = rows*cols;
    std::vector<ImageToTest> images = std::vector<ImageToTest>();

    //ImageToTest images[c];
    for(int i=0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            ImageToTest image=ImageToTest();
            image.location.row = i;
            image.location.col = j;
            image.type = setType(image.location,rows,cols);
            images.push_back(image);
            std::cout <<i<<":"<< i <<","<<j<<":"<<image.type << "\n";
            // images[i+j]=ImageToTest();
            // images[i+j].location.row=i;
            // images[i+j].location.col=j;
            // images[i+j].type = setType(images[i+j].location,rows,cols);
        }
    }

    //std::cout << "count of images:" <<sizeof(images)<<"\n";

    for(int i=0;i<images.size();i++){
        std::string type = images[i].type;
        if(type == "左上角"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右上角"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右下角"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = 0;
            continue;
        }
        if(type == "左下角"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = 0;
            continue;
        }

        if(type == "左边"){
            images[i].sidesCode.at("左边") = 0;
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "上边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = 0;
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "右边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = 0;
            images[i].sidesCode.at("下边") = randCode();
            continue;
        }
        if(type == "下边"){
            images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
            images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
            images[i].sidesCode.at("右边") = randCode();
            images[i].sidesCode.at("下边") = 0;
            continue;
        }
        images[i].sidesCode.at("左边") = -images[i-1].sidesCode.at("右边");
        images[i].sidesCode.at("上边") = -images[i-cols].sidesCode.at("下边");
        images[i].sidesCode.at("右边") = randCode();
        images[i].sidesCode.at("下边") = randCode();
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            std::cout << "("<<
                images[i*cols+j].sidesCode.at("左边")<<","<<
                images[i*cols+j].sidesCode.at("上边")<<","<<
                images[i*cols+j].sidesCode.at("右边")<<","<<
                images[i*cols+j].sidesCode.at("下边")<<","<<
                ")"<<",";
        }
        std::cout << "\n";
    }
}
