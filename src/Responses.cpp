#include "Responses.h"

const json::object responseOk = {
    {"status", "ok"},
    {"message", "Данные получены"}, 
    {"code", 200}
};

const json::object responseFalse = {
    {"status", "error"},
    {"message", "Данные не соответствуют требованиям"}, 
    {"code", 400}
};