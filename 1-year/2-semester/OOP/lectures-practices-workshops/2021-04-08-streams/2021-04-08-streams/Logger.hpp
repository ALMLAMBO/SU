#pragma once
#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <iostream>
#include <fstream>

template<typename T>
class Logger {
public:
	void write(const char* message);
	void write(const T* message);
	void writeLine(const char* message);
	void writeLine(const T* message);

private:
	int id;
	const char* filename = "logs.txt";
};

template<typename T>
void Logger<T>::write(const char* message) {
	std::ofstream file_to_write(this->filename, std::ios::app);

	if (file_to_write.is_open()) {
		file_to_write << message;
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}

	file_to_write.close();
}

template<typename T>
void Logger<T>::Logger::write(const T* message) {
	std::ofstream file_to_write(this->filename, std::ios::app);

	if (file_to_write.is_open()) {
		file_to_write << *message;
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}

	file_to_write.close();
}

template<typename T>
void Logger<T>::writeLine(const char* message) {
	std::ofstream file_to_write(this->filename, std::ios::app);

	if (file_to_write.is_open()) {
		file_to_write << message;
		file_to_write << '\n';
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}

	file_to_write.close();
}

template<typename T>
void Logger<T>::writeLine(const T* message) {
	std::ofstream file_to_write(this->filename, std::ios::app);

	if (file_to_write.is_open()) {
		file_to_write << *message;
		file_to_write << '\n';
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}

	file_to_write.close();
}

#endif // !__LOGGER_HPP__