#ifndef RC_NET_H_INCLUDED
#define RC_NET_H_INCLUDED

#include "rc_os_defines.h"

#ifdef RC_ANDROID
#define RC_MOBILE
#endif

#ifdef RC_IOS
#define RC_MOBILE
#endif


#ifdef RC_ANDROID

#include <android/log.h>
//Using SDL and standard IO
#include "SDL.h"
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include "SDL_net.h"
#include <assert.h>
#include <vector>

#else

#ifdef RC_IOS

//Using SDL and standard IO
#include "SDL2/SDL.h"
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "SDL2/SDL_net.h"

#else
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_net.h>
#include <unistd.h>
#include <assert.h>

#endif //RC_IOS

#endif // RC_ANDROID

const int MAX_SOCKETS = 256;

struct rc_tcp_socket_obj
{
	TCPsocket socket;
	bool active = false;
};

std::vector<rc_tcp_socket_obj> rc_tcp_socket;

struct rc_udp_socket_obj
{
	UDPsocket socket;
	bool active = false;
};

std::vector<rc_udp_socket_obj> rc_udp_socket;

UDPpacket * rc_udp_packet;
int rc_udp_channel;
std::string rc_udp_data;
int rc_udp_len;
int rc_udp_maxlen;
std::string rc_udp_host;
Uint16 rc_udp_port;
int rc_packet_size = 0;
SDLNet_SocketSet rc_socket_set;

bool rc_net_init()
{
	if (SDLNet_Init() < 0)
	{
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		//exit(EXIT_FAILURE);
		return false;
	}
	rc_socket_set = SDLNet_AllocSocketSet(MAX_SOCKETS*2);

	rc_udp_packet = SDLNet_AllocPacket(512);
	rc_packet_size = 512;

	return true;
}

void rc_net_quit()
{
	if(rc_socket_set)
    {
        SDLNet_FreeSocketSet(rc_socket_set);
        rc_socket_set = NULL;
    }
	SDLNet_Quit();
}

int rc_net_tcp_openSocket(std::string host, Uint16 port)
{
    int id = -1;

    for(int i = 0; i < rc_tcp_socket.size(); i++)
	{
		if(!rc_tcp_socket[i].active)
		{
			id = i;
			break;
		}
	}

	if(id < 0)
	{
		rc_tcp_socket_obj obj;
		id = rc_tcp_socket.size();
		rc_tcp_socket.push_back(obj);
	}

    IPaddress ip;
    if(host.compare("") == 0)
    {
        //exit(0);
        SDLNet_ResolveHost(&ip, NULL, port);
    }
    else
    {
        //exit(0);
        SDLNet_ResolveHost(&ip, host.c_str(), port);
    }
    rc_tcp_socket[id].socket = SDLNet_TCP_Open(&ip);
    if(!rc_tcp_socket[id].socket)
		return -1;

	rc_tcp_socket[id].active = true;

	//cout << "Add socket to socket_set" << endl;
	SDLNet_TCP_AddSocket(rc_socket_set, rc_tcp_socket[id].socket);
	return id;
}

void rc_net_tcp_closeSocket(int _socket)
{
	if(_socket < 0 || _socket >= rc_tcp_socket.size())
		return;

	if(rc_tcp_socket[_socket].socket == NULL)
	{
		rc_tcp_socket[_socket].active = false;
		return;
	}
    SDLNet_TCP_DelSocket(rc_socket_set, rc_tcp_socket[_socket].socket);
    SDLNet_TCP_Close(rc_tcp_socket[_socket].socket);
    rc_tcp_socket[_socket].socket = NULL;
    rc_tcp_socket[_socket].active = false;
}

double rc_net_tcp_remoteHost(int _socket)
{
	if(_socket < 0 || _socket >= rc_tcp_socket.size())
		return -1;

	if(rc_tcp_socket[_socket].socket == NULL)
		return -1;

    IPaddress * ip =  SDLNet_TCP_GetPeerAddress(rc_tcp_socket[_socket].socket);
    return (double)ip->host;
}

double rc_net_tcp_remotePort(int _socket)
{
	if(_socket < 0 || _socket >= rc_tcp_socket.size())
		return -1;

	if(rc_tcp_socket[_socket].socket == NULL)
		return -1;

    IPaddress * ip = SDLNet_TCP_GetPeerAddress(rc_tcp_socket[_socket].socket);
    return (double)ip->port;
}

int rc_net_checkSockets(Uint32 m)
{
    return SDLNet_CheckSockets(rc_socket_set, m);
}

int rc_net_tcp_socketReady(int _socket)
{
	if(_socket < 0 || _socket >= rc_tcp_socket.size())
		return 0;

	if(rc_tcp_socket[_socket].socket == NULL)
		return 0;

    return SDLNet_SocketReady(rc_tcp_socket[_socket].socket);
}

