from ft_garden_data import Plant


def run_garden_factory() -> None:
    p1: Plant = Plant("Rose", 10.5, 30)
    p2: Plant = Plant("Tree", 30000.5, 10000)
    p3: Plant = Plant("Cucumber", 5, 3)
    p4: Plant = Plant("Maracuja", 25, 20)
    p5: Plant = Plant("noname", 1, 300)
    print("=== Plant Fatory Output ===")
    prev: str = "Created: "
    p1.show(prev)
    p2.show(prev)
    p3.show(prev)
    p4.show(prev)
    p5.show(prev)


if __name__ == "__main__":
    run_garden_factory()
