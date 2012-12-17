/**
 * InterfaceServer.cpp - Code file for the the Interface Server class, 
 * handling I/O with NetworkInterface and EventInterface threads.
 *
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/

#include "InterfaceServer.hpp"

namespace Cymbiote {

/**
 * Opens a new Telnet listening interface on the given port number
 */
bool InterfaceServer::new_telnet_interface(int port) {
	
	try {
		boost::shared_ptr<NetworkInterface> listener( new TelnetInterface(port) );
		
		interfaces[port] = listener;
		
	} catch (std::exception& e) {
		std::cerr << "Could not open telnet interface on port " << port << ": " << e.what() << std::endl;
		return false;
	}
	
	return true;
}

/**
 * Returns the number of pending incoming requests from any interface.
 *
int InterfaceServer::count_inqueue_waiting() {
	
	return 0;
	
}*/

/**
 * Parses the next incoming request into a GameInput object that the
 * engine can understand and implement.
 *
GameInput *InterfaceServer::process_inqueue() {
	return NULL;
}*/


/**
 *  Destructor
 */
InterfaceServer::~InterfaceServer() {

}

}
