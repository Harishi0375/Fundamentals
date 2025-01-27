#!/usr/bin/env python3

import rosbag
import sys
from robot_action.msg import MoveToGoalActionFeedback

def extract_feedback(bag_file):
    """Extract and display feedback messages from the bag file."""
    try:
        bag = rosbag.Bag(bag_file)

        # Iterate through the bag file
        for topic, msg, t in bag.read_messages(topics=['/move_to_goal/feedback']):
            # Accessing the feedback field inside MoveToGoalActionFeedback
            feedback = msg.feedback
            print(f"Time: {t.to_sec()}, Remaining Distance: {feedback.remaining_distance}")

        bag.close()

    except Exception as e:
        print(f"Error reading bag file: {e}")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: extract_feedback.py <bag_file>")
        sys.exit(1)

    bag_file = sys.argv[1]
    extract_feedback(bag_file)
