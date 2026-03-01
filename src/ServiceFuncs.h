#pragma once

#include <boost/json.hpp>
#include <string>

namespace json = boost::json;

std::string getStringField(const json::object& obj, 
                            const std::string& key, 
                            const std::string& defaultValue);