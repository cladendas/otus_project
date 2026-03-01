#pragma once

#include <boost/json.hpp>

namespace json = boost::json;

json::object targetStruct(std::string phone, 
                            std::string name, 
                            std::string email, 
                            std::string utm_source,
                            std::string utm_campaign,
                            std::string utm_content,
                            std::string utm_medium,
                            std::string utm_term
                        );