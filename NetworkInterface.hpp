/**
 * NetworkInterface.hpp - Header file for the Network Interface class, 
 * that communicates asynchronously with network clients in a separate 
 * thread, using the Boost.ASIO library.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/
 
#ifndef __NETWORKINTERFACE_HPP__
#define __NETWORKINTERFACE_HPP__

#include <iostream>
#include <boost/asio.hpp>

#include "TCPConnection.hpp"


// TODO - make into a separate thread

namespace Cymbiote {

/**
 * Abstract class for general network interface.
 */
class NetworkInterface {

	public:
	
		// Constructor runs the IO service and awaits connections
		NetworkInterface(int port);
		
		// Handle a new connection
		virtual void accept_handler(boost::shared_ptr<TCPConnection> conn, const boost::system::error_code& error) = 0;
		
		// Start listening for a new accept request
		virtual void listen() = 0;
		
		
	protected:

		// The BOOST IO service that this thread will use for communication.
		boost::asio::io_service io_service;
		
		// The BOOST acceptor that this thread will use to listen for
		// new connections
		boost::asio::ip::tcp::acceptor acceptor;
	
	private:
		
};

class TelnetInterface : public NetworkInterface {
	
	public:
	
		// Constructor
		TelnetInterface(int port);
		
		// Handle a new telnet connection
		virtual void accept_handler(boost::shared_ptr<TCPConnection> conn, const boost::system::error_code& error);
		
		// Start listening for a new accept request
		virtual void listen();
		
	protected:
	
	private:
	
		// List of all active connections
		// vector<boost::shared_ptr(TCPConnection)> clients;

};

}

#endif
