#pragma once

#include <boost/json.hpp>
#include <iostream>
#include "../Responses.h"
#include "../Transformers/Transformer_marquiz.h"

namespace json = boost::json;

namespace Handler_marquiz {
    json::object checkJsonPostJson(const json::value& jv);
}