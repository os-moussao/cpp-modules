#include "PmergeMe.hpp"

std::pair<std::vector<int>, std::string> parse(char **av) {
    std::vector<int> v;

    for (av++; *av != nullptr; av++) {
        char *s = *av;
        long long elem = 0;
        for (int i = 0; ; i++) {
            if (s[i] == '\0') {
                v.push_back(elem);
                break ;
            }

            if (s[i] == ' ') {
                v.push_back(elem);
                elem = 0;
            }

            else if (isdigit(s[i])) {
                elem = elem * 10 + s[i] - '0';

                if (elem > INT_MAX) {
                    return std::make_pair(std::vector<int>(), "Error: invalid argument: " + std::string(s) + " (integer too large)");
                }
            }
            
            else {
                return std::make_pair(std::vector<int>(), "Error: invalid argument: " + std::string(s));
            }
        }
    }

    return std::make_pair(v, "");
}

void PmergeMe(std::vector<int> &vec, bool use_multiset) {

    int sz = SZ(vec);

    // base case
    if (sz < 2)
        return ;

    // make vector of pairs
    std::vector<std::pair<int, int> > vp;
    vp.reserve(sz/2);

    for (int i = 0; i+1 < sz; i += 2) {
        vp.push_back(std::make_pair(std::max(vec[i], vec[i+1]), std::min(vec[i], vec[i+1])));
    }

    // recursively sort the array of pairs
    if (use_multiset) {
        std::multiset<std::pair<int,int> > mset(vp.begin(), vp.end());
        vp.clear(); // clearing a vector does not set its capacity to zero
        for (std::multiset<std::pair<int,int> >::iterator it = mset.begin(); it != mset.end(); ++it) {
            vp.push_back(*it);
        }
    } else { // use priority queue
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> >, std::greater<std::pair<int,int> > > minHeap(vp.begin(), vp.end());
        vp.clear();
        while (!minHeap.empty()) {
            vp.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    // make mainCain and pend element vectors
    std::vector<int> mainCain, pend;
    mainCain.reserve(sz / 2 + 2), pend.reserve(sz / 2 + 1);

    mainCain.push_back(vp[0].second);
    for (int i = 0; i < SZ(vp); i++) {
        mainCain.push_back(vp[i].first);
        pend.push_back(vp[i].second);
    }
    
    // last element will not be stored in the vector of pairs
    if (sz % 2) pend.push_back(vec[sz - 1]);

    // start insertions
    for (int i = 1; i < SZ(pend); i++) {
        std::vector<int>::iterator pos = upper_bound(mainCain.begin(), mainCain.end(), pend[i]);
        mainCain.insert(pos, pend[i]);
    }

    // put mainchain into the vector, their lengths are guaranteed to be equal
    for (int i = 0; i < sz; i++)
        vec[i] = mainCain[i];
    
    return ;
}

unsigned long long gettimeUS(void) {
	timeval	now;
	gettimeofday(&now, NULL);
    return now.tv_sec * 1e6 + now.tv_usec;
}