#include <opencv2/opencv.hpp>
#include <tools.h>

using namespace std;

int main() {
    Tools tools = Tools();
    // // 读取原始图片
    //cv::Mat originalImage = cv::imread("E:\\QtProjs\\PartitionOfImage\\1.jpg",cv::IMREAD_UNCHANGED);
    cv::Mat originalImage = cv::imread("/Users/lpcw/QtProjs/automatic-image-segmentation/1.jpg",cv::IMREAD_COLOR);
    //cv::Mat  originalImage = tools.toAlphaImage(inputImage); //.clone();

    std::vector<PieceOfImage> smallImages = tools.toPartition(originalImage,2,2);
    int i=0;
    for(PieceOfImage smallImage:smallImages){

        //smallImage.setKeyPoints();
        cv::Mat image = smallImage.shapedImage.clone();
        KeyPoints keyPoints = smallImage.getKeyPoints();

        cv::rectangle(image, keyPoints.externalScope.ltp, keyPoints.externalScope.rbp,cv::Scalar(0, 0, 255), 2);
        cv::rectangle(image, keyPoints.internalScope.ltp, keyPoints.internalScope.rbp, cv::Scalar(255, 0, 0), 2); // 左上角和右下角坐标，颜色，线宽

        // 在图片上绘制圆形
        for(CircleScope circle:smallImage.getKeyPoints().circleScopes){
            std::cout << "圆："<<circle.center<<","<<circle.r<<","<<circle.code<<"\n";
            if(circle.code !=0){
                cv::circle(image, circle.center, circle.r, cv::Scalar(0, 255, 0), 2); // 圆心坐标，半径，颜色，线宽
            }
        }

        std::string filename = "shapedImage_" + std::to_string(i) + "_" + std::to_string(i) + ".jpg";
        cv::imwrite(filename, image);
        i++;
        // 显示绘制后的图片
        cv::imshow("Image with shapes", image);
        cv::waitKey(0);
        cv::destroyAllWindows();

        smallImage.shapedImage=image.clone();

        tools.toShapeImage(smallImage);
    }


    //std::cin.get();

    return 0;
}
