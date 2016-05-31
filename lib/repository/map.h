#ifndef LO21_REPOSITORY_MAP_H
#define LO21_REPOSITORY_MAP_H


#include <iostream>
#include <unordered_map>
#include "observable.h"

/*
 * Observable map based on the standard unordered_map and dispatching
 * notifications to observers on data change.
 */
template<class K, class V> class ObservableMap : public std::unordered_map<K, V>, public Repository {
public:
    const V& get(const K& key) const {
        return this->at(key);
    }

    bool has(const K& key) const {
        return this->find(key) != this->end();
    }

    void set(const K& key, const V& value) {
        this->emplace(key, value);
    }

    void setAndNotify(const K& key, const V& value) {
        this->set(key, value);
        notify();
    }

    void remove(const K& key) {
        this->erase(key);
    }

    void removeAndNotify(const K& key) {
        this->remove(key);
        notify();
    }
};


#endif //LO21_REPOSITORY_MAP_H
