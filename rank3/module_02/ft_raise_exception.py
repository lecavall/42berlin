def input_temperature(temp_str: str) -> int:
    print(f"\nInput data is '{temp_str}'")
    try:
        temp: int = int(temp_str)
        if (temp < 0):
            raise ValueError("-50°C is too cold for plants (min 0°C)")
        if (temp > 40):
            raise ValueError("100°C is too hot for plants (max 40°C)")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    except Exception as e:
        print(f"Caught other error: {e}")
    else:
        print(f"Temperature is now {temp}°C")
    finally:
        None


def test_temperature() -> None:
    input_temperature("25")
    input_temperature("abc")
    input_temperature("41")
    input_temperature("-1")
    print("\nAll tests completed - Program didn't crash!")


if __name__ == "__main__":
    test_temperature()