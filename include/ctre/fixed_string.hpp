#ifndef CTRE_V2__CTRE__FIXED_STRING__HPP
#define CTRE_V2__CTRE__FIXED_STRING__HPP

#include <utility>

namespace ctre {

template <typename CharT, size_t N> class basic_fixed_string {
	CharT content[N];
public: 
	using char_type = CharT;
	
	template <size_t... I> constexpr basic_fixed_string(const CharT (&input)[N], std::index_sequence<I...>) noexcept: content{input[I]...} { }
	
	constexpr basic_fixed_string(const CharT (&input)[N]) noexcept: basic_fixed_string(input, std::make_index_sequence<N>()) { }
	
	constexpr size_t size() const noexcept {
		// if it's zero terminated string (from string literal) then size N - 1
		if (content[N-1] == '\0') return N - 1;
		else return N;
	}
	constexpr CharT operator[](size_t i) const noexcept {
		return content[i];
	}
	constexpr const CharT * begin() const noexcept {
		return content;
	}
	constexpr const CharT * end() const noexcept {
		return content + size();
	}
};

template <typename CharT, size_t N> basic_fixed_string(const CharT (&)[N]) -> basic_fixed_string<CharT, N>;

} // ctre

#endif