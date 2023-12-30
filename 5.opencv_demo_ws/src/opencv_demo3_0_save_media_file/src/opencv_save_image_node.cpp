#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"


class OpenCV_Node: public rclcpp::Node
{
  public:
    OpenCV_Node();
    bool Save_Image(void);
    void AlphaMat(cv::Mat *mat);
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc,argv);

  auto opencv_node__ = std::make_shared<OpenCV_Node>();
  rclcpp::spin(opencv_node__);

  rclcpp::shutdown();

  return 0;
}

OpenCV_Node::OpenCV_Node():Node("opencv_node")
{
  this->Save_Image();
}

bool OpenCV_Node::Save_Image(void)
{
  cv::Mat mat__(480,640,CV_8UC4);
  this->AlphaMat(&mat__);
  std::vector<int> compression_params;
  compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);   //PNG图像压缩标志
  compression_params.push_back(9);   //设置最高压缩质量
  if(cv::imwrite("./src/opencv_demo3_0_save_media_file/save_files/save_image_test1.png",mat__,compression_params) == false)
  {
    RCLCPP_INFO(this->get_logger(),"保存成PNG图像失败");
    return false;
  }
  RCLCPP_INFO(this->get_logger(),"保存成PNG图像成功");
  return true;
}

void OpenCV_Node::AlphaMat(cv::Mat *mat)
{
  CV_Assert(mat->channels() == 4);  //如果通道不等于4，那么抛出异常
  for(int i = 0;i < mat->rows;i++)   //行
  {
    for(int j = 0;j < mat->cols;j++)    //列
    {
      /*
      cv::Vec4b bgra = mat->at<cv::Vec4b>(i,j);
      bgra.val[0] = cv::saturate_cast<uint8_t>(255);    //B:255   //该函数防止溢出，里面的数只能是0-255
      bgra.val[1] = cv::saturate_cast<uint8_t>(0);      //G:0
      bgra.val[2] = cv::saturate_cast<uint8_t>(0);      //R:0
      bgra.val[3] = cv::saturate_cast<uint8_t>(180);    //α:180
      */
      cv::Vec4b &bgra = mat->at<cv::Vec4b>(i,j);
      bgra[0] = cv::saturate_cast<uint8_t>(255);     //B:255   //该函数防止溢出，里面的数只能是0-255
      bgra[1] = cv::saturate_cast<uint8_t>(0);      //G:0   //重载运算符[]
      bgra[2] = cv::saturate_cast<uint8_t>(0);      //R:0
      bgra[3] = cv::saturate_cast<uint8_t>(90);     //α:90
    }
  }
}