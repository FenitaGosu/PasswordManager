#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

#include "CryptoHash.h"

std::string Encryption::CryptoHash::GetMd5(const std::string& msg) const
{
	boost::uuids::detail::md5 hash;
	boost::uuids::detail::md5::digest_type digest;

	hash.process_bytes(msg.data(), msg.size());
	hash.get_digest(digest);

	const auto intDigest = reinterpret_cast<const int*>(&digest);
	std::string result;
	boost::algorithm::hex(intDigest, intDigest + (sizeof(boost::uuids::detail::md5::digest_type) / sizeof(int)), std::back_inserter(result));

	std::transform(result.begin(), result.end(), result.begin(),[](unsigned char c) { return std::tolower(c); });

	return result;
}
