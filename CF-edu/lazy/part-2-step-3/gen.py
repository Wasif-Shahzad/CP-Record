import sys

# Configuration
N = 100000  # Max array size
M = 100000  # Max queries

def main():
    # Redirect output to a file or stdout
    # usage: python3 gen.py > test.txt
    
    print(f"{N} {M}")

    # 1. Fill the array with 1s.
    # We use a single range update covering [0, N).
    # This sets the Total Sum to 200,000.
    print(f"1 0 {N}")

    # 2. Generate Queries.
    # We have M-1 queries left.
    # We always ask for k = N-1 (the last index).
    # Your code does k++, so it looks for the N-th item (value 200,000).
    # This forces 'find' to recurse all the way to the right.
    # At every step, it calls 'query(left_range)', which is slow.
    
    for _ in range(M - 1):
        print(f"2 {N-1}")

if __name__ == "__main__":
    main()