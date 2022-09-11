#include "json/json.hpp"
#include <iostream>
#include <string>

using json = nlohmann::json;


int main()
{
    std::string jsonStefana(R"({ 
   "company":{ 
      "employee":{ 
         "name":"Stefan",
         "payroll":{ 
            "salary":1500,
            "bonus":800
         }
      }
   }
})");

    json j = json::parse(jsonStefana);

    json employee = j["company"]["employee"];

    int salary = employee["payroll"]["salary"].get<int>();
    int bonus = employee["payroll"]["bonus"];


    std::cout << salary + bonus << std::endl;
}
