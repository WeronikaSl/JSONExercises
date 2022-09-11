#include "json/json.hpp"
#include <iostream>

using json = nlohmann::json;

int main()
{
    std::string toJson = R"({ 
   "company":{
      "employee":{
         "name":"Stefan",
         "payroll" : {
            "salary":1500,
            "bonus" : 800
         }
      }
   }
    })";

    json j = json::parse(toJson);

    json employee = j["company"]["employee"];

    int salary = 0;
    employee["payroll"]["salary"].get_to<int>(salary);
    int bonus = 0;
    employee["payroll"]["bonus"].get_to<int>(bonus);
    std::cout << salary + bonus << std::endl;
    

}

