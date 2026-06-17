def test_temperature(temp_str: str) -> None:
    try:
        temp: int = int(temp_str)
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    except Exception as e:
        print(f"Caught other error: {e}")
    else:
        print(f"Temperature is now {temp}°C")
    finally:
        None


def input_temperature(temp_str: str) -> int:
    print(f"\nInput data is '{temp_str}'")
    test_temperature(temp_str)


if __name__ == "__main__":
    input_temperature("25")
    input_temperature("abc")
    print("\nAll tests completed! Program didn't crash")