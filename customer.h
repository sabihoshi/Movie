#pragma once

#include "json.hpp"
#include "movie.h"
#include <stack>
#include <string>

class Customer {
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Customer, _customerId, _name, _address);

    int _customerId;
    std::string _name;
    std::string _address;
    std::stack<Movie> _rentedMovies;
public:
    Customer(int customerId, std::string name, std::string address);

    int getCustomerId() const;

    std::string getName();

    std::string getAddress();

    void setName(std::string name);

    void setAddress(std::string address);

    void printCustomerDetails();

    void printRentedMovies();

    bool operator==(const Customer &compare) const;

};
