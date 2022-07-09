#pragma once 

template <typename T,typename D>
class Pair
{
private:

	T first;
	D second;

public:

	Pair() = default;
	Pair(const T& first, const D& second);

	const T& getfirst() const;
	const D& getSecond() const;

	void setFirst(const T&);
	void setSecond(const D&);
};

template <typename T, typename D>
Pair<T, D>::Pair(const T& first, const D& second)
{
	setFirst(first);
	setSecond(second);
}

template <typename T, typename D>
const T& Pair<T, D>::getfirst() const
{
	return first;
}

template <typename T, typename D>
const D& Pair<T, D>::getSecond() const
{
	return second;
}

template <typename T, typename D>
void Pair<T, D>::setFirst(const T& otherFirst)
{
	first = otherFirst;
}

template <typename T, typename D>
void Pair<T, D>::setSecond(const D& otherSecond)
{
	second = otherSecond;
}