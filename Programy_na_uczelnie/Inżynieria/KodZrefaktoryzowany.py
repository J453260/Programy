import csv
import json
from dataclasses import dataclass
from typing import List, Dict

VIP_THRESHOLD = 1000
DISCOUNT = 0.10


@dataclass
class Transaction:
    tid: str
    user: str
    amount: float
    category: str


def load_transactions(path: str) -> tuple[list[Transaction], str]:
    data = []
    last_error = ""

    try:
        with open(path, newline="", encoding="utf-8") as f:
            reader = csv.reader(f)
            next(reader)  # header

            for row in reader:
                try:
                    data.append(Transaction(
                        tid=row[0].strip(),
                        user=row[1].strip().lower(),
                        amount=float(row[2]),
                        category=row[3].strip()
                    ))
                except Exception as e:
                    last_error = str(e)
    except OSError as e:
        return [], str(e)

    return data, last_error


def analyze_transactions(data: List[Transaction]):
    users: Dict[str, dict] = {}
    categories: Dict[str, float] = {}
    total = 0.0

    for t in data:
        total += t.amount

        user = users.setdefault(t.user, {
            "sum": 0.0,
            "count": 0,
            "vip": False,
            "after_discount": 0.0
        })

        user["sum"] += t.amount
        user["count"] += 1
        user["vip"] = user["sum"] > VIP_THRESHOLD

        categories[t.category] = categories.get(t.category, 0.0) + t.amount

    for u in users.values():
        u["after_discount"] = u["sum"] * (1 - DISCOUNT if u["vip"] else 1)

    return total, users, categories


def save_report(report: dict, path: str) -> None:
    with open(path, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)


def run(input_path: str, output_path: str = "report.json") -> dict:
    data, error = load_transactions(input_path)
    total, users, categories = analyze_transactions(data)

    report = {
        "total": total,
        "users": users,
        "categories": categories,
        "error": error
    }

    save_report(report, output_path)
    return report


if __name__ == "__main__":
    run("transactions.csv")