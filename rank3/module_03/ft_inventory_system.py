#!/usr/bin/env python3

import sys


def parse_args(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in args:
        if ':' not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue
        parts = arg.split(':')
        name = parts[0]
        quantity = parts[1]
        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue
        try:
            qty = int(quantity)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
            continue
        if qty < 0:
            print(f"Error - quantity for '{name}' cannot be negative")
            continue
        inventory[name] = qty
    return inventory


def display_inventory(inventory: dict[str, int]) -> None:
    print(f"Got inventory: {inventory}")


def list_items(inventory: dict[str, int]) -> None:
    print(f"Item List: {list(inventory.keys())}")


def total_quantity(inventory: dict[str, int]) -> None:
    print(f"Total quantity of the {len(inventory)} items: "
          f"{sum(list(inventory.values()))}")


def quantity_percentages(inventory: dict[str, int]) -> None:
    qty: int = sum(list(inventory.values()))
    for arg in inventory:
        print(f"Item {arg} represents {round((inventory[arg]/qty) * 100, 1)}%")


def most_least_abundant(inventory: dict[str, int]) -> None:
    name = max(inventory, key=lambda item: inventory[item])
    print(f"Item most abundant: {name} with quantity "
          f"{max(list(inventory.values()))}")
    name = min(inventory, key=lambda item: inventory[item])
    print(f"Item least abundant: {name} with quantity "
          f"{min(list(inventory.values()))}")


def add_item(inventory: dict[str, int], item: str, quantity: int) -> None:
    inventory.update({item: quantity})


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error - no arguments provided")
        sys.exit(1)
    inventory = parse_args(sys.argv[1:])
    display_inventory(inventory)
    list_items(inventory)
    total_quantity(inventory)
    quantity_percentages(inventory)
    most_least_abundant(inventory)
    add_item(inventory, "magic_item", 1)
    print(f"Updated inventory: {inventory}")
