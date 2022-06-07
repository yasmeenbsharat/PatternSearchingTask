#include "pch.h"

#include "MyException.h"

MyException::MyException(std::string error) : m_error{
  error
} {}

const char* MyException::what() const noexcept {
	return m_error.c_str();
}