#include "EqualCheck.hpp"

bool EqualCheck::operator()(int value) const {
    return m_value == value;
}
