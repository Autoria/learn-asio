

#include "server_https.hpp"
#include "handler.hpp"
using namespace TestWeb;

int main()
{
    Server<HTTPS> server(12345, 4, "server.crt", "server.key");
    start_server<Server<HTTPS>>(server);

    return 0;
}