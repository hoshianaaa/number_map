#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "nav_msgs/OccupancyGrid.h"


class Number_Map 
{
public:
    Number_Map();

private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    ros::Subscriber sub_;
    void pub_map(int number);
    void numberCallback(const std_msgs::Int16::ConstPtr& msg);
};

Number_Map::Number_Map(){
    pub_ = nh_.advertise<nav_msgs::OccupancyGrid>("number_map", 10, false);
    sub_ = nh_.subscribe<std_msgs::Int16>("number", 1000, &Number_Map::numberCallback,this);
    Number_Map::pub_map(0);

}

void Number_Map::pub_map(int number){

    nav_msgs::OccupancyGrid map;
    map.header.frame_id = "map";
    map.info.width = 4;
    map.info.height = 5; map.info.resolution = 1.0;
    map.info.origin.position.x = -2;
    map.info.origin.position.y = -2.5;
    map.info.origin.position.z = 0;

    int x = 0;
    for(int i=0;i<20;i++){
        map.data.push_back(x);
        map.data[i] = 100;
    }
    
    int n = number;
    int n0[] = {1,2,4,7,8,11,12,15,17,18};
    int n1[] = {1,5,9,13,17,2};
    int n2[] = {1,2,4,7,9,14,16,17,18,19};
    int n3[] = {1,2,4,7,9,12,15,17,18};
    int n4[] = {1,5,6,9,11,12,13,14,15,17};
    int n5[] = {1,2,3,7,9,10,11,12,17,18,19};
    int n6[] = {1,2,7,9,10,11,12,15,17,18};
    int n7[] = {0,1,2,3,4,9,14,18};
    int n8[] = {1,2,4,7,9,10,12,15,17,18};
    int n9[] = {1,2,4,7,8,9,10,12,17,18};

    if(n == 0){
        for(int i=0;i<sizeof(n0)/sizeof(n0[0]);i++){
            map.data[n0[i]] = 0;
        }
    }

    if(n == 1){
        for(int i=0;i<sizeof(n1)/sizeof(n1[0]);i++){
            map.data[n1[i]] = 0;
        }
    }

    if(n == 2){
        for(int i=0;i<sizeof(n2)/sizeof(n2[0]);i++){
            map.data[n2[i]] = 0;
        }
    }

    if(n == 3){
        for(int i=0;i<sizeof(n3)/sizeof(n3[0]);i++){
            map.data[n3[i]] = 0;
        }
    }

    if(n == 4){
        for(int i=0;i<sizeof(n4)/sizeof(n4[0]);i++){
            map.data[n4[i]] = 0;
        }
    }

    if(n == 5){
        for(int i=0;i<sizeof(n5)/sizeof(n5[0]);i++){
            map.data[n5[i]] = 0;
        }
    }


    if(n == 6){
        for(int i=0;i<sizeof(n6)/sizeof(n6[0]);i++){
            map.data[n6[i]] = 0;
        }
    }

    if(n == 7){
        for(int i=0;i<sizeof(n7)/sizeof(n7[0]);i++){
            map.data[n7[i]] = 0;
        }
    }

    if(n == 8){
        for(int i=0;i<sizeof(n8)/sizeof(n8[0]);i++){
            map.data[n8[i]] = 0;
        }
    }

    if(n == 9){
        for(int i=0;i<sizeof(n9)/sizeof(n9[0]);i++){
            map.data[n9[i]] = 0;
        }
    }

    pub_.publish(map);
}

void Number_Map::numberCallback(const std_msgs::Int16::ConstPtr& msg)
{
    ROS_INFO("I heard: [%d]", msg->data);
    pub_map(msg->data);
}

int main(int argc, char **argv){
ros::init(argc, argv, "number_map");
Number_Map number_map;
ros::Rate loop_rate(10);

while (ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
}
  return 0;
}
