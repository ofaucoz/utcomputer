#ifndef LO21_REPOSITORY_HASHMAP_H
#define LO21_REPOSITORY_HASHMAP_H


#include <unordered_map>

using namespace std;

/*
 * Abstract repository template for hasmaps.
 */
template<typename Type> class HashmapRepository {
protected:
    unordered_map<string, Type*> internalMap;

public:
    typedef unordered_map<string, Type*>::iterator Iterator;

    void set(string key, Type& value) {
        internalMap[key] = value;
    }

    Type get(string key) {
        return *internalMap[key];
    }

    bool has(string key) {
        return internalMap.find(key) != internalMap.end();
    }

    Iterator begin() {
        return internalMap.begin();
    }

    Iterator end() {
        return internalMap.end();
    }
};


#endif // LO21_REPOSITORY_HASHMAP_H
