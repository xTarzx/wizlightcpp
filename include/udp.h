#include <iostream>

#ifdef _WIN32
typedef uint16_t u_int16_t;
#endif

class UDPSocket
{

public:
    UDPSocket();
    ~UDPSocket();
    std::string sendUDPCommand(const std::string &msg, const std::string &targetIp,
                               const u_int16_t port, std::string &broadcastIP);

private:
    bool initializeUDPSocket();

    int m_bCastSock;
};
