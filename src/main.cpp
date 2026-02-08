#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <iostream>

namespace beast = boost::beast;
namespace net = boost::asio;
using tcp = net::ip::tcp;

void accept_connection(tcp::acceptor& acceptor) {
    acceptor.async_accept(
        [&acceptor](boost::system::error_code ec, tcp::socket socket) {
            std::cout << "Connect!\n";
            accept_connection(acceptor);
        }
    );
}

int main() {
    try {
        net::io_context context;
        tcp::acceptor acceptor{context, {tcp::v4(), 8080}};

        accept_connection(acceptor);

        std::cout << "Server listening on port 8080...\n";
        
        context.run();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::printf("Hello\n");
}