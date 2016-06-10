#ifndef LO21_REPOSITORY_MAP_H
#define LO21_REPOSITORY_MAP_H


#include <iostream>
#include <unordered_map>
#include "observable.h"

/**
 * An observable map is a standard map with the addition of being a repository,
 * and therefore being observable. It dispatches notifications to listeners
 * when the data change.
 */
template<class K, class V>
class ObservableMap : public std::unordered_map<K, V>, public Repository {
public:

    /**
     * Get an item by its key.
     *
     * @param key The key of the item.
     * @return The item.
     */
    const V &get(const K &key) const {
        return this->at(key);
    }

    /**
     * Check if a given key exists in the map.
     *
     * @param key The key to check.
     * @return Whether the key was found or not.
     */
    bool has(const K &key) const {
        return this->find(key) != this->end();
    }

    /**
     * Set an item at a key and replace it if it already exist.
     *
     * @param key The key to use.
     * @param value The item to store at this key.
     */
    void set(const K &key, const V &value) {
        (*this)[key]=value;
    }

    /**
     * Act as `set` (set an item at a key) and notify the changement right after.
     *
     * @param key The key to use.
     * @param value The item to store at this key.
     */
    void setAndNotify(const K &key, const V &value) {
        this->set(key, value);
        notify();
    }

    /**
     * Remove the item at a given key.
     *
     * @param key The key to remove.
     */
    void remove(const K &key) {
        this->erase(key);
    }

    /**
     * Act as `remove` (remove the item at a given key) and notify the changement right after.
     *
     * @param key The key to remove.
     */
    void removeAndNotify(const K &key) {
        this->remove(key);
        notify();
    }

};


#endif //LO21_REPOSITORY_MAP_H
