#pragma once

#include <boost/json.hpp>
#include "../TargetStruct.h"
#include "../ServiceFuncs.h"

namespace json = boost::json;

json::object transformJson(const json::object& lead);