/**
 * TCPConnection.cpp - Code file for the TCPConnection class, 
 * which represents a connected client over the Telnet protocol.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/
 
#include "TCPConnection.hpp"

namespace Cymbiote {

/**
 * Writes a simple string to the connected socket.
 * TODO - add error handling, etc
 */
void TCPConnection::write(std::string message) {
	
	boost::asio::async_write(sock, boost::asio::buffer(message), 
	  boost::bind(
	    &Cymbiote::TCPConnection::write_handler, 
	    shared_from_this(), 
	    boost::asio::placeholders::error, 
	    boost::asio::placeholders::bytes_transferred
	  )
	);
	
}

/**
 * Handler function passed to the call to the boost asynchronous write.
 * At this point, nothing is needed.
 */
void TCPConnection::write_handler(const boost::system::error_code& err, size_t bytes_transferred) {
	
}

/**
 * Getter function for returning a string representation of the socket address
 */
std::string TCPConnection::get_address() { 
	
	if (sock.is_open())
		return sock.remote_endpoint().address().to_string(); 
	else
		return "Not connected";
	
}

/**
 * Getter function for returning an integer representation of the port address
 */
int TCPConnection::get_port() {
	
	if (sock.is_open())
		return sock.remote_endpoint().port(); 
	else
		return -1;
}

}
