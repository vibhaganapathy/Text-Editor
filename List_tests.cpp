#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_empty_defaultConstructor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_notEmpty_defaultConstructor) {
    List<int> list;
    list.push_back(1);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
}

TEST(test_push_back) {
    List<int> list;
    list.push_back(10);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 10);
}

TEST(test_push_front) {
    List<int> list;
    list.push_front(7);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 7);
    ASSERT_EQUAL(list.back(), 7);
}

TEST(test_push_both) {
    List<int> list;
    list.push_front(10);
    list.push_front(5);
    ASSERT_EQUAL(list.front(), 5);
    ASSERT_EQUAL(list.back(), 10);
}

TEST(push_mixed) {
    List<int> list;
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    ASSERT_EQUAL(list.size(), 3);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_front();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 2);
}

TEST(pop_back_empty) {
    List<int> list;
    list.push_back(5);
    list.push_back(6);
    list.pop_front();
    list.pop_front();

    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_pop_back_push) {
    List<int> list;
    list.push_back(1);
    list.pop_back();
    list.push_back(5);

    ASSERT_EQUAL(list.front(), 5);
    ASSERT_EQUAL(list.back(), 5);
    ASSERT_EQUAL(list.size(), 1);
}

TEST(test_size) {
    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
    }
    ASSERT_EQUAL(list.size(), 10);
}
 
TEST(test_size_push_pop) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    list.push_front(0);
    ASSERT_EQUAL(list.size(), 2);
}
 
TEST(test_iterator_big_three) { 
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // copy constructor
    List<int>::Iterator it1 = list.begin();
    List<int>::Iterator it2(it1);
    ASSERT_TRUE(it1 == it2);

    List<int> it4;
    List<int> copy(it4);
    ASSERT_TRUE(copy.empty());

    // assignment operator
    List<int>::Iterator it3 = list.end();
    it3 = it1;
    ASSERT_TRUE(it3 == it1);

    ++it1;
    ASSERT_TRUE(it1 != it2);
}
 
TEST(test_iterator_empty) {
    List<int> list;
    ASSERT_TRUE(list.begin() == list.end());
}
 
TEST(test_iterator_forward) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
 
    int k = 1;
    for (auto it = list.begin(); it != list.end(); ++it) {
        ASSERT_EQUAL(*it, k);
        ++k;
    }
    ASSERT_EQUAL(k, 4);
}
 
TEST(test_iterator_increment) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
 
    auto it = list.begin();
    auto oldIt = it++;
    ASSERT_EQUAL(*oldIt, 10);
    ASSERT_EQUAL(*it, 20);
}
 
TEST(test_iterator_default_constructor_equal) {
    List<int>::Iterator a;
    List<int>::Iterator b;
    ASSERT_TRUE(a == b);
}
 
TEST(test_iterator_default) {
    List<int> list;
    list.push_back(1);
    List<int>::Iterator defaultIt;
    ASSERT_TRUE(defaultIt != list.end());
}
 
TEST(test_iterator_decrement) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
 
    auto it = list.end();
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
    ASSERT_TRUE(it == list.begin());
}
 
TEST(test_iterator_decrement2) {
    List<int> list;
    list.push_back(5);
    list.push_back(6);
 
    auto it = list.end();
    auto oldIt = it--;
    ASSERT_TRUE(oldIt == list.end());
    ASSERT_EQUAL(*it, 6);
}
 
TEST(test_iterator_traverse_backward) {
    List<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
 
    auto it = list.end();
    for (int j = 5; j >= 1; --j) {
        --it;
        ASSERT_EQUAL(*it, j);
    }
}
 
TEST(test_iterator_equality_rules) { 
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // same list, same position
    auto it1 = list.begin();
    auto it2 = list.begin();
    ASSERT_TRUE(it1 == it2);

    // same list, different position
    ++it2;
    ASSERT_TRUE(it1 != it2);

    // two default iterators compare equality
    List<int>::Iterator def1;
    List<int>::Iterator def2;
    ASSERT_TRUE(def1 == def2);

    // default != list iterator
    ASSERT_TRUE(def1 != list.begin());
    ASSERT_TRUE(def1 != list.end());
}
 
TEST(test_erase) {
    List<int> list;
    list.push_back(42);
    auto it = list.erase(list.begin());
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(it == list.end());
}
 
TEST(test_erase_first) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.erase(list.begin());
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.size(), 2);
}
 
TEST(test_erase_last) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.end();
    --it;
    auto result = list.erase(it);
    ASSERT_TRUE(result == list.end());
    ASSERT_EQUAL(list.back(), 2);
    ASSERT_EQUAL(list.size(), 2);
}
 
TEST(test_erase_middle) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    ++it; 
    auto result = list.erase(it);
    ASSERT_EQUAL(*result, 3);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_insert_and_erase) { 
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // insert then erase element
    auto it = list.begin();
    ++it; 
    it = list.insert(it, 99); 
    ASSERT_EQUAL(*it, 99);
    ASSERT_EQUAL(list.size(), 4);

    it = list.erase(it); 
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.size(), 3);

    // erase then insert at same pos
    it = list.erase(it); 
    it = list.insert(it, 2); 
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}
 
TEST(test_insert_begin) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    auto it = list.insert(list.begin(), 1);
    ASSERT_EQUAL(*it, 1);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.size(), 3);
}
 
TEST(test_insert_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    auto it = list.insert(list.end(), 3);
    ASSERT_EQUAL(*it, 3);
    ASSERT_EQUAL(list.back(), 3);
    ASSERT_EQUAL(list.size(), 3);
}
 
TEST(test_insert_middle) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    auto midIt = list.begin();
    ++midIt; 
    auto it = list.insert(midIt, 2);
    ASSERT_EQUAL(*it, 2);
    ASSERT_EQUAL(list.size(), 3);
 
    auto checkIt = list.begin();
    ASSERT_EQUAL(*checkIt, 1);
    ++checkIt;
    ASSERT_EQUAL(*checkIt, 2);
    ++checkIt;
    ASSERT_EQUAL(*checkIt, 3);
}
 
TEST(test_insert_empty_list) {
    List<int> list;
    auto it = list.insert(list.end(), 7);
    ASSERT_EQUAL(*it, 7);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 7);
}
 
TEST(test_string_list) {
    List<string> list;
    list.push_back("hello");
    list.push_back("world");
    ASSERT_EQUAL(list.front(), "hello");
    ASSERT_EQUAL(list.back(), "world");
    ASSERT_EQUAL(list.size(), 2);
}
 
TEST(test_string_list_copy) {
    List<string> list;
    list.push_back("a");
    list.push_back("b");
    List<string> copyList = list;
    copyList.pop_front();
    ASSERT_EQUAL(list.front(), "a"); 
    ASSERT_EQUAL(copyList.front(), "b");
}
 
TEST(test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    ASSERT_TRUE(list.empty());
    list.push_back(99);
    ASSERT_EQUAL(list.front(), 99);
    ASSERT_EQUAL(list.size(), 1);
}
 
TEST(test_clear_empty_list) {
    List<int> list;
    list.clear();
    ASSERT_TRUE(list.empty());
}


TEST_MAIN()
