#include <exception>

#include <iostream>

#include <string>


/**
* @brief:In  this class, we can have the exception return a description of the problem that occurred.
*/

class MyException : public std::exception {

      public: MyException(std::string error);

	  const char* what() const noexcept override;

private: std::string m_error;

};