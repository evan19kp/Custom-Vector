#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <assert.h>
#include <iostream>
#include <string>

template <typename T>
class MyVector
{
public:
	static constexpr size_t DEFAULT_CAPACITY = 64;
	static constexpr size_t MINIMUM_CAPACITY = 8;

	MyVector(size_t capacity = DEFAULT_CAPACITY, size_t min = MINIMUM_CAPACITY)
	{	
		size_ = 0;
		capacity_ = capacity;
		if (capacity_ < min) {
			capacity_ = MINIMUM_CAPACITY;
		}
		elements_ = new T[capacity_];
	}

	MyVector(const MyVector& other)
	{
		size_ = other.size_;
		capacity_ = other.capacity_;
		elements_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++) {
			elements_[i] = other.elements_[i];
		}
	}

	~MyVector()
	{
		delete[] elements_;
		elements_ = nullptr;
	}

	MyVector& operator=(MyVector rhs)
	{
		std::swap(size_, rhs.size_);
		std::swap(capacity_, rhs.capacity_);
		std::swap(elements_, rhs.elements_);
		return *this;
	}

	T& operator[](size_t index) const
	{
		if (index < 0 || index >= size_) {
			std::cout << "Invalid index access." << std::endl;
			throw std::range_error("Index out of range");
		}
		return elements_[index];
	}

	size_t size() const
	{
		return size_;
	}

	size_t capacity() const
	{
		return capacity_;
	}

	bool empty() const
	{
		return size_ == 0;
	}

	T& at(size_t index) const
	{
		if (index >= size_ || index < 0) {
			std::cout << "Invalid index access." << std::endl;
			throw std::range_error("Index out of range");
		}
		return elements_[index];
	}

	void reserve(size_t capacity)
	{
		if (capacity > capacity_) {
			changeCapacity(capacity);
		}
	}

	T& set(size_t index, const T& element)
	{
		if (index >= size_ || index < 0) {
			std::cout << "Outside size boundary." << std::endl;
			throw std::range_error("Index out of range");
		}
		T& CopyElement = elements_[index];
		elements_[index].~T();
		elements_[index] = element;
		return CopyElement;
	}

	T& push_back(const T& element)
	{
		if (size_ == capacity_) {
			changeCapacity(capacity_ * 2);
		}
		elements_[size_++] = element;
		return elements_[size_ - 1];
	}

	T* begin() {
		return elements_;
	}

	T* end() {
		return elements_ + size_;
	}

	T pop_back()
	{
		if (size_ == 0) {
			std::cout << "Vector is already empty." << std::endl;
			throw std::range_error("Vector is empty");
		}
		T LastElement = *(end() - 1);
		size_--;
		while (size_ < capacity_ / 3 && capacity_ > MINIMUM_CAPACITY) {
			size_t n_capacity = capacity_ / 2;
			if (n_capacity < MINIMUM_CAPACITY) {
				n_capacity = MINIMUM_CAPACITY;
			}
			changeCapacity(n_capacity);
		}
		return LastElement;
	}

	T& insert(size_t index, const T& element)
	{
		if (index > size_ || index < 0) {
			std::cout << "Invalid index for insertion." << std::endl;
			throw std::range_error("Index out of range");
		}
		if (size_ == capacity_) {
			changeCapacity(capacity_ * 2);
		}
		for (size_t i = size_; i > index; --i) {
			elements_[i] = elements_[i - 1];
		}
		elements_[index] = element;
		size_++;
		return elements_[index];
	}

	T erase(size_t index)
	{
		if (index > size_ - 1 || index < 0) {
			std::cout << "Index out of bounds." << std::endl;
			throw std::range_error("Index out of range");
		}
		T Copyreturn_ = elements_[index];
		for (size_t i = index; i < size_; i++){
			elements_[i] = elements_[i + 1];
		}
		pop_back();
		return Copyreturn_;
	}

	void clear()
	{
		while (size_ > 0) {
			pop_back();
		}
		if (capacity_ != DEFAULT_CAPACITY) {
			changeCapacity(DEFAULT_CAPACITY);
		}
	}

private:
	size_t size_ = 0;
	size_t capacity_ = 0;
	T* elements_ = nullptr;

	void changeCapacity(size_t c)
	{
		if (c < size_) {
			std::cout << "Capacity too small for current elements." << std::endl;
			throw std::range_error("Insufficient capacity");
		}
		T* NewElements_ = new T[c];
		for (size_t i = 0; i < size_; i++) {
			NewElements_[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = NewElements_;
		capacity_ = c;
	}
};

#endif
