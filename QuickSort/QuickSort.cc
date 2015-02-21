#include <iterator>
#include <algorithm>
class QuickSort {
template<typename It, typename BinaryComp>
	void partition(const It& first, const It& last, const BinaryComp& cmp) {
		if (first == last) return;
		auto l = first, r = last;
		auto pivot = *(first + std::distance(first, last) / 2);
		while (true) {
			while (l != r && cmp(*l, pivot)) ++l;
			if (l == r) break;
			while (l != r && cmp(pivot, *r)) --r;
			if (r == l) break;
			std::iter_swap(l, r);
		}
		if (std::distance(first, l) != 0)
			partition(first, l - 1, cmp);
		if (std::distance(r, last) != 0)
			partition(r + 1, last, cmp);
	}
 public:
template<typename It, typename BinaryComp>
	QuickSort(const It& first, const It& last, const BinaryComp& cmp) {
		if (first == last) return;
		partition(first, last - 1, cmp);
	}
};

int main() {return 0;}
