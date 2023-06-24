#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <map>

using namespace std;
template <typename T1, typename T2>
auto Sum(T1 a, T2 b)
{
    return a + b;
}


class Funct
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

class User
{
    string name;
    int age;
public:
    User(string name, int age) 
        : name{ name }, age{ age } {};
};

int main()
{
    srand(time(nullptr));

    vector<int> vint(5);
    //cout << typeid(vint.begin()).name() << "\n";

    for (auto it = vint.begin(); it != vint.end(); it++)
        *it = rand() % 100;

    for (auto item : vint)
        cout << item << " ";
    cout << "\n";

    vint.push_back(45);
    vint.reserve(10);

    cout << vint.size() << "\n";
    cout << vint.capacity() << "\n";

    //vint.shrink_to_fit();
    //vint.clear();
    cout << vint.size() << "\n";
    cout << vint.capacity() << "\n";

    vint.insert(vint.begin() + 3, 100);
    for (auto item : vint)
        cout << item << " ";
    cout << "\n";

    list<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    vint.insert(vint.begin() + 4, ++v2.begin(), --v2.end());
    vint.resize(30, 5);

    for (auto item : vint)
        cout << item << " ";
    cout << "\n";

    //erase(vint, 5);
    erase_if(vint, [](auto item) { return item % 2 == 0; });

    for (auto item : vint)
        cout << item << " ";
    cout << "\n";


    vector<User> users;
    users.push_back(User("Bob", 25));
    users.push_back(User("Joe", 37));
    users.push_back(User("Tom", 41));
    users.insert(users.begin() + 1, User("Leo", 26));

    users.emplace_back("Jim", 33);
    users.emplace(users.begin() + 1, "Sam", 28);


    ////////////
    /*
    int c = 10;
    auto lambda = [&](auto a, auto b) 
    { 
        c = 20;
        return a + b + c; 
    };

    std::cout << lambda(10, 20) << "\n";
    std::cout << typeid(lambda).name() << "\n";

    Funct f;
    std::cout << f(10, 20) << "\n";
    */

    map<string, string> dict;
    dict.insert(pair("name", "Bob"));
    dict.insert(pair("age", "32"));
    dict.insert(pair("name", "Leo"));
    dict["name"] = "Leo";

    for (auto item : dict)
        cout << item.first << " -> " << item.second << "\n";
}