int rc_net_tcp_getData(int socket, int numBytes, void * dst)
{
    int rtn = SDLNet_TCP_Recv(rc_tcp_socket[socket].socket, dst, numBytes);
    return rtn;
}

int rc_net_tcp_getData_str(int socket, int numBytes, std::string * dst)
{
    char c[numBytes+1];
    int rtn = rc_net_tcp_getData(socket, numBytes, c);
    c[numBytes] = '\0';
    //cout << "Read bytes: " << (string)c << endl;
    dst[0] = c;
    return rtn;
}

int rc_net_tcp_getData_dbl(int socket, int numBytes, double * dst)
{
    int i[numBytes];
    int rtn = rc_net_tcp_getData(socket, numBytes, i);
    for(int n = 0; n < numBytes; n++)
    {
        dst[n] = i[n];
    }
    return rtn;
}

void rc_net_tcp_sendData(int socket, std::string data)
{
    SDLNet_TCP_Send(rc_tcp_socket[socket].socket, data.c_str(), data.length());
}

int rc_net_tcp_acceptSocket(int socket_server)
{
	int socket_client = -1;

    for(int i = 0; i < rc_tcp_socket.size(); i++)
	{
		if(!rc_tcp_socket[i].active)
		{
			socket_client = i;
			break;
		}
	}

	if(socket_client < 0)
	{
		rc_tcp_socket_obj obj;
		socket_client = rc_tcp_socket.size();
		rc_tcp_socket.push_back(obj);
	}

    //cout << "\n\nthis is a test\n\n";
    if(rc_tcp_socket[socket_server].socket == NULL)
    {
        //cout << "no server" << endl;
        return -1;
    }
    bool val = (rc_tcp_socket[socket_client].socket = SDLNet_TCP_Accept(rc_tcp_socket[socket_server].socket));
    if(val)
        SDLNet_TCP_AddSocket(rc_socket_set, rc_tcp_socket[socket_client].socket);
	else
	{
		rc_tcp_socket[socket_client].socket = NULL;
		rc_tcp_socket[socket_client].active = false;
		return -1;
	}
    //cout << "cp1\n";
    return socket_client;
}

bool rc_net_udp_openSocket(Uint16 port)
{
	int socket = -1;

	for(int i = 0; i < rc_udp_socket.size(); i++)
	{
		if(!rc_udp_socket[i].active)
		{
			socket = i;
			break;
		}
	}

	if(socket < 0)
	{
		rc_udp_socket_obj obj;
		socket = rc_udp_socket.size();
		rc_udp_socket.push_back(obj);
	}

    bool rtn = (bool)(rc_udp_socket[socket].socket = SDLNet_UDP_Open(port));
    if(rtn)
	{
		SDLNet_UDP_AddSocket(rc_socket_set, rc_udp_socket[socket].socket);
		rc_udp_socket[socket].active = true;
	}
	else
	{
		rc_udp_socket[socket].active = false;
		rc_udp_socket[socket].socket = NULL;
		return -1;
	}

	return socket;
}

int rc_net_udp_socketReady(int socket)
{
    return SDLNet_SocketReady(rc_udp_socket[socket].socket);
}

int rc_net_udp_readStream(int socket, std::string * host, double * port, std::string * dst)
{
    //cout << "DEBUG READSTREAM\n";
    //UDPsocket sd;       /* Socket descriptor */
	//UDPpacket *p;       /* Pointer to packet memory */
	//int quit = 0;

    /* Make space for the packet */
	//if (!(rc_udp_packet = SDLNet_AllocPacket(512)))
	//{
	//	fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
	//	exit(EXIT_FAILURE);
	//}

	/* Main loop */

    /* Wait a packet. UDP_Recv returns != 0 if a packet is coming */
    //while(!quit)
    //{
        if (SDLNet_UDP_Recv(rc_udp_socket[socket].socket, rc_udp_packet))
        {
            //printf("UDP Packet incoming\n");
            //printf("\tChan:    %d\n", rc_udp_packet->channel);
            rc_udp_channel = rc_udp_packet->channel;
            //printf("\tData:    %s\n", (char *)rc_udp_packet->data);
            const char * c = (const char *)rc_udp_packet->data;
            //rc_udp_data = (string)c;
            *dst = (std::string)c;
            //printf("\tLen:     %d\n", rc_udp_packet->len);
            rc_udp_len = rc_udp_packet->len;
            //printf("\tMaxlen:  %d\n", rc_udp_packet->maxlen);
            rc_udp_maxlen = rc_udp_packet->maxlen;
            //printf("\tStatus:  %d\n", rc_udp_packet->status);
            //printf("\tAddress: %x %x\n", rc_udp_packet->address.host, rc_udp_packet->address.port);
            //rc_udp_host = SDLNet_ResolveIP(&rc_udp_packet->address);
            *host = SDLNet_ResolveIP(&rc_udp_packet->address);
            //rc_udp_port = rc_udp_packet->address.port;
            *port = rc_udp_packet->address.port;
            return 1;
            //quit = 1;
        }
        else
        {
            rc_udp_channel = 0;
            //rc_udp_data = "";
            *dst = "";
            rc_udp_len = 0;
            rc_udp_maxlen = rc_udp_packet->maxlen;
            //rc_udp_host = SDLNet_ResolveIP(&rc_udp_packet->address);
            *host = SDLNet_ResolveIP(&rc_udp_packet->address);
            //rc_udp_port = rc_udp_packet->address.port;
            *port = rc_udp_packet->address.port;
            return 0;
        }

    //}

    //SDLNet_FreePacket(rc_udp_packet);
}

