#ifndef __war3source_characteritem_h__
#define __war3source_characteritem_h__

class Character;
class Item;

class CharacterItem {
public:
	CharacterItem(Character *character, Item *item, int quantity);
	~CharacterItem();

private:
	Character *character;
	Item *item;
	int quantity;
};
#endif