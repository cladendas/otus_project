#include "ServiceFuncs.h"

namespace json = boost::json;

std::string getStringField(const json::object& obj, 
                            const std::string& key, 
                            const std::string& defaultValue = "") {
    auto it = obj.find(key);
    if (it != obj.end() && it->value().is_string()) {
        return it->value().as_string().c_str();
    }
    return defaultValue;
}