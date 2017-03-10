//
// web_server

#ifndef SERVER_HTTP_HPP
#define SERVER_HTTP_HPP

#include "server_base.hpp"

using namespace std;
namespace TestWeb {
    typedef boost::asio::ip::tcp::socket HTTP;
    template<>
    class Server<HTTP> : public ServerBase<HTTP> {
    public:
        //通过端口号，线程数来构造 Web 服务器
        Server(unsigned short port, size_t num_threads=1) :
            ServerBase<HTTP>::ServerBase(port, num_threads) {};
    private:
        //实现accept
        void accept() {
            //为当前连接创建一个新的 socket
            //智能指针用于传递临时对象给匿名函数
            auto socket = make_shared<HTTP>(m_io_service);

            acceptor.async_accept(*socket, [this, socket](const boost::system::error_code& ec) {
                //立即启动并接受一个连接
                accept();
                //如果出现错误
                if (!ec) process_request_and_respond(socket);
            });
        }
    };
}

#endif //SERVER_HTTP_HPP