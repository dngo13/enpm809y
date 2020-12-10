#include <ros/ros.h>
#include <nav_msgs/Odometry.h>


/**
 * This is the callback function that will get called when a new message
 * has arrived on the Topic /odom.
*/
void OdomCallback(const nav_msgs::Odometry::ConstPtr& odom){
    ROS_INFO("I received odom: [%f,%f,%f]",
             odom->pose.pose.position.x,
             odom->pose.pose.position.y,
             odom->pose.pose.position.z); //store x,y,z position values
}

int main(int argc, char **argv){
 /**
  * The ros::init() function needs to see argc and argv so that it can perform
  * any ROS arguments and name remapping that were provided at the command line.
  * For programmatic remappings you can use a different version of init() which takes
  * remappings directly, but for most command-line programs, passing argc and argv is
  * the easiest way to do it.  The third argument to init() is the name of the node.
  *
  * You must call one of the versions of ros::init() before using any other
  * part of the ROS system.
  */
    ros::init(argc, argv, "odom_subscriber");


    /**
     * NodeHandle is the main access point to communications with the ROS system.
     * The first NodeHandle constructed will fully initialize this node, and the last
     * NodeHandle destructed will close down the node.
     */
    ros::NodeHandle nh;
    /**
     * The subscribe() call is how you tell ROS that you want to receive messages
     * on a given topic.  This invokes a call to the ROS
     * master node, which keeps a registry of who is publishing and who
     * is subscribing.  Messages are passed to a callback function, here
     * called OdomCallback.  subscribe() returns a Subscriber object that you
     * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
     * object go out of scope, this callback will automatically be unsubscribed from
     * this topic.
     *
     * The second parameter to the subscribe() function is the size of the message
     * queue.  If messages are arriving faster than they are being processed, this
     * is the number of messages that will be buffered up before beginning to throw
     * away the oldest ones.
     */

    /**
     * Subscribe to the Topic /odom with the master.
     * ROS will call the OdomCallback() function whenever a new message arrives.
     * The 2nd argument is the queue size, in case we are not able to process messages fast enough.
     * In this case, if the queue reaches 1000 messages, we will start throwing away old messages as new ones arrive.
     */
    ros::Subscriber sub_odom = nh.subscribe("odom", 1000, &OdomCallback);

     /**
      * ros::spin() will enter a loop, pumping callbacks.  With this version, all
      * callbacks will be called from within this thread (the main one).  ros::spin()
      * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
      */
    ros::spin();
}
