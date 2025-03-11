#include<catch2/catch_test_macros.hpp>

import spr;

TEST_CASE("If the index is in the Indexlist, check if contains agrees", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<1,2>;

    REQUIRE(contains_v<list, 1>);
}

TEST_CASE("If the index is not in the Indexlist, check if contains agrees", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<1,2>;

    REQUIRE(!contains_v<list, 0>);
}

