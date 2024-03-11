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
std::vector<PieceOfImage> Tools::toSideCode(std::vector<PieceOfImage> images,const unsigned long cols)
{
    //std::cout<<"size of images"<<images.size()<<"\n";
    for(unsigned long i=0;i<images.size();i++){
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

std::string Tools::setType(const Location loc,const unsigned long rows,const unsigned long cols){

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
                                          const unsigned long col,const unsigned long row,
                                          const unsigned long smallWidth,unsigned long smallHeight,
                                          const unsigned long cols,const unsigned long rows){
    SizeOfPartition sizeOfpartition=SizeOfPartition();
    sizeOfpartition.ltx = col;
    sizeOfpartition.lty = row;
    sizeOfpartition.wide = smallWidth;
    sizeOfpartition.height = smallHeight;

    std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
    std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
    std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")->";
    std::cin.get();


    if(type == "左上角"){
        if(sidesCode.at("右边")==1){
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<1;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右上角"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.ltx = col-smallWidth/4;
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<3;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";

        std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右下角"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.ltx = col-smallWidth/4;
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("上边")==1){
            sizeOfpartition.lty = row-smallHeight/4;
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<5;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }

    if(type == "左下角"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.lty = row-smallHeight/4;
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<7;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }

    if(type == "左边"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.lty = row-smallHeight/4;
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = sizeOfpartition.height+smallHeight/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.wide = smallWidth+smallWidth / 4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<8;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }
    if(type == "上边"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.ltx = col-smallWidth/4;
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.wide = sizeOfpartition.wide+smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<2;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }

    if(type == "右边"){
        if(sidesCode.at("上边")==1){
            sizeOfpartition.lty = row-smallHeight/4;
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sidesCode.at("左边")==1){
            sizeOfpartition.ltx = col-smallWidth/4;
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("下边")==1){
            sizeOfpartition.height = sizeOfpartition.height+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<3;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }
    if(type == "下边"){
        if(sidesCode.at("左边")==1){
            sizeOfpartition.ltx = col-smallWidth/4;
            sizeOfpartition.wide = smallWidth+smallWidth/4;
        }
        if(sidesCode.at("右边")==1){
            sizeOfpartition.wide = sizeOfpartition.wide + smallWidth/4;
        }
        if(sidesCode.at("上边")==1){
            sizeOfpartition.lty = row-smallHeight/4;
            sizeOfpartition.height = smallHeight+smallHeight/4;
        }
        if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
            sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
        }
        if(sizeOfpartition.lty+sizeOfpartition.height>rows){
            sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
        }
        std::cout<<6;
        std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
        std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
        std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
        std::cin.get();
        return sizeOfpartition;
    }
    if(sidesCode.at("左边")==1){
        sizeOfpartition.ltx = col-smallWidth/4;
        sizeOfpartition.wide = smallWidth+smallWidth/4;
    }
    if(sidesCode.at("上边")==1){
        sizeOfpartition.lty = row-smallHeight/4;
        sizeOfpartition.height = smallHeight+smallHeight/4;
    }
    if(sidesCode.at("右边")==1){
        sizeOfpartition.wide = sizeOfpartition.wide+smallWidth/4;
    }
    if(sidesCode.at("下边")==1){
        sizeOfpartition.height = sizeOfpartition.height+smallHeight/4;
    }
    if(sizeOfpartition.ltx+sizeOfpartition.wide>cols){
        sizeOfpartition.wide = sizeOfpartition.wide-(sizeOfpartition.ltx+sizeOfpartition.wide-cols);
    }
    if(sizeOfpartition.lty+sizeOfpartition.height>rows){
        sizeOfpartition.height = sizeOfpartition.height-(sizeOfpartition.lty+sizeOfpartition.height-rows);
    }
    std::cout<<9;
    std::cout<<"("<<sizeOfpartition.ltx<<","<<sizeOfpartition.lty<<")";
    std::cout<<"("<<sidesCode.at("左边")<<sidesCode.at("上边")<<sidesCode.at("右边")<<sidesCode.at("下边")<<")";
    std::cout<<"("<<sizeOfpartition.wide<<","<<sizeOfpartition.height<<")\n";
    std::cin.get();
    return sizeOfpartition;
}


std::vector<PieceOfImage> Tools::toPartition(const cv::Mat &originalImage,const unsigned long rows,const unsigned long cols){

    std::vector<PieceOfImage> images=std::vector<PieceOfImage>();
    SizeOfPartition sizeOfPartition=SizeOfPartition();
    int smallWidth = originalImage.cols / cols;
    int smallHeight = originalImage.rows / rows;
    std::cout<<"original image's rows:"<<originalImage.rows<<";";
    std::cout<<"original image's cols:"<<originalImage.cols<<"\n";
    std::cout<<"small width:"<<smallWidth<<",";
    std::cout<<"small height:"<<smallHeight<<"\n";
    std::cin.get();

    // 划分原始图片为N*M个小图片
    for (unsigned long i = 0; i < rows; i++) {
        for (unsigned long j = 0; j < cols; j++) {

            PieceOfImage image=PieceOfImage();

            image.location.row = i;
            image.location.col = j;
            image.size.wide = smallWidth;
            image.size.height = smallHeight;
            image.type = setType(image.location,rows,cols);
            images.push_back(image);
        }
    }
    images = toSideCode(images,cols);
    for (unsigned long i = 0; i < rows; i++) {
        for (unsigned long j = 0; j < cols; j++) {
            PieceOfImage image=images[i*cols+j];
            std::string type = image.type;
            std::map<std::string,int> sidesCode = image.sidesCode;
            sizeOfPartition = setSizeOfPartition(type,sidesCode, j * smallWidth,i * smallHeight, smallWidth, smallHeight,originalImage.cols,originalImage.rows);

            cv::Rect roi(sizeOfPartition.ltx, sizeOfPartition.lty, sizeOfPartition.wide, sizeOfPartition.height);
            cv::Mat smallImage = originalImage(roi).clone();
            images[i*cols+j].image = smallImage;
            // 保存小图片
            std::string filename = "small_image_" + std::to_string(i) + "_" + std::to_string(j) + ".jpg";
            cv::imwrite(filename, smallImage);
        }
    }
    return images;
}


void Tools::toTestSideCode(const unsigned long rows,const unsigned long cols){

    //const int c = rows*cols;
    std::vector<ImageToTest> images = std::vector<ImageToTest>();

    //ImageToTest images[c];
    for(unsigned long i=0;i<rows;i++){
        for(unsigned long j = 0;j<cols;j++){
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

    for(unsigned long i=0;i<images.size();i++){
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

    for(unsigned long i=0;i<rows;i++){
        for(unsigned long j=0;j<cols;j++){
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
