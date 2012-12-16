/**
 * CymbioteServer.cpp - Initiates the main game engine and controls program execution.
 *
 * Copyright 2012 Brett Richards
 * This software is licensed under the GNU General Public License v3. Please see COPYING for more details.
 *
 **/

#include "CymbioteServer.h"

using namespace std;

int main() {
	
	Cymbiote::GameEngine engine;
	
	// Initialise the game engine.
	if ( !engine.init() ) {
		
		// Exit on error for now.
		cout << "Unable to initialise game engine. Exiting." << endl;
		return -1;
		
	}
		
	while ( engine.loop() ) {
		
		// Consider delay to avoid excessive CPU use
		
		// Statistics may also be gathered here
		
		// For now, just stop after one loop until we have actual logic.
		engine.stop();
	}
	
	cout << "Cymbiote server shut down successfully." << endl;
	return 0;
	
}
