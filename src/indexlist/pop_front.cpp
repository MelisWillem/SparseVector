export module spr:pop_front;

export import :indexlist;

namespace spr{

template<typename List>
struct pop_front;

template<auto head, auto... elements>
struct pop_front<Indexlist<head, elements...>>
{
    using Type = Indexlist<elements...>;
};

export template<typename List>
using pop_front_t = typename pop_front<List>::Type;

}
