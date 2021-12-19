#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <set>
using namespace std;
int main()
{
    string word1, word2, word3, word4;
    string a, b;
    map<string, vector<pair<string, string>>> name1;
    map<string, string> name2;
    map<string, int> animal1;
    map<string, set<int>>info1;
    ifstream filein;
    int num;
    int counter1 = 0;
    int counter2 = 0;
    filein.open("in.txt");
    while (!filein.eof())
    {
        getline(filein, word1, ',');
        getline(filein, word2, ',');
        getline(filein, word3, ',');
        getline(filein, word4);

        num = atoi(word4.c_str());
        name1[word2].push_back(make_pair(word1, word3));
        name2.insert(make_pair(word3, word2));
        animal1[word2] = 1;
        info1[word2].insert(num);

    }
    for (auto it = animal1.begin(); it != animal1.end(); it++)
    {
        counter1++;
    }
    cout << "Number of animals: " << counter1 << endl << endl;
    cout << endl << "Enter type of animal: ";
    cin >> a;
    auto at = name1.find(a);
    try
    {
        if (at == name1.end())
        {
            throw 1;
        }
        for (auto it = name1.begin(); it != name1.end(); it++)
        {
            if (it->first == a)
            {
                for (auto name1 : it->second)
                {
                    cout << "Information: " << name1.first << name1.second << endl;
                }
            }
        }
    }
    catch (...)
    {
        cout << "Not found" << endl;
    }
    cout << endl << "Enter name of animal: ";
    cin >> b;
    auto ot = name2.find(b);
    try
    {
        if (ot == name2.end())
        {
            throw 1;
        }
        for (auto it = name2.begin(); it != name2.end(); it++)
        {
            if (it->first == b)
            {
                counter2++;
            }
        }
        cout << "Number of animals: " << counter2 << endl << endl;
    }
    catch (...)
    {
        cout << "Not found" << endl << endl;
    }
    cout << endl << endl;
    for (auto it = info1.begin(); it != info1.end(); it++)
    {
        auto it21 = it->second.begin();
        auto it22 = it->second.end();
        it22--;
        cout << "The yongest " << it->first << " is in age of " << *it21 << endl;
        cout << "The oldest " << it->first << " is in age of " << *it22 << endl;
    }
    filein.close();
    return 0;
}