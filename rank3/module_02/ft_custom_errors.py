class GardenError(Exception):
    def __init__(self,  message: str = "Unknown GardenError"):
        super().__init__(message)

class PlantError(GardenError):
    def __init__(self,  message: str = "Unknown PlantError"):
        super().__init__(message)

class WaterError(GardenError):
    def __init__(self,  message: str = "Unknown WaterError"):
        super().__init__(message)

def garden_status(op_num: int) -> None:
    water_vol: int = 200
    days_since_water: int = 2
    if (op_num == 0):
        water_vol: int = 50
    if (op_num == 1):
        days_since_water: int = 10
    if (op_num == 2):
        days_since_water: int = 10
    if (op_num == 3):
        water_vol: int = 50
    plant: str = "tomato"
    if (water_vol < 100):
        raise WaterError("Not enough water in the tank!")
    if (days_since_water > 3):
        raise PlantError(f"The {plant} plant is wilting!")


def  test_garden_errors() -> None:
    print("\nTesting PlantError...")
    try:
        garden_status(1)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    else:
        print("No errors")
    print("\nTesting WaterError...")
    try:
        garden_status(0)
    except WaterError as e: 
        print(f"Caught WaterError: {e}")
    else:
        print("No errors")
    print("\nTesting catching all garden errors...")
    for i in range(2, 4):
        try:
            garden_status(i)
        except GardenError as e:
            print(f"Caught GardenError: {e}")
        else:
            print("No errors")
    print("\nAll custom error types work correctly!")



if __name__ == "__main__":
    test_garden_errors()