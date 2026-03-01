#include "TargetStruct.h"

namespace json = boost::json;

json::object targetStruct(std::string phone, 
                            std::string name = "", 
                            std::string email = "", 
                            std::string utm_source = "",
                            std::string utm_campaign = "",
                            std::string utm_content = "",
                            std::string utm_medium = "",
                            std::string utm_term = ""
                        ) {

    json::object obj = {
        {"NAME", name},
        {"PHONE",
            json::array {
                {{"VALUE_TYPE", "OTHER"}, {"TYPE_ID", "PHONE"}, {"VALUE", phone}}
            }
        },
        {"EMAIL", 
            json::array {
                {{"VALUE_TYPE", "OTHER"}, {"TYPE_ID", "EMAIL"}, {"VALUE", email}}
            }
        },
        {"UTM_SOURCE", utm_source},
        {"UTM_CAMPAIGN", utm_campaign},
        {"UTM_MEDIUM", utm_medium},
        {"UTM_CONTENT", utm_content},
        {"UTM_TERM", utm_term}
    };

    return obj;
}