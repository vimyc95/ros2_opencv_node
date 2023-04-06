#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>


void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    // cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
    cv::imshow("image", cv_ptr->image);
    cv::waitKey(1);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("image_subscriber");
    auto subscription = node->create_subscription<sensor_msgs::msg::Image>("/camera/color/image_raw", 10, image_callback);
    
    rclcpp::Rate loop_rate(30);

    while(rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "%s\n", "fucking gulu");
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    return 0;
}