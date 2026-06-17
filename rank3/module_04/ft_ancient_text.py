#!/usr/bin/env python3

import sys
import typing


def read_file(filename: str) -> None:
    print(f"Accessing file '{filename}'")
    try:
        f = open(filename, 'r')
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)
    print("---\n")
    content: str = f.read()
    print(f"{content}")
    f.close()
    print("\n---")
    print(f"File '{filename}' closed.")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        sys.exit(1)
    print("=== Cyber Archives Recovery ===")
    read_file(sys.argv[1])
