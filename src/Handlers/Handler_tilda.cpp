#include <boost/json.hpp>
#include <iostream>
#include "../Responses.cpp"

namespace json = boost::json;

struct Handler_tilda {
    static bool checkJson(const json::value& jv) {
        if (jv.is_object()) {
            const json::object& lead = jv.as_object();

            if (lead.count("phone")) {
                return true;
            } else {
                std::cerr << "Отсутствует phone\n";
            }
        } else {
            std::cerr << "JSON должен быть объектом\n";
        }

        return false;
    }
};
