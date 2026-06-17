#!/usr/bin/env python3


from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        self.storage: list = []
        self.rank_counter: int = -1
        self.total_ingest: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        if isinstance(data, list):
            self.total_ingest += len(data)
        else:
            self.total_ingest += 1

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
        super().ingest(data)
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
        super().ingest(data)
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
        super().ingest(data)
        if isinstance(data, list):
            self.storage.extend(f"{i['log_level']}: {i['log_message']}"
                                for i in data)
        else:
            self.storage.append(f"{data['log_level']}: {data['log_message']}")


class DataStream():
    def __init__(self):
        self.proc_queue: list = []

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, DataProcessor):
            self.proc_queue.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for item in stream:
            handled = False
            for proc in self.proc_queue:
                if proc.validate(item):
                    proc.ingest(item)
                    handled = True
                    break
            if not handled:
                print(f"DataStream error - Can't process element in "
                      f"stream: {item}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.proc_queue:
            print("No processor found, no data")
            return
        for proc in self.proc_queue:
            print(f"{type(proc).__name__}: total {proc.total_ingest} "
                  "items processed, "
                  f"remaining {len(proc.storage)} on processor")


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ==\n")

    batch = ['Hello world', [3.14, -1, 2.71],
             [{'log_level': 'WARNING', 'log_message':
               'Telnet access! Use ssh instead'},
              {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
             42, ['Hi', 'five']]

    print("Initialize Data Stream...")
    ds = DataStream()
    ds.print_processors_stats()

    print("\nRegistering Numeric Processor")
    ds.register_processor(NumericProcessor())

    print(f"\nSend first batch of data on stream: {batch}")
    ds.process_stream(batch)
    ds.print_processors_stats()

    print("\nRegistering other data processors")
    ds.register_processor(TextProcessor())
    ds.register_processor(LogProcessor())

    print("Send the same batch again")
    ds.process_stream(batch)
    ds.print_processors_stats()

    print("\nConsume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for _ in range(3):
        ds.proc_queue[0].output()
    for _ in range(2):
        ds.proc_queue[1].output()
    ds.proc_queue[2].output()
    ds.print_processors_stats()
