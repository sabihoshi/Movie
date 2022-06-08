#include "customer.h"

Customer::Customer(int customerId, std::string name, std::string address):
         _customerId(customerId), _name(std::move(name)), _address(std::move(address))
{
}

void Customer::printRentedMovies()
{
  std::stack<Movie> temp (_rentedMovies);
  while (!temp.empty())
  {
    temp.top().printMovieDetails(true);
    temp.pop();
  }
}

int Customer::getCustomerId() const
{
  return _customerId;
}

std::string Customer::getName()
{
  return _name;
}
std::string Customer::getAddress()
{
  return _address;
}

void Customer::setName(std::string name)
{
  _name = std::move(name);
}

void Customer::setAddress(std::string address)
{
  _address = std::move(address);
}

void Customer::printCustomerDetails()
{
  std::cout << "Customer ID: " << _customerId << std::endl;
  std::cout << "Name: " << _name << std::endl;
  std::cout << "Address: " << _address << std::endl;
}

bool Customer::operator==(const Customer &compare) const
{
  return _customerId == compare._customerId;;
}
