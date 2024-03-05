#include <memory>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

int main(int argc,char **argv)
{   rclcpp::init(argc,argv);
    auto logger=rclcpp::get_logger("rclcpp");
    if (argc!=4)
    {
        RCLCPP_INFO(logger,"invaild numbers \n usage:"
        "$ros2 run turtle_cpp turtle_move_cpp x y (z is angular)");
        return 1;
    }
     rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("turtle_move");
    pub_ =node->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel",10);
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x=atof(argv[1]);
    msg.linear.y=atof(argv[2]);
    msg.angular.z = atof(argv[3]);
    pub_->publish(msg);
  rclcpp::shutdown();
  return 0;
}
    

