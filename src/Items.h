#pragma once

#include <string>

class Items {
    std::string handler_get_raw = "Handler_get_raw";
    std::string handler_marquiz = "Handler_marquiz";
    std::string handler_post_raw = "Handler_post_raw";
    std::string handler_tilda = "Handler_tilda";

    std::string transformer_get_raw = "Transformer_get_raw";
    std::string transformer_marquiz = "Transformer_marquiz";
    std::string transformer_post_raw = "Transformer_post_raw";
    std::string transformer_tilda = "Transformer_tilda";

    bool set_item(std::string current_item) noexcept;

    std::string current_item = "";
public:

    Items(std::string _item);

    std::string get_item();
};