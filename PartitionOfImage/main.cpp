#include <opencv2/opencv.hpp>
#include <tools.h>

using namespace std;

int main() {
    // // 读取原始图片
    cv::Mat originalImage = cv::imread("C:\\Users\\oosio\\Documents\\QtProjs\\PartitionOfImage\\1.jpg");

    // // 定义划分份数N和M
    // int N = 3; // 宽度划分份数
    // int M = 2; // 高度划分份数

    // // 计算小图片的宽度和高度
    // int smallWidth = originalImage.cols / N;
    // int smallHeight = originalImage.rows / M;

    // // 划分原始图片为N*M个小图片
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cv::Rect roi(i * smallWidth, j * smallHeight, smallWidth, smallHeight);
    //         cv::Mat smallImage = originalImage(roi).clone();

    //         // 保存小图片
    //         std::string filename = "small_image_" + std::to_string(i) + "_" + std::to_string(j) + ".jpg";
    //         cv::imwrite(filename, smallImage);
    //     }
    // }
    Tools tools = Tools();
    //tools.toTestSideCode(3,5);
    tools.toPartition(originalImage,2,2);

    std::cin.get();

    return 0;
}
