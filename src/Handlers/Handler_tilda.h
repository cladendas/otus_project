#pragma once

#include <boost/json.hpp>
#include <iostream>
#include "../Responses.h"
#include "../Transformers/Transformer_tilda.h"

namespace json = boost::json;

class Handler_tilda {
public:
    static json::object checkJsonPostJson(const json::value& jv);
};