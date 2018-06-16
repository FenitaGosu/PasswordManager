#pragma once

#include <memory>
#include <vector>

namespace Tools {

class RandomIntGenerator
{
public:
	RandomIntGenerator();
	RandomIntGenerator(int a, int b);
	~RandomIntGenerator();

	void SetParams(int a, int b);

	int Get();
	std::vector<int> GetVector(size_t size);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

}
