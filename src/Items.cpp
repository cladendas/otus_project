#include "Items.h"

bool Items::set_item(std::string current_item) noexcept {
    if (current_item == handler_get_raw) {
        this->current_item = handler_get_raw;
    } else if (current_item == handler_marquiz) {
        this->current_item = handler_marquiz;
    } else if (current_item == handler_post_raw) {
        this->current_item = handler_post_raw;
    } else if (current_item == handler_tilda) {
        this->current_item = handler_tilda;
    } else if (current_item == transformer_get_raw) {
        this->current_item = transformer_get_raw;
    } else if (current_item == transformer_marquiz) {
        this->current_item = transformer_marquiz;
    } else if (current_item == transformer_post_raw) {
        this->current_item = transformer_post_raw;
    } else if (current_item == transformer_tilda) {
        this->current_item = transformer_tilda;
    }

    if (current_item.empty()) {
        return false;
    }

    return true;
}

Items::Items(std::string _item) {
    set_item(_item);
}

std::string Items::get_item() {
    return current_item;
}