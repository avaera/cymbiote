/**
 * TCPConnection.hpp - Header file for the TCPConnection class, 
 * which represents a connected client over the Telnet protocol.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/
 
#ifndef __TCPConnection_HPP__
#define __TCPConnection_HPP__

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace Cymbiote {
	
using namespace boost::asio::ip;

class TCPConnection 
  : public boost::enable_shared_from_this<TCPConnection> {

	public:
		
		// Create a new connection and return a smart pointer to it,
		// following the usual BOOST style.
		static boost::shared_ptr<TCPConnection> create(boost::asio::io_service& sock_conn) {
			return boost::shared_ptr<TCPConnection>(new TCPConnection(sock_conn));
		};
		
		// Write a string message to this connection.
		// TODO - worry about formatting, protocol, etc.
		void write(std::string output);
		
		// Write handler function necessary for boost asynchronous write.
		void write_handler(const boost::system::error_code& err, size_t bytes_transferred);
		
		// Getter function for obtaining the socket directly.
		tcp::socket& get_socket() { return sock; };
		
		// Simple getter function to obtain the string address of the socket
		std::string get_address();
		
		// Simple getter function to obtain the port number of the socket
		int get_port(); 
	
	protected:
	
	private:
	
		// Constructor used by the create method
		TCPConnection(boost::asio::io_service& sock_conn) : sock(sock_conn) { };
	
		// The socket for this connection
		tcp::socket sock;

};

}

#endif
