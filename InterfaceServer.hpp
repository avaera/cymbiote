/**
 * InterfaceServer.hpp - Header file for the Interface Server class, 
 * handling I/O with NetworkInterface and EventInterface threads.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/
 
#ifndef __INTERFACESERVER_HPP__
#define __INTERFACESERVER_HPP__

#include <deque>
#include <map>
#include <boost/shared_ptr.hpp>

#include "NetworkInterface.hpp"

namespace Cymbiote {

class InterfaceServer {

	public:
	
		// Default constructor
		InterfaceServer() { };
		
		// Default destructor
		~InterfaceServer();
		
		// Add a new telnet interface on the specified port
		bool new_telnet_interface(int port);
		
		// Check whether there are any new messages waiting
		// int count_inqueue_waiting();
		
		// Process the next message in the incoming queue into a request
		// that the engine can understand.
		// GameInput *process_inqueue();
		
	protected:
	
	private:
		// List of active network interface threads
		typedef boost::shared_ptr<NetworkInterface> network_ptr;
		std::map<int, network_ptr> interfaces;
		
		// Event management thread
		// EventInterface event_thread;
		
		// Queue for incoming requests and outgoing responses
		// std::deque<??> in_queue;
		// std::deque<??> out_queue;

	
};

}

#endif
