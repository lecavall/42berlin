import sys


def test_sys(array: list) -> None:
    print("=== Command Quest ===")
    print(f"Program name: {array[0]}")
    x: int = len(array)
    if (x == 1):
        print("No arguments provided!")
        print(f"Total arguments: {x}")
    else:
        print(f"Arguments received: {x - 1}")
        for i in range(1, x):
            print(f"Argument {i}: {array[i]}")
        print(f"Total arguments: {x}")


if __name__ == "__main__":
    test_sys(sys.argv)
