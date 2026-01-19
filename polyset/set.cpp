#include "set.hpp"

set::set() : _bag(nullptr) {}

set::set(searchable_bag& bag) : _bag(&bag) {}

set::set(searchable_bag* bag) : _bag(bag) {}

set::set(const set& other): {}