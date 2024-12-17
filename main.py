import argparse


def add_str_number(s: str) -> int:
    total = 0
    for c in s:
        if c.isdigit():
            total += int(c)
    return total


if __name__ == "__main__":
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Sum the digits in a string.")
    parser.add_argument(
        "input_string", type=str, help="The string containing digits to sum."
    )

    # Parse arguments
    args = parser.parse_args()

    # Calculate sum of digits and print the result
    result = add_str_number(args.input_string)
    print(f"{result}")
