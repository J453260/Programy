#include <iostream>
#include <cstring>

#define TABLE_SIZE 16
#define KEY_SIZE 64

using namespace std;

struct Node
{
    char key[KEY_SIZE];
    int value;
    Node* next;
};

Node* table[TABLE_SIZE] = {nullptr};

unsigned long hashString(const char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % TABLE_SIZE;
}

void map_put(const char* key, int value)
{
    unsigned long index = hashString(key);
    Node* curr = table[index]; //current

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    Node* node = new Node;
    strcpy(node->key, key);
    node->value = value;
    node->next = table[index];
    table[index] = node;
}

bool map_get(const char* key, int* out)
{
    unsigned long index = hashString(key);
    Node* curr = table[index];

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            *out = curr->value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool map_remove(const char* key)
{
    unsigned long index = hashString(key);
    Node* curr = table[index]; //current
    Node* prev = nullptr; //previous

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            if (prev) prev->next = curr->next;
            else table[index] = curr->next;

            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void map_clear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* curr = table[i];
        while (curr)
        {
            Node* tmp = curr; //temporary
            curr = curr->next;
            delete tmp;
        }
        table[i] = nullptr;
    }
}

int main()
{
    map_put("kot", 5);
    map_put("pies", 7);
    map_put("ryba", 3);
    map_put("lew", 9);

    int value;
    if (map_get("pies", &value))
    {
        cout << "pies = " << value << endl;
    }

    map_remove("pies");

    if (!map_get("pies", &value))
    {
        cout << "pies zostal usuniety" << endl;
    }

    map_clear();
    return 0;
}
