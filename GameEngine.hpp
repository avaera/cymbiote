/**
 * GameEngine.hpp - Header file for the Game Engine class, managing the 
 * primary logic of the game world.
 * 
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. 
 * Please see COPYING for more details.
 * 
 **/
 
#ifndef __GAMEENGINE_HPP__
#define __GAMEENGINE_HPP__

#include <iostream>
#include <vector>

#include "InterfaceServer.hpp"

namespace Cymbiote {
	
// GameEngine class
class GameEngine {
	public:
	
		// Default constructor
		GameEngine() : interface() {
			state = EngineState::UNINITIALISED;
		};
		
		// Initialisation function, returns true if there were no errors
		bool init();
		
		// Main logic for game loop, returns true upon clean shutdown
		bool run();
		
		// Ends the main game loop and shuts down the server, returns true if there were no errors
		bool stop();
		
		// Destructor (unused)
		~GameEngine() { };
	
	protected:
	
	private:
	
		// Enumerated state information
		struct EngineState {
			enum Setting {
				UNINITIALISED, INITIALISED, RUNNING, STOPPING, PAUSED
			};
		};
		
		// Any interface servers used by the game
		InterfaceServer interface;
		
		// The current enumerated state of the engine
		EngineState::Setting state;
		
		
};

}


#endif
