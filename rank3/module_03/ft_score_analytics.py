import sys


def score_display(array: list) -> None:
    print("=== Player Score Analytics ===")
    status: int = 1
    for arg in array[1:]:
        try:
            int(arg)
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
            status = 0
    if (status == 0):
        print("No scores provided. Usage: "
              "python3 ft_score_analytics.py <score1> <score2> ...")
    else:
        scores = [int(x) for x in array[1:]]
        print("Scores processed: [" + ", ".join(str(x) for x in scores) + "]")
        print(f"Total players: {len(scores)}")
        print(f"Total Score: {sum(scores)}")
        print(f"Average Score: {sum(scores) / len(scores)}")
        print(f"High Score: {max(scores)}")
        print(f"Low Score: {min(scores)}")
        print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":
    score_display(sys.argv)
