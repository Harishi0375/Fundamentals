#!/usr/bin/env python

import rospy
import actionlib
from robot_action.msg import MoveToGoalAction, MoveToGoalGoal # type: ignore

def feedback_callback(feedback):
    rospy.loginfo("Distance remaining to the goal: %f", feedback.distance_remaining)

def send_goal(client, x, y):
    # Create a new goal and send it to the action server
    goal = MoveToGoalGoal(x=x, y=y)
    rospy.loginfo("Sending goal: (%f, %f)", x, y)

    # Send the goal to the server
    client.send_goal(goal, feedback_cb=feedback_callback)

    # Wait for the result from the action server
    client.wait_for_result()

    # Print out the result (whether success or not)
    result = client.get_result()
    if result.success:
        rospy.loginfo("Goal successfully reached!")
    else:
        rospy.loginfo("Failed to reach the goal.")

if __name__ == "__main__":
    rospy.init_node('move_to_goal_client')

    # Create the SimpleActionClient for the MoveToGoal action
    client = actionlib.SimpleActionClient('move_to_goal', MoveToGoalAction)

    # Wait until the action server has started
    rospy.loginfo("Waiting for the action server to start...")
    client.wait_for_server()

    rospy.loginfo("Action server started, sending goals...")

    # List of goals to send (x, y)
    goals = [(1.0, 1.0), (2.0, 3.0), (5.0, 5.0), (0.0, 0.0)]

    # Send each goal to the action server
    for goal in goals:
        send_goal(client, goal[0], goal[1])

    rospy.loginfo("All goals sent. Shutting down client.")
