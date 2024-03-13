#include <opencv2/opencv.hpp>
#include <tools.h>

using namespace std;

int main() {
    Tools tools = Tools();
    // // 读取原始图片
    //cv::Mat originalImage = cv::imread("E:\\QtProjs\\PartitionOfImage\\1.jpg",cv::IMREAD_UNCHANGED);
    cv::Mat inputImage = cv::imread("/Users/lpcw/QtProjs/automatic-image-segmentation/1.jpg",cv::IMREAD_COLOR);
    cv::Mat  originalImage = tools.toAlphaImage(inputImage); //.clone();

    // // 定义划分份数N和M
    // int N = 3; // 宽度划分份数
    // int M = 2; // 高度划分份数

    // // 计算小图片的宽度和高度
    // int smallWidth = originalImage.cols / N;
    // int smallHeight = originalImage.rows / M;

    // // 划分原始图片为N*M个小图片
    // for (int i = 0; i < N; i++) {s
    //     for (int j = 0; j < M; j++) {
    //         cv::Rect roi(i * smallWidth, j * smallHeight, smallWidth, smallHeight);
    //         cv::Mat smallImage = originalImage(roi).clone();

    //         // 保存小图片
    //         std::string filename = "small_image_" + std::to_string(i) + "_" + std::to_string(j) + ".jpg";
    //         cv::imwrite(filename, smallImage);
    //     }
    // }
    //Tools tools = Tools();
    //tools.toTestSideCode(3,5);
    std::vector<PieceOfImage> smallImages = tools.toPartition(originalImage,2,2);
    //int i=0;
    for(PieceOfImage smallImage:smallImages){

        smallImage.setKeyPoints();
        cv::Mat image = smallImage.image.clone();
        KeyPoints keyPoints = smallImage.getKeyPoints();
/*
        cv::rectangle(image, keyPoints.externalScope.ltp, keyPoints.externalScope.rbp,cv::Scalar(255, 0, 0), 2);
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
*/
        smallImage.image=image.clone();

        tools.toShapeImage(smallImage);
    }


    //std::cin.get();

    return 0;
}
