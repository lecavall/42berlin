import random


ACHIEVEMENTS = [
        'Crafting Genius',
        'World Savior',
        'Master Explorer',
        'Collector Supreme',
        'Untouchable',
        'Boss Slayer',
        'Strategist',
        'Unstoppable',
        'Speed Runner',
        'Survivor',
        'Treasure Hunter',
        'First Steps',
        'Sharp Mind',
        'Hidden Path Finder']


class Player:
    def __init__(self, name: str, achievements: set):
        self.name = name
        self.ach = achievements

    def show(self):
        print(f"Player {self.name}: {self.ach}")

    def distinction(self, *sets) -> None:
        others = set().union(*sets)
        dist_set = self.ach - others
        print(f"Only {self.name} has: {dist_set}")

    def missing(self) -> None:
        miss_set = set(ACHIEVEMENTS) - self.ach
        print(f"{self.name} is missing: {miss_set}")


def gen_player_achievements() -> set:
    amount: int = random.randint(1, len(ACHIEVEMENTS))
    new_set: set = set(random.sample(ACHIEVEMENTS, amount))
    return (new_set)


def achievement_system() -> None:
    print("=== Achievement Tracker System ===\n")
    alice = Player("Alice", gen_player_achievements())
    alice.show()
    bob = Player("Bob", gen_player_achievements())
    bob.show()
    charlie = Player("Charlie", gen_player_achievements())
    charlie.show()
    dylan = Player("Dylan", gen_player_achievements())
    dylan.show()
    print("\nAll distinct achievements:"
         f" {alice.ach | bob.ach | charlie.ach | dylan.ach}")
    print("\nCommon Achievements: "
          f"{alice.ach & bob.ach & charlie.ach & dylan.ach}\n")
    alice.distinction(bob.ach, charlie.ach, dylan.ach)
    bob.distinction(alice.ach, charlie.ach, dylan.ach)
    charlie.distinction(bob.ach, alice.ach, dylan.ach)
    dylan.distinction(bob.ach, charlie.ach, alice.ach)
    print("")
    alice.missing()
    bob.missing()
    charlie.missing()
    dylan.missing()


if __name__ == "__main__":
    achievement_system()
