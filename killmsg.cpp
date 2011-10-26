// killmsg.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include "plugin_utils.h"

bool killmyself = 0;
bool triti=1; //getting killed if tked?

class killmsg : public bz_Plugin
{
  virtual const char* Name (){return "killmsg Plugin";}
  virtual void Init ( const char* config);

  virtual void Event ( bz_EventData *  eventData  );
};

BZ_PLUGIN(killmsg)

void killmsg::Init ( const char* commandLine )
{
  bz_debugMessage(4,"killmsg plugin loaded");
  if(&commandLine[0]) triti=atoi(&commandLine[0]);
  Register(bz_ePlayerDieEvent);


}

void killmsg::Event ( bz_EventData *eventData )
{
    if(eventData->eventType==bz_ePlayerDieEvent)
    {
      bz_PlayerDieEventData_V1* data = (bz_PlayerDieEventData_V1*)eventData;

      bz_BasePlayerRecord *playerdata; //create a playerrecord for the dead player.
      playerdata = bz_getPlayerByIndex(data->playerID); //get data

      bz_BasePlayerRecord *killerdata; //another playerrecord for the killer
      killerdata = bz_getPlayerByIndex(data->killerID); //get data
     
      if(killerdata&&playerdata)
      {
                //now we create a message to send to the killer
                std::string killermessage = std::string("You killed ") +
                playerdata->callsign.c_str();

                        if(data->killerID==data->playerID && killmyself==1)
                        {
                                //This kill is the kill you get after a teamkill...
                                killmyself=0;
                        }
                        else if(data->killerID==data->playerID)
                        {
                                bz_sendTextMessage(BZ_SERVER,data->killerID,"You commited suicide! Don't do that again!");
                        }
                        else if(killerdata->team==playerdata->team && killerdata->team!=eRogueTeam)
                        {
                                //Here we check whether the kill was a team kill
                                if(triti)killmyself=1; //The plugin gets confused if you get killed after a teamkill
                                std::string tkmessage = std::string("You killed teamate ") +
                                playerdata->callsign.c_str() +
                                std::string("! Don't do that again!") ;
                                bz_sendTextMessage(BZ_SERVER,data->killerID,tkmessage.c_str());
                        }
                        else
                        {
                                //Send the first message if no TK or suicide
                                bz_sendTextMessage(BZ_SERVER,data->killerID,killermessage.c_str());
                        }
      }
      //free the records here
      bz_freePlayerRecord(playerdata);
      bz_freePlayerRecord(killerdata);
    }
}

// made by alezakos

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

