#pragma once

#include <boost/json.hpp>
#include "../TargetStruct.h"
#include "../ServiceFuncs.h"

namespace json = boost::json;

namespace Transformer_marquiz {
    json::object transformJson(const json::object& lead);
}