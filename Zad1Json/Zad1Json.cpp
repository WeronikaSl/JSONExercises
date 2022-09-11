#include "json/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;


int main()
{
    json j;
    j["imie"] = "Weronika";
    j["nazwisko"] = "Slowinska";
    j["wiek"] = 23;
    j["praca"]["biuro"] = "tlumaczka";
    j["praca"]["szkola"] = "nauczycielka";
    j["lista"] = { 1,2,3 };
    
    std::string a = j["praca"]["biuro"];
    std::cout << a;

    std::ofstream o("ja.json");
    o << std::setw(4) << j << std::endl; //to setw - ile whitespaces żeby to ładnie poformatować, bez tego po prostu w jednej linijce
}
