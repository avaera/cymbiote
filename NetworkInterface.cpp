/**
 * NetworkInterface.cpp - Code file for the Network Interface class, 
 * that communicates asynchronously with network clients in a separate 
 * thread, using the Boost.ASIO library.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/

#include "NetworkInterface.hpp"

namespace Cymbiote {

using namespace boost::asio::ip;

/**
 * Constructor initialises the necessary IO services and waits for
 * connections.
 */
NetworkInterface::NetworkInterface(int port) 
	: io_service(), acceptor(io_service, tcp::endpoint(tcp::v4(), port)) {
	
}

/**
 * Constructor initialises the necessary IO services and waits for
 * connections.
 */
TelnetInterface::TelnetInterface(int port) : NetworkInterface(port) {
	
	try {
		std::cout << "Cymbiote MUD now listening for telnet connections on port 1023." << std::endl;
		
		listen();
		
		io_service.run();
	} catch (std::exception& e) {
		std::cerr << "ERR: " << e.what() << std::endl;
	}
	
}

/**
 * Blocks on the io_service until a connection occurs
 */
void TelnetInterface::listen() {
	
	// Obtain a smart pointer reference to the new connection
	boost::shared_ptr<TCPConnection> new_conn 
	  = TCPConnection::create(acceptor.get_io_service());
	
	// Attempt an accept operation
	acceptor.async_accept(new_conn->get_socket(), 
	  boost::bind(
	    &Cymbiote::TelnetInterface::accept_handler, 
	    this, 
	    new_conn, 
	    boost::asio::placeholders::error
	  )
	);
	
}

/**
 * Handler function for accept operation.
 */
void TelnetInterface::accept_handler(boost::shared_ptr<TCPConnection> conn, const boost::system::error_code& error) {

	if (error) {
		// Do something about the error
		switch (error.value()) {
			using namespace boost::asio::error;
			case access_denied:
				std::cerr << "Permission to open a listening socket was denied. Do you have the necessary privileges?" << std::endl;
				break;
			case address_in_use:
				std::cerr << "Listening socket is already in use." << std::endl;
				break;
			default:
				std::cerr << "Unable to open listening socket." << std::endl;
			
		}
		
		return;
	}
	
	// Just send a test message for now, then disconnect the client
	conn->write("You have successfully connected.\n");
	std::cout << "Telnet connection from " << conn->get_address() << ":" << conn->get_port() << std::endl;
	
	listen();
}


}
