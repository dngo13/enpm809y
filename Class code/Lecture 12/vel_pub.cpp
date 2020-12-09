
/*
 * Publish randomly-generated velocity Messages on /cmd_vel Topic.
 */
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  //--for geometry_msgs::Twist
#include <stdlib.h> //--for rand() and RAND_MAX

int main(int argc, char **argv) {
    /*
     * The ros::init() function needs to see argc and argv so that it can perform
     * any ROS arguments and name remapping that were provided at the command line.
     * For programmatic remappings you can use a different version of init() which takes
     * remappings directly, but for most command-line programs, passing argc and argv is
     * the easiest way to do it.  The third argument to init() is the name of the node.
     *
     * You must call one of the versions of ros::init() before using any other
     * part of the ROS system.
     */
    ros::init(argc, argv, "cmd_vel_publisher");
    /*
     * NodeHandle is the main access point to communications with the ROS system.
     * The first NodeHandle constructed will fully initialize this node, and the last
     * NodeHandle destructed will close down the node.
     */
    ros::NodeHandle nh;

    /*
     * The advertise() function is how you tell ROS that you want to
     * publish on a given topic name. This invokes a call to the ROS
     * master node, which keeps a registry of who is publishing and who
     * is subscribing. After this advertise() call is made, the master
     * node will notify anyone who is trying to subscribe to this topic name,
     * and they will in turn negotiate a peer-to-peer connection with this
     * node.  advertise() returns a Publisher object which allows you to
     * publish messages on that topic through a call to publish().  Once
     * all copies of the returned Publisher object are destroyed, the topic
     * will be automatically unadvertised.
     *
     * The second parameter to advertise() is the size of the message queue
     * used for publishing messages.  If messages are published more quickly
     * than we can send them, the number here specifies how many messages to
     * buffer up before throwing some away.
     */
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    //--seed the random number generator.
    srand(time(0));

    /*
     * A ros::Rate object allows you to specify a frequency that you would like to loop at.
     * It will keep track of how long it has been since the last call to Rate::sleep(),
     * and sleep for the correct amount of time.
     */
    ros::Rate loop_rate(2);

    /*
     * ros::ok() will return false if:
     * - A SIGINT is received (Ctrl-C)
     * - We have been kicked off the network by another node with the same name
     * - ros::shutdown() has been called by another part of the application.
     * - All ros::NodeHandles have been destroyed
     */


    while(ros::ok()) {
        /*
         * This is a message object. You stuff it with data, and then publish it.
         * We are just providing linear.x and angular.z
         * The other 4 fields (linear.y, linear.z, angular.x, and angular.y) default to 0
         */

        //--RAND_MAX: This macro expands to an integral constant expression whose
        // value is the maximum value returned by the rand function.
        // This value is library-dependent, but is guaranteed to be at least 32767 on
        // any standard library implementation.
        geometry_msgs::Twist msg;
        msg.linear.x = double(rand())/double(RAND_MAX);
        msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

        /*
         * The publish() function is how you send messages. The parameter
         * is the message object. The type of this object must agree with the type
         * given as a template parameter to the advertise<>() call, as was done
         * in the constructor above.
         */
        pub.publish(msg);

        //--send a message to rosout with the details.
        //--See http://wiki.ros.org/roscpp/Overview/Logging
            ROS_INFO_STREAM("Sending random velocity command:"
            << " linear=" << msg.linear.x
            << " angular=" << msg.angular.z);

        /*
         * Each call to this method causes a delay in the program.
         * The duration of the delay is calculated to prevent the loop from iterating faster
         * than the specified rate.
        */
        loop_rate.sleep();
    }
    return 0;
}
