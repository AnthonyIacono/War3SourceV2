#ifndef __war3source_item_h__
#define __war3source_item_h__

class Item {
public:
	Item(const char *key);
	~Item();

private:
	char key[64];
};

#endif