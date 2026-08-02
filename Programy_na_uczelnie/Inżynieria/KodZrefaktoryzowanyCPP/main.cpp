#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

const double VIP_THRESHOLD = 1000.0;
const double DISCOUNT = 0.10;

struct Transaction
{
    string tid;
    string user;
    double amount;
    string category;
};

struct UserInfo
{
    double sum = 0.0;
    int count = 0;
    bool vip = false;
    double after_discount = 0.0;
};

vector<string> split_csv(const string& line)
{
    vector<string> result;
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ',')) result.push_back(cell);
    return result;
}

vector<Transaction> load_transactions(const string& path, string& error)
{
    vector<Transaction> data;
    ifstream f(path);
    if (!f.is_open())
    {
        error = "Cannot open file";
        return {};
    }

    string line;
    getline(f, line); // header

    while (getline(f, line))
    {
        try
        {
            auto row = split_csv(line);
            if (row.size() < 4) throw runtime_error("Invalid row");

            data.push_back(
            {
                row[0],
                row[1],
                stod(row[2]),
                row[3]
            });
        }
        catch (exception& e)
        {
            error = e.what();
        }
    }
    return data;
}

void analyze_transactions(
    const vector<Transaction>& data,
    double& total,
    map<string, UserInfo>& users,
    map<string, double>& categories)
{
    total = 0;

    for (const auto& t : data)
    {
        total += t.amount;

        auto& u = users[t.user];
        u.sum += t.amount;
        u.count++;
        u.vip = u.sum > VIP_THRESHOLD;

        categories[t.category] += t.amount;
    }

    for (auto& [_, u] : users)
        u.after_discount = u.vip ? u.sum * (1 - DISCOUNT) : u.sum;
}

void save_report(
    const string& path,
    double total,
    const map<string, UserInfo>& users,
    const map<string, double>& categories,
    const string& error)
{
    ofstream g(path);
    g << fixed << setprecision(2);

    g << "{\n  \"total\": " << total << ",\n  \"users\": {\n";

    bool first = true;
    for (const auto& [name, u] : users)
    {
        if (!first) g << ",\n";
        first = false;
        g << "    \"" << name << "\": {"
          << "\"sum\": " << u.sum
          << ", \"count\": " << u.count
          << ", \"vip\": " << (u.vip ? "true" : "false")
          << ", \"after_discount\": " << u.after_discount << "}";
    }

    g << "\n  },\n  \"categories\": {\n";

    first = true;
    for (const auto& [cat, val] : categories)
    {
        if (!first) g << ",\n";
        first = false;
        g << "    \"" << cat << "\": " << val;
    }

    g << "\n  },\n  \"error\": \"" << error << "\"\n}";
}

void run(const string& input, const string& output="report.json")
{
    string error;
    auto data = load_transactions(input, error);

    double total;
    map<string, UserInfo> users;
    map<string, double> categories;

    analyze_transactions(data, total, users, categories);
    save_report(output, total, users, categories, error);
}

int main()
{
    run("transactions.csv");
    return 0;
}
