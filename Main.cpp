#include <iostream>
#include <string>
#include <algorithm>
class Car {
public:
	explicit Car(size_t num = 0) : _size(num), _data(new int[_size]), _acceleration("\nVwoom...vwoommm...vwooommm...\n")
	{log("constructor");}
	
	~Car() {
		log("Deconstructor");
		if (_data) {
			delete[] _data;
			_data = nullptr;
		}
	}
	Car(const Car& other) : _size(other._size), _data(new int[_size]), _acceleration("\nVwoom...vwoommm...vwooommm...\n")
	{
		log("copy constructor");
		_acceleration = other._acceleration;
		for (size_t i = 0; i < _size; i++) {
			_data = other._data;
		}
	}
	
	Car& operator=(const Car& other){
		log("copy assigment operator");
		Car tmp(other);
		std::swap(_acceleration, tmp._acceleration);
		std::swap(_size, tmp._size);
		std::swap(_data, tmp._data);
		return *this;
	}
	
	Car& operator=(Car&& other) noexcept {
		log("move assigment operation");
		std::swap(_acceleration, other._acceleration);
		std::swap(_size, other._size);
		std::swap(_data, other._data);
		return *this;
	}
	
	void push_acceleration() {
		std::cout << _acceleration << std::endl;
	}
	
private:
	
	void log(const char* msg) {
		std::cout << "[" << this << "] - " << msg<< "\n";
	}
	std::string _acceleration;
	size_t _size;
	int* _data;
};
int main() {
	Car v1(10);
	Car v2;
	Car v3;
	v1.push_acceleration();
	v2 = v1;
	v2.push_acceleration();
	v3 = std::move(v1);
	v3 = Car(20);
	v3.push_acceleration();
	return 0;
}