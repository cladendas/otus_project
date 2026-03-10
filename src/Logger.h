#pragma once

#include <sqlite3.h>
#include <iostream>
#include "Items.h"

class Logger {
    static sqlite3 *db;
    static std::string path;
    static char* erm;

public:
    static bool open_or_create_db();

    static bool close_db();

    static bool insert_info(Items& item, std::string& message);
};