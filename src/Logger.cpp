#include "Logger.h"

sqlite3* Logger::db = nullptr;
std::string Logger::path = "log.db";
char* Logger::erm = nullptr;

bool Logger::open_or_create_db() {
    bool open_result = sqlite3_open(path.c_str(), &db);

    if (open_result != SQLITE_OK) {
        std::cerr << "Unable to open DB\n";
        return false;
    }

    int result_create_table = sqlite3_exec(db, "CREATE TABLE log(id INTEGER PRIMARY KEY AUTOINCREMENT, timestamp INTEGER, item TEXT, message TEXT)", 0, 0, &erm);

    if (result_create_table != SQLITE_OK) {
        std::cerr << "------- Table is not create\n";
        std::cerr << erm << '\n';
        return false;
    }
    
    return true;
}

bool Logger::close_db() {
    int close_result = sqlite3_close(db);

    if (close_result) {
        std::cerr << "DB close error\n";
        return false;
    }
    
    return true;
}

bool Logger::insert_info(Items& item, std::string& message) {
    sqlite3_stmt* stmt;
    
    // Подготовка запроса с плейсхолдерами
    const char* sql = "INSERT INTO log (timestamp, item, message) VALUES (strftime('%s', 'now'), ?, ?)";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        return false;
    }
    
    // Привязка параметров
    sqlite3_bind_text(stmt, 1, item.get_item().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, message.c_str(), -1, SQLITE_TRANSIENT);

     // Выполнение запроса
    rc = sqlite3_step(stmt);
    
    // Очистка
    sqlite3_finalize(stmt);
    
    return rc == SQLITE_DONE;
}