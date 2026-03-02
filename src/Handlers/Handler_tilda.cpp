#include "Handler_tilda.h"

json::object Handler_tilda::checkJsonPostJson(const json::value& jv) {
    if (jv.is_object()) {
        const json::object& lead = jv.as_object();

        if (lead.count("phone")) {

            auto targetLead = Transformer_tilda::transformJson(lead);

            //TODO: POST targetLead

            std::cout << "POST tilda\n";

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