#pragma once
#include "json/json.hpp"

namespace ns {
    using json = nlohmann::json;

    class Student
    {
    private:
        std::string _firstName = {};
        std::string _lastName = {};
        unsigned int _studentID = 0;
    public:
        Student();
        Student(std::string firstName, std::string lastName, unsigned int studentID);
        std::string getFirstName() const;
        std::string getLastName() const;
        unsigned int getGetStudentID() const;
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setStudentID(unsigned int studentID);
    };

    void to_json(json& j, const Student& p);

    void from_json(const json& j, Student& p);

}