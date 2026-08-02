import csv
import json

VIP_THRESHOLD = 1000
DISCOUNT = 0.10

data = []        # global state
last_error = ""  # global state


def run(input_path, output_path="report.json"):
    global data, last_error

    try:
        f = open(input_path, "r", encoding="utf-8")
        reader = csv.reader(f)
        header = next(reader)  # may crash
    except:
        return {}

    for row in reader:
        try:
            tid = row[0].strip()
            user = row[1].strip().lower()
            amount = float(row[2])
            category = row[3].strip()

            data.append([tid, user, amount, category])
        except Exception as e:
            last_error = str(e)
            pass

    f.close()

    users = {}
    categories = {}
    total = 0.0

    for rec in data:
        user = rec[1]
        amount = rec[2]
        category = rec[3]

        total += amount

        if user not in users:
            users[user] = {"sum": 0.0, "count": 0, "vip": False, "after_discount": 0.0}

        users[user]["sum"] += amount
        users[user]["count"] += 1

        if users[user]["sum"] > VIP_THRESHOLD:
            users[user]["vip"] = True

        if category not in categories:
            categories[category] = 0.0
        categories[category] += amount

    for user in users:
        if users[user]["vip"]:
            users[user]["after_discount"] = users[user]["sum"] * (1.0 - DISCOUNT)
        else:
            users[user]["after_discount"] = users[user]["sum"]

    report = {
        "total": total,
        "users": users,
        "categories": categories,
        "error": last_error
    }

    try:
        g = open(output_path, "w", encoding="utf-8")
        g.write(json.dumps(report))
        g.close()
    except:
        pass

    return report


if __name__ == "__main__":
    run("transactions.csv")



