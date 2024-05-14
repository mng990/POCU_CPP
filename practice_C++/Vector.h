#pragma once
#include <iostream>

class Vector
{
public:
	Vector();
	Vector(int x, int y);
	Vector(const Vector& other);
	~Vector();

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	void Add(const Vector& other);


	bool IsEqual(const Vector& v) const;
	Vector operator*(const Vector& v) const;
	Vector operator*(int multiplier) const;
	Vector operator*=(const Vector& v);


	Vector operator+(const Vector& rhs) const;
	Vector operator+= (const Vector & rhs);

	friend std::ostream& operator<< (std::ostream& os, const Vector& vec) 
	{
		os << vec.getX() << " / " << vec.getY() << "\n";
		return os;
	}

	Vector& operator= (Vector vec) {
		this->mX = vec.getX();
		this->mY = vec.getY();

		return *this;
	}

private:
	int mX;
	int mY;
};

