//main_http.cpp

#include "server_http.hpp"
#include "handler.hpp"

using namespace std;
using namespace TestWeb;

int main() {
    Server<HTTP> server(12345, 4);
    start_server<Server<HTTP>>(server);


    return 0;
}
