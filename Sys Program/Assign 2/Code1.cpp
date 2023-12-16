#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

unordered_map<char, vector<string>> grammar = {
    {'E', {"TG"}},
    {'G', {"+TG", "e"}},
    {'T', {"FS"}},
    {'S', {"*FS", "e"}},
    {'F', {"a", "(E)"}}};

unordered_map<char, unordered_set<char>> first_sets;
unordered_map<char, unordered_set<char>> follow_sets;
char start_symbol = 'E';

unordered_set<char> compute_first(char variable);

unordered_set<char> find_first(string production);

unordered_set<char> compute_follow(char variable);

unordered_set<char> find_follow(char lhs, string production);

int main()
{
    // Computing FIRST sets for all variables
    for (auto &entry : grammar)
    {
        compute_first(entry.first);
    }

    // Computing FOLLOW sets for all variables
    for (auto &entry : grammar)
    {
        compute_follow(entry.first);
    }

    // Printing the computed FIRST and FOLLOW sets
    cout << "\nFIRST sets:\n";
    for (auto &entry : first_sets)
    {
        cout << "FIRST(" << entry.first << ") = { ";
        for (char terminal : entry.second)
        {
            cout << terminal << " ";
        }
        cout << "}\n";
    }

    cout << "\nFOLLOW sets:\n";
    for (auto &entry : follow_sets)
    {
        cout << "FOLLOW(" << entry.first << ") = { ";
        for (char terminal : entry.second)
        {
            cout << terminal << " ";
        }
        cout << "}\n";
    }

    return 0;
}

unordered_set<char> compute_first(char variable)
{
    if (first_sets.find(variable) != first_sets.end())
    {
        return first_sets[variable];
    }

    unordered_set<char> first_set;

    for (const string &production : grammar[variable])
    {
        first_set.insert(find_first(production).begin(), find_first(production).end());
    }

    first_sets[variable] = first_set;
    return first_set;
}

unordered_set<char> find_first(string production)
{
    unordered_set<char> first;

    char symbol = production[0];

    if (isupper(symbol))
    { // Non-terminal
        first = compute_first(symbol);
    }
    else
    { // Terminal
        first.insert(symbol);
    }

    return first;
}
unordered_set<char> compute_follow(char variable)
{
    if (follow_sets.find(variable) != follow_sets.end())
    {
        return follow_sets[variable];
    }

    unordered_set<char> follow_set;

    if (variable == start_symbol)
    {
        follow_set.insert('$');
    }

    for (auto &entry : grammar)
    {
        for (const string &production : entry.second)
        {
            size_t pos = production.find(variable);

            while (pos != string::npos)
            {
                if (pos == production.size() - 1)
                { // Variable is at the end of production
                    if (variable != entry.first)
                    {
                        follow_set.insert(compute_follow(entry.first).begin(), compute_follow(entry.first).end());
                    }
                }
                else
                { // Variable is followed by another symbol
                    string remaining = production.substr(pos + 1);
                    unordered_set<char> remaining_first = find_first(remaining);

                    // Add non-epsilon terminals to follow set
                    for (char terminal : remaining_first)
                    {
                        if (terminal != 'e')
                        {
                            follow_set.insert(terminal);
                        }
                    }

                    if (remaining_first.find('e') != remaining_first.end())
                    {
                        // Include FOLLOW of the non-terminal after the variable
                        follow_set.insert(compute_follow(entry.first).begin(), compute_follow(entry.first).end());
                    }
                }

                pos = production.find(variable, pos + 1);
            }
        }
    }

    follow_sets[variable] = follow_set;
    return follow_set;
}

unordered_set<char> find_follow(char lhs, string production)
{
    unordered_set<char> follow;

    size_t pos = production.find(lhs);
    while (pos != string::npos)
    {
        if (pos == production.size() - 1)
        { // lhs is at the end of production
            if (lhs != production[pos])
            {
                follow = compute_follow(lhs);
            }
        }
        else
        { // lhs is followed by another symbol
            string remaining = production.substr(pos + 1);
            unordered_set<char> remaining_first = find_first(remaining);
            follow.insert(remaining_first.begin(), remaining_first.end());

            if (remaining_first.find('e') == remaining_first.end())
            {
                break;
            }
        }

        pos = production.find(lhs, pos + 1);
    }

    return follow;
}
