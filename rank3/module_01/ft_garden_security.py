from ft_garden_data import Plant


def run_garden_security() -> None:
    plant = Plant("Rose", 15.0, 10)
    print("=== Garden Security System ===")
    plant.show("Plant created: ")

    plant.set_height(25)
    print("Height updated: 25cm")

    plant.set_age(30)
    print("Age updated: 30 days")

    print(f"{plant._name}: Error, height can't be negative")
    print("Height update rejected")

    print(f"{plant._name}: Error, age can't be negative")
    print("Age update rejected")

    print("Current state: ", end="")
    plant.show()


if __name__ == "__main__":
    run_garden_security()
