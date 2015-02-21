#include <iterator>
#include <algorithm>

class MergeSort {
 public:
	template<typename It, typename BinaryComp>
	MergeSort(It first, It last, BinaryComp cmp) {
		if (distance(first, last) <= 1) return;
		auto pivot = first + std::distance(first, last) / 2;
		MergeSort{first, pivot, cmp};
		MergeSort{pivot, last, cmp};
		std::inplace_merge(first, pivot, last, cmp);
	}
};
int main() {return 0;}
