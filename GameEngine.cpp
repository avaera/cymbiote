/**
 * GameEngine.cpp - Code file for the GameEngine class, managing the primary 
 * logic of the game world
 *
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/

#include "GameEngine.hpp"

namespace Cymbiote {

/**
 *  Performs any necessary actions to prepare the engine for initialisation
 */
bool GameEngine::init() {
	
	// Here will go much more later on.
	
	// Create a new telnet interface
	if ( !interface.new_telnet_interface(1023) ) {
		return false;
	}
	
	state = EngineState::INITIALISED;
	return true;
}

/**
 *  Main logic for game loop, returns true upon clean shutdown
 */
bool GameEngine::run() {

    // Ensure the engine state is valid
    switch (state) {
		case EngineState::UNINITIALISED:
			// The engine should be initialised
			if (!init()) {
				// Could not initialise the engine
				return false;
			}
			break;
		case EngineState::INITIALISED:
			// The engine is ready
			break;
		default:
		    // Engine not in a valid state to be run
		    std::cout << "Invalid request to start game engine." << std::endl;
		    return false;
		
	}
	state = EngineState::RUNNING;
    
	// Again, not much to do yet.
	
	// Main game loop
	for (;;) {
		
       // DO nothing
       break;

	}
	
	state = EngineState::INITIALISED;
	return true;
	
}

/** 
 * Requests that the engine shut down cleanly, once the current loop is 
 * completed. Returns false on any error.
 */
bool GameEngine::stop() {
	
	state = EngineState::STOPPING;
	
	// Perform necessary safety checks at a later stage.
	
	return true;
}

}
