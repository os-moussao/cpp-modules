#include "PmergeMe.hpp"


int main(int ac, char **av) {

    if (ac < 2) {
        return std::cerr << "usage: ./PmergeMe <positive integer sequence>\n", 1; 
    }

    std::pair<std::vector<int>, std::string> pr = parse(av);

    if (!pr.second.empty()) {
        return std::cerr << pr.second << '\n', 1;
    }

    // getting two copies to test with 2 diffrent containers
    std::vector<int> a(pr.first), b(pr.first);

    // print before
    std::cout << "before: ";
    for (int i = 0; i < SZ(pr.first); i++) {
        std::cout << pr.first[i] << ' ';
    }
    std::cout << std::endl;

    // sort    
    PmergeMe(pr.first, 1);
    
    // print after
    std::cout << "after: ";
    for (int i = 0; i < SZ(pr.first); i++) {
        std::cout << pr.first[i] << ' ';
    }
    std::cout << std::endl;

    // compare timing of the containers

    // using multiset
    unsigned long long before_mset = gettimeUS();
    PmergeMe(a, 1);
    unsigned long long after_mset = gettimeUS();

    // using priority queue
    unsigned long long before_pq = gettimeUS();
    PmergeMe(a, 1);
    unsigned long long after_pq = gettimeUS();

    std::cout << "Time to process a range of " << SZ(a) << " elements with std::multiset : " << after_mset-before_mset << " us" << std::endl;
    std::cout << "Time to process a range of " << SZ(a) << " elements with std::priority_queue : " << after_pq-before_pq << " us" << std::endl;
}