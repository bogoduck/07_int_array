#pragma once
#include <string>



class IntArray {
private:
	std::string _name;
	int _length{};
	int* _data{};
public:
	IntArray() = default;
	IntArray(const std::string name, int length);
	void erase();
	void copy(IntArray dest);
	void getIntbyIndex(int index);
	void resize(int newLength);
	void setIntbyIndex(int index, int value);
	void delIntbyIndex(int index);

};