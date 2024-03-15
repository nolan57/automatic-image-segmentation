#include <opencv2/opencv.hpp>
#include <tools.h>

using namespace std;

int main() {
    Tools tools = Tools();
    // // 读取原始图片
    cv::Mat inputImage = cv::imread("E:\\QtProjs\\automatic-image-segmentation\\1.jpg");
    //cv::Mat originalImage = cv::imread("/Users/lpcw/QtProjs/automatic-image-segmentation/1.jpg",cv::IMREAD_COLOR);
     //.clone();
    cv::Mat originalImage;
    if(inputImage.channels() == 4){
        std::cout << "image has 4 Channels"<<"\n";
        originalImage = inputImage.clone();
    }else{
        std::cout << "image doesn't has 4 Channels"<<"\n";
        originalImage = tools.addAlphaToImage(inputImage);
        std::cout << "image now has "<<originalImage.channels() <<"channels"<<"\n";
    }

    std::vector<PieceOfImage> smallImages = tools.toPartition(originalImage,3,3);
    // for(PieceOfImage smallImage:smallImages){

    //     tools.toShapeImage(smallImage);

    // }

    for(int i = 0;i<smallImages.size();i++){

        tools.toShapeImage(smallImages[i]);

    }

    for(PieceOfImage smallImage:smallImages){

        std::string filename = "shapedImage_[" +
                               std::to_string(smallImage.location.col) + "," +
                               std::to_string(smallImage.location.row) + "]" + "_" + ".png";
        cv::imwrite(filename, smallImage.shapedImage);

        cv::imshow("Image with shapes", smallImage.shapedImage);
        cv::waitKey(0);
        cv::destroyAllWindows();

        }

    return 0;
}
