"""Exercise 0: The Alembic.

This file demonstrates the six import styles requested by the first
exercise of the subject.  It intentionally keeps ``create_earth`` hidden
from the public ``alchemy`` package interface while exposing
``create_air``.
"""

import alchemy
import alchemy.elements
import elements
from alchemy import create_air as package_create_air
from alchemy.elements import create_air
from elements import create_water


def ft_alembic_0() -> None:
    """Use ``import ...`` to access ``elements.py`` and create fire."""
    print("=== Alembic 0 ===")
    print("Using: 'import ...' structure to access elements.py")
    print(f"Testing create_fire: {elements.create_fire()}")


def ft_alembic_1() -> None:
    """Use ``from ... import ...`` to access root elements.

    Create water through the imported function.
    """
    print("=== Alembic 1 ===")
    print("Using: 'from ... import ...' structure to access elements.py")
    print(f"Testing create_water: {create_water()}")


def ft_alembic_2() -> None:
    """Use ``import ...`` to access ``alchemy/elements.py``.

    Create earth through the imported module.
    """
    print("=== Alembic 2 ===")
    print("Accessing alchemy/elements.py using 'import ...' structure")
    print(f"Testing create_earth: {alchemy.elements.create_earth()}")


def ft_alembic_3() -> None:
    """Use ``from ... import ...`` to access ``alchemy/elements.py``."""
    print("=== Alembic 3 ===")
    print(
        "Accessing alchemy/elements.py using "
        "'from ... import ...' structure"
    )
    print(f"Testing create_air: {create_air()}")


def ft_alembic_4() -> None:
    """Use ``import alchemy`` to access the package public interface."""
    print("=== Alembic 4 ===")
    print("Accessing the alchemy module using 'import alchemy'")
    print(f"Testing create_air: {alchemy.create_air()}")
    print("Now show that not all functions can be reached")
    print("This will raise an exception!")
    print("Testing the hidden create_earth: ", end="")
    print(f"{alchemy.create_earth()}")  # type: ignore[attr-defined]


def ft_alembic_5() -> None:
    """Use ``from alchemy import ...`` for the public interface."""
    print("=== Alembic 5 ===")
    print("Accessing the alchemy module using 'from alchemy import ...'")
    print(f"Testing create_air: {package_create_air()}")


def main() -> None:
    """Run all successful demonstrations, then the intentional failure."""
    ft_alembic_0()
    print()
    ft_alembic_1()
    print()
    ft_alembic_2()
    print()
    ft_alembic_3()
    print()
    ft_alembic_5()
    print()
    ft_alembic_4()


if __name__ == "__main__":
    main()
