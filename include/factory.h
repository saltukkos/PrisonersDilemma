#pragma once

#include <interface.h>
#include <map>
#include <string>
#include "strategy.h"

template <class IdType>
class Factory
{
public:
	Factory() {}

	~Factory() {}

	bool Register(const IdType& id, Strategy* (*creator)(const IdType&) ) {
		return creators.insert(std::pair<IdType, Strategy* (*)(const IdType&)>(id, creator)).second;
	}

	Strategy* Create(const IdType& id, const std::string& dir) {
		auto it = creators.find(id);
		if (it != creators.end()) {
			return it->second(dir);
		}
		return 0;
	}

	void ShowRegistred() {
		auto it = creators.begin();
		
		while (it != creators.end()) {
			Interface::ShowName((it++)->first);
		}
	}

private:
	std::map<IdType, Strategy* (*)(const IdType&)> creators;
};

template<class IdType>
Factory<IdType>& Instance() {
	static Factory<IdType> f;
	return f;
}
