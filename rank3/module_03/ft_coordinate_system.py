import math


def get_player_pos() -> tuple:
    while True:
        try:
            s: str = input("Enter new coordinates "
                           "as floats in format 'x,y,z': ")
            if s.count(',') != 2:
                raise SyntaxError("Invalid syntax")
            c: tuple = tuple((float(part.strip()) for part in s.split(',')))
            break
        except SyntaxError as e:
            print(f"{e}")
        except ValueError as e:
            msg: str = str(e)
            print(f"Error on parameter{msg.split(": ")[-1]} : {e}")
    return (c)


def calculate_distance(c: tuple, c2: tuple) -> float:
    return (math.sqrt((c2[0]-c[0])**2 + (c2[1]-c[1])**2 + ((c2[2]-c[2]))**2))


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    c = get_player_pos()
    print(f"Got a first touple: ({c})")
    print(f"It includes: X={c[0]}, Y={c[1]}, Z={c[2]}")
    print(f"Distance to center: {round(calculate_distance(c, (0, 0, 0)), 4)}")
    print("\nGet a second set of coordinates")
    c1 = get_player_pos()
    print("Distance between"
          f" the 2 sets of coordinates: {round(calculate_distance(c, c1), 4)}")
