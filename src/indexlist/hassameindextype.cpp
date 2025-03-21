module;
#include<type_traits>

export module spr:has_same_index_type;

import :isempty;
import :head;

namespace spr{

export
template<
    typename left,
    typename right,
    bool = is_empty_v<left>,
    bool = is_empty_v<right>
    >
struct has_same_index_type;

export template<
    typename left,
    typename right>
constexpr bool has_same_index_type_v =  
    has_same_index_type<left, right>::value;

template<typename left,typename right>
struct has_same_index_type<left, right, false, false> 
    : std::is_same<
        decltype(head_v<left>),
        decltype(head_v<right>)>{
};

template<
    typename left,
    typename right,
    bool is_left_empty,
    bool is_right_empty>
struct has_same_index_type : std::true_type{}; 

}
