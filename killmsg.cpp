// killmsg.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include "plugin_utils.h"

BZ_GET_PLUGIN_VERSION

bool killmyself = 0;
bool triti=1; //getting killed if tked?

// event handler callback
class killmsg_events : public bz_EventHandler
{
public:
  virtual void process ( bz_EventData *eventData );

  virtual bool autoDelete ( void ) { return false;} // this will be used for more then one event
};

killmsg_events killmsg_events;
BZF_PLUGIN_CALL int bz_Load ( const char* commandLine )
{
  bz_debugMessage(4,"killmsg plugin loaded");
  if(&commandLine[0]) triti=atoi(&commandLine[0]);
  bz_registerEvent(bz_ePlayerDieEvent,&killmsg_events);
  return 0;
}

BZF_PLUGIN_CALL int bz_Unload ( void )
{
  bz_debugMessage(4,"killmsg plugin unloaded");
  bz_removeEvent(bz_ePlayerDieEvent,&killmsg_events);
  return 0;
}

void killmsg_events::process ( bz_EventData *eventData )
{
    if(eventData->eventType==bz_ePlayerDieEvent)
    {
      bz_PlayerDieEventData* data = (bz_PlayerDieEventData*)eventData;

      bz_PlayerRecord *playerdata; //create a playerrecord for the dead player.
      playerdata = bz_getPlayerByIndex(data->playerID); //get data

      bz_PlayerRecord *killerdata; //another playerrecord for the killer
      killerdata = bz_getPlayerByIndex(data->killerID); //get data
      
      if(killerdata&&playerdata)
      {
	//now we create a message to send to the killer
	std::string killermessage = std::string("You killed ") +
	playerdata->callsign.c_str();
	
	if(data->killerID==data->playerID && killmyself==1) 
	{
		killmyself=0;
	}
	else if(data->killerID==data->playerID) 
	{
		bz_sendTextMessage(BZ_SERVER,data->killerID,"You commited suicide! Don't do that again!");
	}
	else if(killerdata->team==playerdata->team && killerdata->team!=eRogueTeam) {
		//Here we check whether the team was a team kill
		if(triti)killmyself=1; //The plugin gets confused if you get killed after a teamkill
		std::string tkmessage = std::string("You killed teamate ") +
		playerdata->callsign.c_str() +
		std::string("!") +
		std::string(" Don't do that again!") ;
		bz_sendTextMessage(BZ_SERVER,data->killerID,tkmessage.c_str());
	}
	else {
		bz_sendTextMessage(BZ_SERVER,data->killerID,killermessage.c_str());
		//send the messages we created
	}
      }
      //free the records here
      bz_freePlayerRecord(playerdata);
      bz_freePlayerRecord(killerdata);
    }
}



//plugin by alezakos



// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

