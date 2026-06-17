

def garden_operations(operation_number: int) -> None:
    if (operation_number == 0):
        num: int = int("hello")
    elif (operation_number == 1):
        x: int = 5 / 0
    elif (operation_number == 2):
        x = open("/hello")
    elif (operation_number == 3):
        x = "number" + 3
    else:
        return ();

def test_error_types() -> None:
    for i in range(5):   
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")
        else:
            print("Operation completed succesfully")
    print("All error types tested succesfully!")

# How can I make it with one except statement? Where can I get the type of error from


if __name__ == "__main__":
    test_error_types()