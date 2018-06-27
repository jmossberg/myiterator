#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

class MyIterator2 : public std::iterator<std::vector<int>::iterator::iterator_category, std::vector<int>::iterator::value_type>
{
    std::vector<int>::iterator it_;
    std::vector<int>::iterator it_next_;
    std::vector<int>::iterator it_end_;
public:
    MyIterator2(std::vector<int>::iterator it, std::vector<int>::iterator it_end) : it_(it), it_next_(it), it_end_(it_end) {}
    MyIterator2& operator++() {auto res=std::find(it_next_,it_end_,2); it_=res; it_next_=it_; it_next_++; return *this;} //prefix
    int& operator*() {return *it_;}
    bool operator!=(const std::vector<int>::iterator& rhs) const {return it_!=rhs;}
};

int main()
{
    std::vector<int> v{1,2,3,2,5,2,1};
    MyIterator2 my_it{std::begin(v), std::end(v)};

    for( ; my_it!=std::end(v) ; ++my_it ) {
        std::cout << *my_it << " ";
    }
    std::cout << std::endl;

    return 0;
}
