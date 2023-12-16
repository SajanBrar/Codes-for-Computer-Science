#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

unordered_map<char, unordered_map<char, string>> parsing_table = {
    {'E', {{'a', "TG"}, {'(', "TG"}}},
    {'G', {{')', "e"}, {'$', "e"}, {'+', "+TG"}}},
    {'T', {{'(', "FS"}, {'a', "FS"}}},
    {'S', {{')', "e"}, {'$', "e"}, {'+', "e"}, {'*', "*FS"}}},
    {'F', {{'(', "(E)"}, {'a', "a"}}}};

char start_symbol = 'E';

bool parse_string(const string &input)
{
    stack<char> symbols;
    symbols.push('$');
    symbols.push(start_symbol);

    size_t input_index = 0;
    char current_symbol = symbols.top();

    while (current_symbol != '$')
    {
        if (!isupper(current_symbol))
        { // Terminal symbol
            if (current_symbol == input[input_index])
            {
                symbols.pop();
                input_index++;
            }
            else
            {
                cout << "Error: Mismatched terminal symbol: " << current_symbol << " vs. " << input[input_index] << endl;
                return false;
            }
        }
        else
        { // Non-terminal symbol
            char input_token = input[input_index];
            if (parsing_table[current_symbol].find(input_token) != parsing_table[current_symbol].end())
            {
                string production = parsing_table[current_symbol][input_token];
                symbols.pop();
                if (production != "e")
                {
                    for (int i = production.length() - 1; i >= 0; --i)
                    {
                        symbols.push(production[i]);
                    }
                }
            }
            else
            {
                cout << "Error: No production found in the parsing table for Non-Terminal " << current_symbol << " and input token " << input_token << endl;
                return false;
            }
        }
        current_symbol = symbols.top();
    }

    if (input_index == input.length())
    {
        cout << "String successfully parsed!" << endl;
        return true;
    }
    else
    {
        cout << "Error: Parsing incomplete, input not fully consumed." << endl;
        return false;
    }
}

int main()
{
    string input;
    cout << "Enter an input string: ";
    cin >> input;

    if (parse_string(input))
    {
        cout << "Parsing successful!" << endl;
    }
    else
    {
        cout << "Parsing failed." << endl;
    }

    return 0;
}