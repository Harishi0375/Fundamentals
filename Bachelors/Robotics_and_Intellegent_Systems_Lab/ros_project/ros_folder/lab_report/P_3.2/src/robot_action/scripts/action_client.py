#!/usr/bin/env python3

import rospy
import actionlib
from robot_action.msg import MoveToGoalAction, MoveToGoalGoal

def feedback_cb(feedback):
    """Callback to process feedback from the action server."""
    rospy.loginfo(f"Feedback received: Remaining distance = {feedback.remaining_distance}")

def send_goal(client, x, y):
    """Send a goal to the action server."""
    goal = MoveToGoalGoal(x=x, y=y)
    client.send_goal(goal, feedback_cb=feedback_cb)

    # Wait for the result
    client.wait_for_result()
    return client.get_result()

if __name__ == '__main__':
    rospy.init_node('move_to_goal_action_client')

    # Create an action client for 'move_to_goal' action
    client = actionlib.SimpleActionClient('move_to_goal', MoveToGoalAction)

    # Wait until the action server is ready
    rospy.loginfo("Waiting for action server to start...")
    client.wait_for_server()

    rospy.loginfo("Action server started, sending goals to the server...")

    # Define a list of goals (x, y) to send
    goals = [(2.0, 3.0), (4.0, 5.0), (6.0, 8.0)]

    for i, (x, y) in enumerate(goals):
        rospy.loginfo(f"Sending goal {i+1}: x={x}, y={y}")
        result = send_goal(client, x, y)

        # Process the result from the server
        if result.success:
            rospy.loginfo(f"Goal {i+1} reached successfully!")
        else:
            rospy.loginfo(f"Goal {i+1} failed to reach.")

        rospy.sleep(2)  # Optional: wait between goals

    rospy.loginfo("All goals sent.")
