from ft_garden_data import Plant


def simulate_plant(name: str, height: float, age: int, growth: int, days: int) -> None:
    specimen: Plant = Plant(name, height, age, growth)
    print("=== Garden Plant Growth ===")
    temp: float = specimen.height
    for i in range(days):
        print(f"=== Day {i + 1} ===")
        specimen.new_day()
    print("=== Garden Plant Growth ===")
    print(f"Simulated growth: {specimen.height - temp}cm")


if __name__ == "__main__":
    x: int = int(input("Do you want to track a new plant? (0 or 1)"))
    if (x == 1):
        name: str = input("What should be it's name?")
        height: float = float(input("What is it's height in cm?"))
        age: int = int(input(f"How old is the {name}"))
        growth: int = int(input("What is it's averae growth per day?"))
        days: int = int(input("How many days of growth will you simulate?"))
        simulate_plant(name, height, age, growth, days)
    else:
        print("Error. Try again.")
