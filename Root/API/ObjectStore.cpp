/**********************************************************\
See http://code.google.com/p/indexeddb for license
Copyright Brandon Haynes
\**********************************************************/

#include "ObjectStore.h"

namespace BrandonHaynes {
namespace IndexedDB { 
namespace API { 

ObjectStore::ObjectStore(const std::string& name, const Implementation::ObjectStore::Mode mode)
	: name(name), mode(mode)
	{
	registerProperty("name", make_property(this, &ObjectStore::getName));
	registerProperty("keyPath", make_property(this, &ObjectStore::getKeyPath));
	registerProperty("mode", make_property(this, &ObjectStore::getModeInteger));
	registerProperty("indexNames", make_property(this, &ObjectStore::getIndexNameVariants));
	}
}
}
}