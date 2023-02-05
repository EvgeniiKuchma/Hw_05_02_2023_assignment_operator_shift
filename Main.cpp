#include <iostream>
#include <string>
#include <algorithm>
class Car {
public:
	explicit Car(size_t num = 0) : _size(num), 
		_acceleration("Vwoom...vwoommm...vwooommm..."){log("constructor\n");}
	
	Car(const Car& other) : _size(other._size), _acceleration("Vwoom...vwoommm...vwooommm..."){
		log("copy constructor\n");
		for (size_t i = 0; i < _size; i++) {
			_acceleration[i] = other._acceleration[i];
		}
	}
	
	Car& operator=(const Car& other){
		log("copy assigment operator");
		Car tmp(other);
		std::swap(_size, tmp._size);
		std::swap(_size, tmp._size);
		return *this;
	}
	
	Car& operator=(Car&& other) noexcept {
		log("move assigment operation");
		std::swap(_size, other._size);
		std::swap(_size, other._size);
		return*this;
	}
	
	void push_acceleration() {
		std::cout << _acceleration << std::endl;
	}
	
private:
	
	void log(const char* msg) {
		std::cout << "[" << this << "]" << msg<< "\n";
	}
	std::string _acceleration;
	size_t _size;
};
int main() {
	Car v1(40);
	Car v2;
	Car v3;
	v1.push_acceleration();
	std::cout << "++++++++++++++++++++++++" << std::endl;
	v2 = v1;
	v3 = std::move(v1);
	return 0;
}