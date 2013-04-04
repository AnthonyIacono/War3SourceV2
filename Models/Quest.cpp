#include "Quest.h"
#include <iostream>
#include "Utils.h"
using namespace SourceHook;

namespace War3Source {
	Quest::Quest(const char *name, const char *className, IMap<SourceHook::String> *properties) {
		StrCopy(this->name, sizeof(this->name), name);
		StrCopy(this->className, sizeof(this->className), className);
		this->properties = properties;
	}

	Quest::~Quest() {
		this->properties->Destroy();
	}

	void Quest::Destroy() {
		delete this;
	}

	const char *Quest::GetName() {
		return this->name;
	}

	const char *Quest::GetClass() {
		return this->className;
	}
	
	unsigned int Quest::GetPropUnsignedInt(const char *key, unsigned int defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0");

		return strtoul(actualValue.c_str(), NULL, 10);
	}
	
	int Quest::GetPropInt(const char *key, int defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0");

		return atoi(actualValue.c_str());
	}
	
	float Quest::GetPropFloat(const char *key, float defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		String actualValue = this->properties->GetValue(key, "0.0");

		return (float)atof(actualValue.c_str());
	}
	
	SourceHook::String Quest::GetPropString(const char *key, SourceHook::String defaultValue, bool *propExists) {
		if(!this->properties->CheckContainsKey(key)) {
			return defaultValue;
		}

		return this->properties->GetValue(key, "");
	}
	
	void Quest::SetPropUnsignedInt(const char *key, unsigned int value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%u", value);

		this->properties->SetValue(key, buffer);
	}

	void Quest::SetPropInt(const char *key, int value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%d", value);

		this->properties->SetValue(key, buffer);
	}

	void Quest::SetPropFloat(const char *key, float value) {
		char buffer[64];
		sprintf_s(buffer, sizeof(buffer), "%f", value);

		this->properties->SetValue(key, buffer);
	}

	void Quest::SetPropString(const char *key, const char *value) {
		this->properties->SetValue(key, value);
	}

	bool Quest::CheckPropExists(const char *key) {
		return this->properties->CheckContainsKey(key);
	}
}