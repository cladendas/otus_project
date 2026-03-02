#include "Handler_marquiz.h"

json::object Handler_marquiz::checkJsonPostJson(const json::value& jv) {
    if (jv.is_object()) {
        const json::object& lead = jv.as_object();

        if (lead.count("contacts") && lead.at("contacts").as_object().count("phone")) {

            auto targetLead = Transformer_marquiz::transformJson(lead);

            //TODO: POST targetLead

            std::cout << "POST marquiz\n";

            std::string json_str = json::serialize(targetLead);
            std::cout << json_str << std::endl;

            return responseOk;
        } else {
            std::cerr << "Отсутствует phone\n";
        }
    } else {
        std::cerr << "JSON должен быть объектом\n";
    }

    return responseFalse;
}