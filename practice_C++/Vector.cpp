#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector():
	mX(0), mY(0)
{
}

Vector::Vector(int x, int y):
	mX(x), mY(y)
{
}

Vector::Vector(const Vector& other)
	:mX(other.getX()), mY(other.getY())
{
}

Vector::~Vector()
{
}

int Vector::getX() const
{
	return mX;
}

int Vector::getY() const
{
	return mY;
}

void Vector::setX(int num)
{
	mX = num;
}

void Vector::setY(int num)
{
	mY = num;
}

void Vector::Add(const Vector& other)
{
	this->mX += other.mX;
	this->mY += other.mY;
}

bool Vector::IsEqual(const Vector& v) const
{
	return mX == v.getX() && mY == v.getY();
}

Vector Vector::operator*(const Vector& v) const
{
	Vector result(this->mX * v.getX(), this->mY * v.getY());

	return result;
}

Vector Vector::operator*(int multiplier) const
{
	Vector result(this->mX * multiplier, this->mY * multiplier);
	
	return result;
}

Vector Vector::operator*=(const Vector& rhs)
{
	this->mX *= rhs.getX();
	this->mY *= rhs.getY();

	return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
	Vector result(mX + rhs.getX(), mY + rhs.getY());
	return result;
}

Vector Vector::operator+=(const Vector& rhs) {
	
	this->mX += rhs.getX();
	this->mY += rhs.getY();

	return *this;
}