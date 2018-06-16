#include <random>
#include <vector>
#include <algorithm>
#include <functional>

#include "RandomIntGenerator.h"

using namespace Tools;

struct RandomIntGenerator::Impl
{
	Impl()
		: gen(std::random_device()())
	{
	}

	std::mt19937 gen;
	std::uniform_int_distribution<int> dis;
};

RandomIntGenerator::RandomIntGenerator()
	: m_impl(std::make_unique<Impl>())
{
}

RandomIntGenerator::RandomIntGenerator(int a, int b)
	: m_impl(std::make_unique<Impl>())
{
	SetParams(a, b);
}

void RandomIntGenerator::SetParams(int a, int b)
{
	decltype (m_impl->dis)::param_type newParams(a, b);
	m_impl->dis.param(newParams);
}

int RandomIntGenerator::Get()
{
	return m_impl->dis(m_impl->gen);
}

std::vector<int> RandomIntGenerator::GetVector(size_t size)
{
	std::vector<int> res;
	res.reserve(size);

	std::generate_n(std::back_inserter(res), size, std::bind(m_impl->dis, std::ref(m_impl->gen)));

	return res;
}
