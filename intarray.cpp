#include "intarray.h"
#include <exception>
#include <iostream>

IntArray::IntArray(const std::string name, int length) : _name(name), _length(length) { // create container
	try {
		if (length < 0)
			throw "bad_length";

		this->_data = new int[length] {};
		std::cout << "IntArray of size " << this->_length << " created" << std::endl;
	}
	catch (const char* exception) {
		std::cout << "IntArray NOT created - Exception: " << exception << std::endl;
	}
}

void IntArray::erase()
{
	delete[] this->_data;
	this->_data = nullptr;
	this->_length = 0;
}

void IntArray::getIntbyIndex(int index) { // get element
	try {
		if (index >= this->_length)
			throw "bad_range";

		std::cout << "IntArray " << this->_name << "[" << index << "] = " << this->_data[index] << std::endl;
	}
	catch (const char* exception) {
		std::cout << "getIntbyIndex FAILED - Exception: " << exception << std::endl;
	}
}


void IntArray::copy(IntArray dest) { //copy container to container
	try {
		if (this->_length > dest._length)
			throw "bad_range";

		for (int i = 0; i < this->_length; i++) {
			dest._data[i] = this->_data[i];
		}
		std::cout << "IntArray " << this->_name << " copied to IntArray " << dest._name << std::endl;
	}
	catch (const char* exception) {
		std::cout << "Copy FAILED - Exception: " << exception << std::endl;
	}
}	

void IntArray::resize(int newLength) {  //change size
	if (newLength == this->_length)
		return;

	int* data = new int[newLength];

	if (this->_length > 0)
	{
		int elementsToCopy{ (newLength > this->_length) ? this->_length : newLength };

		for (int i = 0; i < elementsToCopy; ++i)
			data[i] = this->_data[i];
	}

	delete[] this->_data;
	this->_data = data;
	this->_length = newLength;
	std::cout << "IntArray " << this->_name << "was resized to " << this->_length << std::endl;
}

void IntArray::setIntbyIndex(int index, int value) {  // insert 
	try {
		if (index >= this->_length)
			throw "bad_range";
		
		this->_data[index] = value;
		std::cout << "IntArray " << this->_name << "[" << index << "] = " << this->_data[index] << std::endl;
	}
	catch (const char* exception) {
		std::cout << "setIntbyIndex FAILED - Exception: " << exception << std::endl;
	}
}

void IntArray::delIntbyIndex(int index) {  //delete
	try {
		if (index >= this->_length)
			throw "bad_range";

		std::cout << "IntArray " << this->_name << "[" << index << "] = " << this->_data[index] << " was deleted" << std::endl;
		this->_data[index] = -1;
	}
	catch (const char* exception) {
		std::cout << "delIntbyIndex FAILED - Exception: " << exception << std::endl;
	}
}
