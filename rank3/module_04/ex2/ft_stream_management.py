#!/usr/bin/env python3

import sys
import typing


def read_file(filename: str) -> str:
    print(f"Accessing file '{filename}'")
    print("---")
    try:
        f = open(filename, 'r')
    except OSError as e:
        sys.stdout.write(f"[STDERR] Error opening file '{filename}': {e}")
        sys.exit(1)
    content = f.read()
    f.close()
    print("---")
    print(f"File '{filename}' closed.")
    return (content)


def transform(content: str) -> str:
    lines = content.split('\n')
    new_lines = [line + '#' for line in lines]
    return '\n'.join(new_lines)


def save_file(filename: str, content: str) -> None:
    try:
        f = open(filename, 'w')
    except OSError as e:
        sys.stdout.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        print("Data not saved.")
        return
    f.write(content)
    f.close()
    print(f"Data saved in file '{filename}'.")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        sys.exit(1)
    print("=== Cyber Archives Recovery & Preservation ===")
    content = read_file(sys.argv[1])
    new_content = transform(content)
    print("Transform data:")
    print("---")
    print(new_content)
    print("---")
    # TODO: replace with sys.stdout.write(), sys.stdout.flush(), sys.stdin.readline().strip('\n')
    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    save_name = sys.stdin.readline().strip('\n')
    if not save_name:
        print("Not saving data.")
    else:
        print(f"Saving data to '{save_name}'")
        save_file(save_name, new_content)
