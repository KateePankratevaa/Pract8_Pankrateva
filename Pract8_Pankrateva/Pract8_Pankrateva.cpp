#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Higher {
    int year;
    char university[50];
};
struct Average {
    int vozr;
};

struct Employee {
   
    char name[100];
   
    union Info {
        Average averageInfo;
        Higher higherInfo;
    };

    int vozr;
    char education;
    Info info;
};

bool compareByAge(const Employee& a, const Employee& b) {
    return a.vozr < b.vozr;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Employee people[4];
    people[0] = { "Иванова", 30, 'с' };
    people[0].info.averageInfo = { 30 };
    people[1] = { "Петров", 35, 'с' };
    people[1].info.averageInfo = { 35 };
    people[2] = { "Сидорова", 2012, 'в' };
    people[2].info.higherInfo = { 2012, "УРГАхУ" };
    people[3] = { "Кузнецов", 2018, 'в' };
    people[3].info.higherInfo = { 2018, "УРФУ" };

    vector<Employee> notHigher;
    for (const auto& person : people) {
        if (person.education == 'с')
        {
            notHigher.push_back(person);
        }
    }

    sort(notHigher.begin(), notHigher.end(), compareByAge);

    for (const auto& person : notHigher)
    {
        cout << "Фамилия: " << person.name << ", Возраст: " << person.vozr << endl;
    }

    return 0;
}
