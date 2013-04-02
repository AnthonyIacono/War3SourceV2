#include "Item.h"
#include <sh_vector.h>
#include <iostream>
using namespace SourceHook;

namespace War3Source {
	Item::Item(const char *name, const char *className, IMap<SourceHook::String> *properties) {
		strcpy_s(this->name, sizeof(name), name);
		strcpy_s(this->className, sizeof(className), className);
		this->properties = properties;
	}

	Item::~Item() {
		this->properties->Destroy();
	}

	void Item::Destroy() {
		delete this;
	}

	const char *Item::GetName() {
		return this->name;
	}

	const char *Item::GetClass() {
		return this->className;
	}

	unsigned int Item::GetPropUnsignedInt(const char *key, unsigned int defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0");

		return strtoul(actualValue.c_str(), NULL, 10);
	}

	int Item::GetPropInt(const char *key, int defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0");

		return atoi(actualValue.c_str());
	}

	float Item::GetPropFloat(const char *key, float defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0.0");

		return (float)atof(actualValue.c_str());
	}

	String Item::GetPropString(const char *key, String defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		return this->properties->GetValue(key, "");
	}

	void Item::SetPropUnsignedInt(const char *key, unsigned int value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%u", value);

		this->properties->SetValue(key, buffer);
	}

	void Item::SetPropInt(const char *key, int value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%d", value);

		this->properties->SetValue(key, buffer);
	}

	void Item::SetPropFloat(const char *key, float value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%f", value);

		this->properties->SetValue(key, buffer);
	}

	void Item::SetPropString(const char *key, const char *value) {
		this->properties->SetValue(key, value);
	}

	bool Item::CheckPropExists(const char *key) {
		return this->properties->CheckContainsKey(key);
	}
}