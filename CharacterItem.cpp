#include "characteritem.h"

CharacterItem::CharacterItem(Character *character, Item *item, int quantity) {
	this->character = character;
	this->item = item;
	this->quantity = quantity;
}