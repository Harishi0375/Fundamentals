#!/usr/bin/env python

import rospy
import actionlib
from robot_action.msg import MoveToGoalAction, MoveToGoalFeedback, MoveToGoalResult # type: ignore


import math

class MoveToGoalActionServer:
    def __init__(self):
        # Create an action server
        self.server = actionlib.SimpleActionServer('move_to_goal', MoveToGoalAction, self.execute, False)
        self.server.start()
        rospy.loginfo("MoveToGoal Action Server started.")
    
    def execute(self, goal):
        rospy.loginfo("Goal received: Moving to (%f, %f)", goal.x, goal.y)

        # Initial position of the robot
        current_x, current_y = 0.0, 0.0
        success = False
        rate = rospy.Rate(1)  # 1 Hz

        feedback = MoveToGoalFeedback()
        result = MoveToGoalResult()

        while not rospy.is_shutdown():
            # Calculate remaining distance
            remaining_distance = math.sqrt((goal.x - current_x)**2 + (goal.y - current_y)**2)

            # Check if we reached the goal
            if remaining_distance < 0.1:  # Tolerance of 0.1 units
                success = True
                rospy.loginfo("Goal reached!")
                break

            # Provide feedback
            feedback.distance_remaining = remaining_distance
            self.server.publish_feedback(feedback)

            # Simulate movement: Let's assume it moves 0.5 units per second towards the goal
            direction_x = (goal.x - current_x) / remaining_distance
            direction_y = (goal.y - current_y) / remaining_distance
            current_x += 0.5 * direction_x
            current_y += 0.5 * direction_y

            rospy.loginfo("Current position: (%f, %f), Distance remaining: %f", current_x, current_y, remaining_distance)

            # Check for preemption (if the goal was canceled)
            if self.server.is_preempt_requested():
                rospy.loginfo("Goal preempted!")
                self.server.set_preempted()
                return

            # Sleep to maintain the loop rate
            rate.sleep()

        # Set result based on whether the goal was achieved
        result.success = success
        self.server.set_succeeded(result)

if __name__ == "__main__":
    rospy.init_node('move_to_goal_server')
    server = MoveToGoalActionServer()
    rospy.spin()
