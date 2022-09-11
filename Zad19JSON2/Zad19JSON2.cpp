#include "json/json.hpp"
#include "StudentClass.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>

using json = nlohmann::json;

int main()
{
    std::vector<ns::Student> vec = {};
    vec.push_back(ns::Student("Sean", "Brown", 12345));
    vec.push_back(ns::Student("Drake", "Williams", 67894));
    vec.push_back(ns::Student("Tom", "Miller", 45632));
    vec.push_back(ns::Student("Peter", "Jonson", 47682));

    json j;

    j["Students"] = vec; //json automatycznie przerabia każdy kontener na kontener jsonów, ale musi być zaimplementowana metoda to_json zeby wiedzialo jak

    std::ofstream o("students.json");
    o << std::setw(4) << j << std::endl;

    std::ifstream ifs("students.json");
    json jf = json::parse(ifs);

    std::list<ns::Student> l = {};

    for (auto& elem : jf["Students"]) //wszystkie elemety z jf dla klucza students, to jest przed : jest kluczem, a po : jest wartością dla tego klucza (klucze dla kluczy)
    {
        //ns::Student student; //nie dziala bez konstr domyuslneg bo metoda from_jsn potrzebuje konstruktora bezparam żeby sobie go utworzyć i setterami
        //student = elem.get<ns::Student>();
        //l.push_back(student);
        l.push_back(elem.get<ns::Student>()); //to samo co wyżej tylko tamto bardziej rozbite

        //można też pobrać jedynie określony element
        //elem["FirstName: "] //tutaj dostajemy tylko first names
    }

    std::for_each(l.cbegin(), l.cend(), [&](ns::Student s) {std::cout << s.getFirstName() << " " << s.getLastName() << " " << s.getGetStudentID() << std::endl; });


}
