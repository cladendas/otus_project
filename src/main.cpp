#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/json.hpp>
#include <iostream>

#include "Handlers/Handler_tilda.h"
#include "Handlers/Handler_marquiz.h"
#include "Handlers/Handler_post_raw.h"
#include "Items.h"
#include "Logger.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace json = boost::json;

using tcp = net::ip::tcp;

bool validate_and_save(const std::string& json_str) {
    try {
        json::value data = json::parse(json_str);

        if (!data.as_object().contains("phone")) {
            return false;
        }
        
        // Проверяем наличие leads
        // if (!data.as_object().contains("leads")) {
        //     std::cerr << "No 'leads' found" << std::endl;
        //     return false;
        // }
        
        // // Проверяем phone в каждом lead
        // for (const auto& lead : data.at("leads").as_array()) {
        //     if (!lead.as_object().contains("phone")) {
        //         std::cerr << "No 'phone' in lead" << std::endl;
        //         return false;
        //     }
        // }
        
        // Сохраняем в файл
        // std::string filename = "tilda_data_" + get_timestamp() + ".json";
        // std::ofstream file(filename);
        // file << json::serialize(data);
        // std::cout << "Saved to " << filename << std::endl;
        return true;
        
    } catch (...) {
        return false;
    }
}

void handle_request(tcp::socket& socket) {
    beast::flat_buffer buffer;
    http::request<http::string_body> req;
    http::read(socket, buffer, req);
    
    http::response<http::string_body> res;
    
    if (req.method() == http::verb::post && req.target() == "/api/tilda") {
        if (validate_and_save(req.body())) {
            res.result(http::status::ok);
            res.body() = "{\"status\":\"success\"}";
        } else {
            res.result(http::status::bad_request);
            res.body() = "{\"status\":\"error\",\"message\":\"Invalid data\"}";
        }
    } else if (req.method() == http::verb::get && req.target() == "/api/tilda") {
        std::cout << "TEST GET\n";
    } else {
        res.result(http::status::not_found);
        res.body() = "{\"status\":\"error\",\"message\":\"Not found\"}";
    }
    
    res.set(http::field::content_type, "application/json");
    res.prepare_payload();
    http::write(socket, res);
    socket.shutdown(tcp::socket::shutdown_send);
}

void accept_connection(tcp::acceptor& acceptor) {
    acceptor.async_accept(
        [&acceptor](boost::system::error_code ec, tcp::socket socket) {

            if (!ec) {
                // std::make_shared<Session>(std::move(socket))->start();

                std::cout << "Connect!\n";
                handle_request(socket);
                accept_connection(acceptor);
            }
            
        }
    );
}

void start() {
    try {
        net::io_context context;
        tcp::acceptor acceptor{context, {tcp::v4(), 8080}};

        accept_connection(acceptor);

        std::cout << "Server listening on port 8080...\n";
        
        context.run();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    std::printf("Hello\n");
}

void test() {

    Logger::open_or_create_db();

    Items item("Handler_get_raw");

    std::string test_msg = "TEST_TEST";

    Logger::insert_info(item, test_msg);

    Logger::close_db();


    // json::object lead = {
    //     {"phone", "232432"},
    //     {"email", "7666@dfsrf.ewfe"},
    //     {"contacts", {
    //         {"phone", "111111"}
    //     }}
    // };

    // Handler_tilda::checkJsonPostJson(lead);
    // Handler_marquiz::checkJsonPostJson(lead);

    // Handler_post_raw::saveJsonToFile(lead);

    // std::string json_str = json::serialize(lead);
    // std::cout << json_str << std::endl;
}

int main() {

    test();

}
