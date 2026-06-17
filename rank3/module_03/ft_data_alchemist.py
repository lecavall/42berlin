#! /usr/bin/env python3

import random


if __name__ == "__main__":
    names = [
        'Alice',
        'bob',
        'Charlie',
        'dylan',
        'Emma',
        'Gregory',
        'john',
        'kevin',
        'Liam',
    ]
    names_cap: list = [x.capitalize() for x in names]
    names_only_cap: list = [x for x in names if x[0].isupper()]
    score_dict: dict = {x: random.randint(0, 1000) for x in names_cap}
    avg: float = round(sum(score_dict.values()) / len(score_dict), 2)
    high_sc: dict = {x: score_dict for x, s in score_dict.items() if s > avg}
    print("=== Game Data Alchemist ===\n")
    print(f"Initial list of players: {names}")
    print(f"New list with all names capitalized: {names_cap}")
    print(f"New list of capitalized names only: {names_only_cap}")
    print(f"Score dict: {score_dict}")
    print(f"Score average is {avg}")
    print(f"High scores: {high_sc}")
