#include "StringBoundTest.hpp"

bool StringBoundTest::operator()(const std::string& str) const {
    return ((str.size() >= m_lowerBound) && (str.size() <= m_upperBound));
}
