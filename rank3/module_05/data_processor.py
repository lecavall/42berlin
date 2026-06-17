#!/usr/bin/env python3


from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        self.storage: list = []
        self.rank_counter: int = -1

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.storage:
            raise IndexError("No data to output")
        self.rank_counter += 1
        return (self.rank_counter, self.storage.pop(0))


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(i, (int, float)) for i in data)
        else:
            return False

    def ingest(self, data: int | float | list) -> None:
        if not self.validate(data):
            raise ValueError("Got exception: Improper numeric data")
        if isinstance(data, list):
            self.storage.extend(str(i) for i in data)
        else:
            self.storage.append(str(data))


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(i, str) for i in data)
        else:
            return False

    def ingest(self, data: str | list) -> None:
        if not self.validate(data):
            raise ValueError
        if isinstance(data, list):
            self.storage.extend(i for i in data)
        else:
            self.storage.append(data)


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return True
        if isinstance(data, list):
            return all(isinstance(i, dict) for i in data)
        else:
            return False

    def ingest(self, data: dict | list) -> None:
        if not self.validate(data):
            raise ValueError
        if isinstance(data, list):
            self.storage.extend(f"{i['log_level']}: {i['log_message']}"
                                for i in data)
        else:
            self.storage.append(f"{data['log_level']}: {data['log_message']}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")

    print("\nTesting Numeric Processor...")
    np = NumericProcessor()
    print(f"Trying to validate input '42': {np.validate(42)}")
    print(f"Trying to validate input 'Hello': {np.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        np.ingest('foo')
    except ValueError as e:
        print(f"{e}")
    np.ingest([1, 2, 3, 4, 5])
    print("Processing data: [1, 2, 3, 4, 5]")
    print("Extracting 3 values...")
    for i in range(3):
        rank, val = np.output()
        print(f"Numeric value {rank}: {val}")

    print("\nTesting Text Processor...")
    tp = TextProcessor()
    print(f"Trying to validate input '42': {tp.validate(42)}")
    tp.ingest(['Hello', 'Nexus', 'World'])
    print("Processing data: ['Hello', 'Nexus', 'World']")
    print("Extracting 1 value...")
    rank, val = tp.output()
    print(f"Text value {rank}: {val}")

    print("\nTesting Log Processor...")
    lp = LogProcessor()
    print(f"Trying to validate input 'Hello': {lp.validate('Hello')}")
    logs = [{'log_level': 'NOTICE', 'log_message': 'Connection to server'},
            {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]
    lp.ingest(logs)
    print(f"Processing data: {logs}")
    print("Extracting 2 values...")
    for i in range(2):
        rank, val = lp.output()
        print(f"Log entry {rank}: {val}")
