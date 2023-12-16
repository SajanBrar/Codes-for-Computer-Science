#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

unordered_map<char, vector<string>> grammar = {
    {'E', {"TG"}},
    {'G', {"+TG", "e"}},
    {'T', {"FS"}},
    {'S', {"*FS", "e"}},
    {'F', {"a", "(E)"}}};

unordered_map<char, unordered_set<char>> first_sets = {
    {'E', {'(', 'a'}},
    {'G', {'e', '+'}},
    {'T', {'a', '('}},
    {'S', {'e', '*'}},
    {'F', {'(', 'a'}}};

unordered_map<char, unordered_set<char>> follow_sets = {
    {'E', {')', '$'}},
    {'G', {')', '$'}},
    {'T', {')', '$', '+'}},
    {'S', {')', '$', '+'}},
    {'F', {')', '$', '+', '*'}}};

unordered_map<char, unordered_map<char, string>> parsing_table;
unordered_set<char> compute_first(string production);

void create_parsing_table()
{
    for (auto &entry : grammar)
    {
        char non_terminal = entry.first;

        for (const string &production : entry.second)
        {
            unordered_set<char> first = compute_first(production);

            for (char terminal : first)
            {
                if (terminal != 'e')
                {
                    parsing_table[non_terminal][terminal] = production;
                }
            }

            if (first.find('e') != first.end())
            {
                unordered_set<char> follow = follow_sets[non_terminal];
                for (char terminal : follow)
                {
                    parsing_table[non_terminal][terminal] = "e";
                }
            }
        }
    }
}

int main()
{
    create_parsing_table();

    // Printing the LL(1) predictive parsing table
    cout << "LL(1) Predictive Parsing Table:\n";
    for (auto &entry : parsing_table)
    {
        cout << "Non-Terminal " << entry.first << ":\n";
        for (auto &inner_entry : entry.second)
        {
            cout << "    " << inner_entry.first << " : " << inner_entry.second << "\n";
        }
    }

    return 0;
}

unordered_set<char> compute_first(string production)
{
    unordered_set<char> first;

    char symbol = production[0];

    if (isupper(symbol))
    { // Non-terminal
        first = first_sets[symbol];
    }
    else
    { // Terminal
        first.insert(symbol);
    }

    return first;
}
