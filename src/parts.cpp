#include <iostream>
using namespace std;
#include "parts.h"

void Part::describe()
{
    cout << "Part: " << this->name << "\nSubparts:\n";
    if (sub_parts.empty())
        cout << "\tNo subparts.\n";
    else
        for (auto it = sub_parts.begin(); it != sub_parts.end(); ++it)
            cout << "\t" << it->first->name << " " << it->second << "\n";
}

int Part::count_howmany(Part const *p)
{
    if (this == p)
        return 1;

    int i = 0;
    for (auto it = sub_parts.begin(); it != sub_parts.end(); ++it)
        i += it->first->count_howmany(p) * it->second;

    return i;
}


void add_part(string const &x, int q, string const &y)
{
    Part* parent = partContainer.lookup(x);
    Part* child = partContainer.lookup(y);
    parent->sub_parts[child] = q;
}

NameContainer partContainer;

Part* NameContainer::lookup(const string &name)
{
    auto it = name_map.find(name);
    Part* outp;

    if (it == name_map.end())
    {
        outp = new Part(name);
        name_map[name] = outp;
    }
    else
        outp = it->second;

    return outp;
}

NameContainer::~NameContainer(void) {

}

NameContainer::NameContainer(void) {

}

