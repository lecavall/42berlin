
class Plant:
    def __init__(self, name: str, height: float, age: int, behavior: int = 0):
        self._name: str = name
        self._behavior: int = behavior
        self._height: float = height
        self._age: int = age

    def set_height(self, safe_height: float) -> None:
        if (safe_height < 0):
            print("Error, height can't be negative")
        else:
            self._height = safe_height

    def set_age(self, safe_age: int) -> None:
        if (safe_age < 0):
            print("Error, age can't be negative")
        elif (safe_age > 109575):
            print("Error, plant can't be older than 300 years")
        else:
            self._age = safe_age

    def get_height(self) -> float:
        return (self._height)

    def get_age(self) -> int:
        return (self._age)

    def show(self, prev: str = "") -> None:
        print(f"{prev}{self._name}: {self._height}cm, {self._age} days old")

    def aging(self) -> None:
        self._age += 1

    def grow(self) -> None:
        self._height += self._behavior

    def new_day(self) -> None:
        self.aging()
        self.grow()
        self.show()


def add_plant(name: str, height: float, age: int) -> Plant:
    new_plant = Plant(name, height, age)
    return (new_plant)


if __name__ == "__main__":
    p1 = add_plant("Maracuja", 25, 30)
    p2 = add_plant("Tree ", 50, 100)
    p3 = add_plant("Rose", 25, 30)
    p1.show()
    p2.show()
    p3.show()
