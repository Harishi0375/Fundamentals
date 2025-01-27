#!/usr/bin/env python3
import rospy
import actionlib
import math
from robot_action.msg import MoveToGoalAction, MoveToGoalFeedback, MoveToGoalResult, Position  # Import custom messages
from visualization_msgs.msg import Marker  # Import Marker message for RViz visualization
import geometry_msgs.msg

class MoveToGoalActionServer:
    def __init__(self):
        # Initialize the action server
        self.server = actionlib.SimpleActionServer('move_to_goal', MoveToGoalAction, self.execute, False)
        self.server.start()

        # Publisher for robot’s position (using custom Position message)
        self.position_publisher = rospy.Publisher('robot_position', Position, queue_size=10)

        # Publisher for visualizing markers in RViz
        self.marker_publisher = rospy.Publisher('visualization_marker', Marker, queue_size=10)

        # Marker to visualize the robot’s path in RViz
        self.path_marker = Marker()
        self.initialize_path_marker()

        rospy.loginfo("Action server started, ready to move the robot to the goal position.")

    def initialize_path_marker(self):
        """Initializes the marker for visualizing the robot’s path in RViz."""
        self.path_marker.header.frame_id = "odom"  # Fixed frame in RViz
        self.path_marker.ns = "robot_path"
        self.path_marker.id = 1
        self.path_marker.type = Marker.LINE_STRIP
        self.path_marker.action = Marker.ADD
        self.path_marker.scale.x = 0.05  # Line width for the path
        self.path_marker.color.a = 1.0  # Opaque color
        self.path_marker.color.r = 0.0
        self.path_marker.color.g = 1.0  # Green color for visibility
        self.path_marker.color.b = 0.0

    def execute(self, goal):
        """Executes the action when a goal is received."""
        rospy.loginfo("Received goal: Move to (x: %f, y: %f)", goal.x, goal.y)

        # Initialize the robot’s current position
        current_x, current_y = 0.0, 0.0
        theta = 0.0  # Orientation (fixed for simplicity)
        feedback = MoveToGoalFeedback()
        result = MoveToGoalResult()
        rate = rospy.Rate(1)  # Set loop rate to 1 Hz

        while not rospy.is_shutdown():
            # Calculate the distance to the goal
            distance_to_goal = self.calculate_distance(current_x, current_y, goal.x, goal.y)

            if distance_to_goal < 0.1:
                rospy.loginfo("Goal reached!")
                result.success = True
                self.server.set_succeeded(result)
                break

            if self.server.is_preempt_requested():
                rospy.loginfo("Goal preempted!")
                result.success = False
                self.server.set_preempted(result)
                break

            # Simulate movement by updating the current position
            current_x += 0.1 * (goal.x - current_x)
            current_y += 0.1 * (goal.y - current_y)

            # Publish the updated robot position
            position_msg = Position()
            position_msg.x = current_x
            position_msg.y = current_y
            position_msg.theta = theta  # Keep orientation constant
            self.position_publisher.publish(position_msg)

            # Publish a marker in RViz to visualize the robot’s current position
            self.publish_marker(current_x, current_y, theta)

            # Update and publish the path marker
            self.update_path_marker(current_x, current_y)

            # Send feedback with the remaining distance
            feedback.remaining_distance = distance_to_goal
            self.server.publish_feedback(feedback)

            rate.sleep()

    def publish_marker(self, x, y, theta):
        """Publishes a marker showing the robot’s current position in RViz."""
        marker = Marker()
        marker.header.frame_id = "odom"  # Ensure this matches the fixed frame in RViz
        marker.header.stamp = rospy.Time.now()
        marker.ns = "robot_position"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = x
        marker.pose.position.y = y
        marker.pose.position.z = 0.0
        marker.pose.orientation.w = 1.0  # Orientation set to neutral
        marker.scale.x = 0.2  # Set the marker’s size
        marker.scale.y = 0.2
        marker.scale.z = 0.2
        marker.color.a = 1.0  # Fully opaque
        marker.color.r = 1.0  # Red color for visibility
        marker.color.g = 0.0
        marker.color.b = 0.0
        self.marker_publisher.publish(marker)

    def update_path_marker(self, x, y):
        """Adds the robot’s current position to the path marker for RViz visualization."""
        new_point = geometry_msgs.msg.Point()
        new_point.x = x
        new_point.y = y
        new_point.z = 0.0
        self.path_marker.points.append(new_point)

        # Update the timestamp and publish the path marker
        self.path_marker.header.stamp = rospy.Time.now()
        self.marker_publisher.publish(self.path_marker)

    def calculate_distance(self, x1, y1, x2, y2):
        """Calculates the Euclidean distance between two points."""
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

if __name__ == '__main__':
    rospy.init_node('move_to_goal_action_server')  # Initialize the ROS node
    server = MoveToGoalActionServer()  # Instantiate the action server
    rospy.spin()  # Keep the server running
