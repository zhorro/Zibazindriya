#include "episode.h"

Episode::Episode(QObject *parent)
	: QObject(parent)
{

}

Episode::Episode(const Episode & yep)
	: QObject(yep.parent())
{
	id                 = yep.id;

	local              = yep.local;             
	url	               = yep.url;	           
	podcast	           = yep.podcast;	   
	                                      
	newEpisode         = yep.newEpisode;        
	downloaded         = yep.downloaded;        
	stillInFeed        = yep.stillInFeed;       
	                                      
	timeUpdated        = yep.timeUpdated;       
	timeDownloaded     = yep.timeDownloaded;    
	created            = yep.created;           
	deleteAfter        = yep.deleteAfter;       
	                                      
	duration           = yep.duration;          
	lastPlayedPosition = yep.lastPlayedPosition;
	                                      
	title              = yep.title;             
	GUID               = yep.GUID;              
	description        = yep.description;       
	shownotes          = yep.shownotes;         
	src                = yep.src;               
	link               = yep.link;              
	                                      
	updating           = yep.updating;          
}

Episode::~Episode()
{

}

QString Episode::dbCreationString()
{
	return 	"CREATE TABLE episode ("
		"id                 INTEGER     PRIMARY KEY,"
		"local              TEXT,"
		"url                TEXT,"
		"podcast            INTEGER,"

		"newEpisode	    BOOLEAN,"
		"downloaded         BOOLEAN,"
		"stillInFeed        BOOLEAN,"

		"timeUpdated		TIME,"
		"timeDownloaded		TIME,"
		"created            TIME,"
		"deleteAfter        TIME,"

		"duration           DOUBLE,"
		"lastPlayedPosition DOUBLE,"

		"title              TEXT,"
		"GUID               TEXT,"
		"description        TEXT,"
		"shownotes          TEXT,"
		"src                TEXT,"
		"link               TEXT,"

		"updating           BOOLEAN"
		")";
}

