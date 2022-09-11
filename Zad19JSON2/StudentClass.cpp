#include "StudentClass.hpp"

ns::Student::Student()
{
}

ns::Student::Student(std::string firstName, std::string lastName, unsigned int studentID)
{
    _firstName = firstName;
    _lastName = lastName;
    _studentID = studentID;
}

std::string ns::Student::getFirstName() const
{
    return _firstName;
}

std::string ns::Student::getLastName() const
{
    return _lastName;
}

unsigned int ns::Student::getGetStudentID() const
{
    return _studentID;
}

void ns::Student::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void ns::Student::setLastName(std::string lastName)
{
    _lastName = lastName;
}

void ns::Student::setStudentID(unsigned int studentID)
{
    _studentID = studentID;
}

void ns::to_json(json& j, const Student& p) //bierze sobie obiekt i pobira z niego dane i przerabia na jsona
{
    j = json{ {"FirstName: ", p.getFirstName()}, {"LastName: ", p.getLastName()}, {"StudentID: ", p.getGetStudentID()} };
}

void ns::from_json(const json& j, Student& p) //zawsze specjalizujemy sobie tą funkcję jeśli chcemy z jsona dla nazych obiektów
{
    //pierwszy sposób
    p.setFirstName(j["FirstName: "].get<std::string>()); //to get string upewnia się, że weźmiemy to jako string, ok byłoby też: p.setFirstName(j["FirstName:"]);

    //drugi sposób
    std::string lastName;
    j.at("LastName: ").get_to(lastName); //get_to nic nie zwraca! ustawi nam jedynie pole last name
    p.setLastName(lastName); //tutaj przekazujemy sobie lastName

    //"trzeci" sposób
    p.setStudentID(j["StudentID: "]);
}
