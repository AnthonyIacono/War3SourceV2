#ifndef __war3source_databaseplayer_h__
#define __war3source_databaseplayer_h__

class DatabasePlayer {
public:
	DatabasePlayer(const char *steamID, CVector<DatabaseCharacter*> *databaseCharacters);
	~DatabasePlayer();

private:
	char steamID[64];
	CVector<DatabaseCharacter*> *databaseCharacters;
};

#endif