#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "nav_msgs/OccupancyGrid.h"


class Number_Pub 
{
public:
    Number_Pub();
    void publish_num();
private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
};

Number_Pub::Number_Pub(){
    pub_ = nh_.advertise<std_msgs::Int16>("number", 10, false);
}

void Number_Pub::publish_num(){
    static int count;
    std_msgs::Int16 number;
    number.data = count%10;
    pub_.publish(number);
    count++;
}


int main(int argc, char **argv){

ros::init(argc, argv, "number_pub");
Number_Pub number_pub;
ros::Rate loop_rate(1);

while (ros::ok()){
    number_pub.publish_num();
    ros::spinOnce();
    loop_rate.sleep();
}
  return 0;
}