Uint32 rc_net_udp_len()
{
    return rc_udp_len;
}

Uint32 rc_net_udp_maxlen()
{
    return rc_udp_maxlen;
}

std::string rc_net_udp_getRemoteHost(int socket)
{
	if(socket < 0 || socket >= rc_udp_socket.size())
		return "";

	if(!rc_udp_socket[socket].active)
		return "";

    IPaddress * ip = SDLNet_UDP_GetPeerAddress(rc_udp_socket[socket].socket,0);
    //
    return SDLNet_ResolveIP(ip);
}

double rc_net_udp_getRemotePort(int socket)
{
	if(socket < 0 || socket >= rc_udp_socket.size())
		return -1;

	if(!rc_udp_socket[socket].active)
		return -1;

    IPaddress * ip = SDLNet_UDP_GetPeerAddress(rc_udp_socket[socket].socket,0);
    return (double)ip->port;
}

void rc_net_udp_closeSocket(int socket)
{
	if(socket < 0 || socket >= rc_udp_socket.size())
		return;

	if(!rc_udp_socket[socket].active)
	{
		rc_udp_socket[socket].socket = NULL;
		return;
	}

    SDLNet_UDP_DelSocket(rc_socket_set, rc_udp_socket[socket].socket);
    SDLNet_UDP_Close(rc_udp_socket[socket].socket);
    rc_udp_socket[socket].socket = NULL;
    rc_udp_socket[socket].active = false;
}

int rc_net_udp_sendData(int slot, std::string host, Uint16 port, std::string s_data)
{
    IPaddress srvadd;

    if(s_data.length()+1 > rc_packet_size)
    {
        rc_packet_size = SDLNet_ResizePacket(rc_udp_packet, s_data.length()+1);
        if(rc_packet_size < s_data.length())
        {
            std::cout << "UDP_SendData Error: " << SDLNet_GetError() << endl;
            return 0;
        }
    }


    if(rc_udp_packet == NULL)
        return 0;


    if (SDLNet_ResolveHost(&srvadd, host.c_str(), port) == -1)
	{
		std::cout << "UDP_SendData Error: " << SDLNet_GetError() << "\n";
		//exit(EXIT_FAILURE);
		return 0;
	}

	rc_udp_packet->address.host = srvadd.host;
    rc_udp_packet->address.port = srvadd.port;
	rc_udp_packet->data = (Uint8*)s_data.c_str();


	rc_udp_packet->len = s_data.length()+1;
	//cout << "#Data = " << (char*)rc_udp_packet->data << endl;
	//cout << "#Length = " << rc_udp_packet->len << endl;
	SDLNet_UDP_Send(rc_udp_socket[slot].socket, -1, rc_udp_packet);

    return 1;
}

std::string rc_byteToString(Uint8 n)
{
    std::stringstream s;
    s << (Uint32)n;
    return s.str();
}

std::string rc_net_myLocalIP()
{
    //cout << "MYLOCALIP" << endl;
    IPaddress myIP;
    myIP.host = 0;
    myIP.port = 0;
    std::string net_name = SDLNet_ResolveIP(&myIP);
    SDLNet_ResolveHost(&myIP,net_name.c_str(),0);
    std::string ip = "";
    ip += rc_byteToString((Uint8)myIP.host) + ".";
    ip += rc_byteToString((Uint8)(myIP.host >> 8)) + ".";
    ip += rc_byteToString((Uint8)(myIP.host >> 16)) + ".";
    ip += rc_byteToString((Uint8)(myIP.host >> 24));
    //cout << "vagina: " << myIP.host << endl;
    return ip;
}



#endif // RC_NET_H_INCLUDED
