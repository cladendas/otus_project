#include <boost/json.hpp>

namespace json = boost::json;

json::object responseOk = {
    {"status", "ok"},
    {"message", "Данные получены"}, 
    {"code", 200}
};

json::object responseFalse = {
    {"status", "error"},
    {"message", "Данные не соответстсвуют требованиям"}, 
    {"code", 400}
};
