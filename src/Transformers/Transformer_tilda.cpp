#include "Transformer_tilda.h"

json::object transformJson(const json::object& lead) {

    json::object targetLead = targetStruct(
        lead.at("phone").as_string().c_str(),
        getStringField(lead, "name", ""),
        getStringField(lead, "email", ""),
        getStringField(lead, "utm_source", ""),
        getStringField(lead, "utm_campaign", ""),
        getStringField(lead, "utm_content", ""),
        getStringField(lead, "utm_medium", ""),
        getStringField(lead, "utm_term", "")
    );

    return targetLead;
}
