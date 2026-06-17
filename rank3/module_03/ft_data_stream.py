#!/usr/bin/env python3


from typing import Generator
import random


def gen_event() -> Generator[tuple, None, None]:
    names = [
        'alice',
        'bob',
        'charlie',
        'dylan',
    ]
    actions = [
        'run',
        'eat',
        'sleep',
        'grab',
        'move',
        'climb',
        'swim',
        'release',
        'use',
    ]
    while True:
        yield (random.choice(names), random.choice(actions))


def consume_event(new_list: list) -> Generator[tuple, None, None]:
    while new_list:
        item = random.choice(new_list)
        new_list.remove(item)
        yield item


if __name__ == "__main__":
    gen = gen_event()
    for i in range(1000):
        temp = next(gen)
        print(f"Event {i}: Player {temp[0]} did action {temp[1]}")
    new_list = list(next(gen) for i in range(10))
    print(f"Built list of 10 events: {new_list}")
    consume = consume_event(new_list)
    for event in consume_event(new_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {new_list}")
