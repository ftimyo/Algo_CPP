#include <iostream>
#include <vector>
#include <random>

template<typename It, typename Cmp>
void quicksort(It b, It e, Cmp cmp) {
	if (e < b+1) return;
	auto i = b, j = e;
	auto p = *i;
	while (i < j) {
		while (cmp(*++i ,p) && i < e);
		while (cmp(p, *--j) && b < j);
		if (i < j) std::swap(*i,*j);
		else break;
	}
	std::swap(*j,*b);
	quicksort(b,j,cmp);
	quicksort(j+1,e,cmp);
}

#if 1
int main() {
	std::random_device rd;
	auto cnt = rd()%(1<<25);
	auto i = cnt;
	std::cout << "Generate Test Array[" << cnt << "]"<<std::endl;
	auto v1 = std::vector<decltype(cnt)>(cnt,0);
	for (i = 0; i < cnt; ++i) v1[i] = rd();
	std::cout << "Start Sorting" << std::endl;
	auto cmp = [](auto& x, auto& y){return x < y;};
	quicksort(begin(v1),end(v1),cmp);
	std::cout << "Start validating" << std::endl;
	bool valid = true;
	if (!std::is_sorted(begin(v1),end(v1),cmp)) valid = false;
	if (valid) std::cout << "Correct" << std::endl;
	else std::cout << "Incorrect" << std::endl;
	return 0;
}
#endif
