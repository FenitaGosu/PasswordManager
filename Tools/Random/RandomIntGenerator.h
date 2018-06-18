#pragma once

#include <memory>
#include <vector>

namespace Tools {

template<class T>
class RandomIntGenerator
{
public:
	RandomIntGenerator();
	RandomIntGenerator(T a, T b);
	~RandomIntGenerator();

	void SetParams(T a, T b);

	T Get();
	std::vector<T> GetVector(size_t size);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
