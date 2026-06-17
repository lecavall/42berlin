"""Demonstrate from-import for the root elements module."""

from elements import create_water


print("=== Alembic 1 ===")
print("Using: 'from ... import ...' structure to access elements.py")
print(f"Testing create_water: {create_water()}")
