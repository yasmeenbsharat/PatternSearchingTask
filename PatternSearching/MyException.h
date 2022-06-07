#include <exception>

#include <iostream>

#include <string>

class MyException : public std::exception {

      public: MyException(std::string error);

	  const char* what() const noexcept override;

private: std::string m_error;

};