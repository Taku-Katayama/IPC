#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
//ROS用に追加
#include"ros/ros.h"//ROS用のヘッダ
#define BUFFER_SIZE 1024 //256 = 1 byte
#define DATABUFFER 1024
#define IP_Number "192.168.11.27"

int main(int argc,char **argv)//ROS用に追加()→ (int argc,char **argv)
{
//ROS用に追加
	ros::init(argc,argv,"helo_node");//ROSのノードの生成
//-----------
    std::cout << "helo" << std::endl;
    return 0;
}
