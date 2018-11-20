//
// Created by bantdit on 11/19/18.
//

#include <gtest/gtest.h>
#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "../src/type_list.h"

::testing::AssertionResult type_list_test() {
    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::size == 3);

    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::get_type_index<uint8_t>::value == 0);
    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::get_type_index<uint16_t>::value == 1);
    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::get_type_index<int32_t>::value == 2);

    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::has_type<uint8_t>::value);
    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::has_type<uint16_t>::value);
    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::has_type<int32_t>::value);

    static_assert(easy_mp::type_list<uint8_t, uint16_t, int32_t>::has_type<int64_t>::value == false);

    return ::testing::AssertionSuccess();
}

::testing::AssertionResult type_list_head_tail() {
    static_assert(std::is_same_v<
            typename easy_mp::head<easy_mp::type_list<uint8_t, uint16_t, int32_t>>::type,
            easy_mp::type_list<uint8_t>>);

    static_assert(std::is_same_v<
            typename easy_mp::tail<easy_mp::type_list<uint8_t, uint16_t, int32_t>>::type,
            easy_mp::type_list<uint16_t, int32_t>>);

    return ::testing::AssertionSuccess();
}

::testing::AssertionResult type_list_concat() {
    static_assert(std::is_same_v<
            typename easy_mp::concat<easy_mp::type_list<uint8_t, uint16_t>, easy_mp::type_list<int32_t>>::type,
            easy_mp::type_list<uint8_t, uint16_t, int32_t>>);

    return ::testing::AssertionSuccess();
}

TEST(TYPE_LIST_TEST, type_list_internals) {
    EXPECT_TRUE(type_list_test());
}

TEST(HEAD_TAIL_TEST, type_list_head_tail_test) {
    EXPECT_TRUE(type_list_head_tail());
}

TEST(CONCAT_TEST, type_list_concat_test) {
    EXPECT_TRUE(type_list_concat());
}
