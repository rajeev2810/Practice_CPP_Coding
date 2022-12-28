// interval_map .cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <assert.h>

#ifdef _NDEBUG
#undef _STLP_DEBUG
else
#define _STLP_DEBUG 1
#endif

template<typename K, typename V>
class interval_map  {
	friend void IntervalMapTest();
	V m_valBegin;	
public:
    std::map<K, V> m_map;
	// constructor associates whole range of K with val
	interval_map (V const& val)
		: m_valBegin(val)
	{}

	// Assign value val to inteendValueal [keyBegin, keyEnd).
	// Overwrite previous values in this inteendValueal.
	// Conforming to the C++ Standard Library conventions, the inteendValueal
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty inteendValueal,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
      
        if (keyEnd < keyBegin)
            return;
        if (m_map.empty()) {
            if (val == m_valBegin)
                return;
            m_map.insert(std::make_pair(keyBegin, val));
            m_map.insert(std::make_pair(keyEnd, m_valBegin));
        }
        
        V value = (*this)[keyBegin];
        if (!(value == val)) {
            const auto [it, success] = m_map.insert(std::make_pair(keyBegin, val));
            // if the key is already assigned.
            if (!success) {
                if (it != m_map.end())
                  it->second = val;
            }
        }
		// INSERT YOUR SOLUTION HERE
	}

	// look-up of the value associated with key
	V const& operator[](K const& key) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		}
		else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map , for example using a map of int inteendValueals to char.


class myK {
public:
    int val;
    myK(int V) : val(V) {}
    myK(const myK& M) : val(M.val) {}

    friend bool operator<(const myK& l, const myK& r)
    {
        return l.val < r.val; // keep the same order
    }
};

class myV {
public:
    char c;
    myV(char C) : c(C) {}
    myV(const myV& M) : c(M.c) {}

    friend bool operator==(const myV& l, const myV& r)
    {
        return l.c == r.c; // keep the same order
    }
};

int main() {
    interval_map <myK, myV> mymap('a');
    assert(mymap.m_map.empty());
    mymap.assign(1, 3, 'a');
    assert(mymap.m_map.empty());
    mymap.assign(1, 3, 'w');
    for (auto& p : mymap.m_map) {
        std::cout << p.first.val << " : " << p.second.c << '\n';
    }
    return 0;
}
/*
Correctness: Your program should produce a working interval_map with the behavior described above.In particular, pay attention to the validity of iterators.It is illegal to dereference end iterators.Consider using a checking STL implementation such as the one shipped with Visual C++ or GCC.
*/
