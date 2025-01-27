import random

def generate_random_sequence(n, min_val=0, max_val=19):
    return [random.randint(min_val, max_val) for _ in range(n)]

def generate_case_A_sequence(n):
    return list(range(n))

def generate_case_B_sequence(n):
    return list(range(n, 0, -1))

# Example usage:
n = 20  # Length of sequences
random_seq = generate_random_sequence(n)
case_A_seq = generate_case_A_sequence(n)
case_B_seq = generate_case_B_sequence(n)

print("Random Sequence:", random_seq)
print("Case A Sequence:", case_A_seq)
print("Case B Sequence:", case_B_seq)


# generate_random_sequence function generates a random sequence of length n with values between min_val and max_val.

# generate_case_A_sequence function generates a sequence in increasing order.

# generate_case_B_sequence function generates a sequence in decreasing order.
