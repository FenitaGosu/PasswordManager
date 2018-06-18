#include <random>
#include <vector>
#include <algorithm>
#include <functional>

#include "RandomIntGenerator.h"

using namespace Tools;

template <class T>
struct RandomIntGenerator<T>::Impl
{
	Impl()
		: gen(std::random_device()())
	{
	}

	std::mt19937 gen;
	std::uniform_int_distribution<T> dis;
};

template <class T>
RandomIntGenerator<T>::RandomIntGenerator()
	: m_impl(std::make_unique<Impl>())
{
}

template <class T>
RandomIntGenerator<T>::RandomIntGenerator(T a, T b)
	: m_impl(std::make_unique<Impl>())
{
	SetParams(a, b);
}

template <class T>
RandomIntGenerator<T>::~RandomIntGenerator() = default;

template <class T>
void RandomIntGenerator<T>::SetParams(T a, T b)
{
	typename decltype (m_impl->dis)::param_type newParams(a, b);
	m_impl->dis.param(newParams);
}

template <class T>
T RandomIntGenerator<T>::Get()
{
	return m_impl->dis(m_impl->gen);
}

template <class T>
std::vector<T> RandomIntGenerator<T>::GetVector(size_t size)
{
	std::vector<T> res;
	res.reserve(size);

	std::generate_n(std::back_inserter(res), size, std::bind(m_impl->dis, std::ref(m_impl->gen)));

	return res;
}

template class Tools::RandomIntGenerator<int>;
template class Tools::RandomIntGenerator<size_t>;
