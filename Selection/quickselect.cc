#include <iostream>
#include <random>
#include <vector>
template <typename It, typename Cmp>
void quickselect(It b, It e, Cmp cmp, unsigned k) {
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
	if (j-b == k) return;
	if (j-b > k) quickselect(b,j,cmp, k);
	else quickselect(j+1,e,cmp,k-(j-b)-1);
}

#if 1
int main() {
	std::random_device rd;
	auto cnt = rd()%(1<<25);
	auto i = cnt;
	auto k = cnt >> 1;
	auto cmp = [](auto& x, auto& y){return x < y;};
	std::cout << "Generate Test Array[" << cnt << "]"<<std::endl;
	auto v1 = std::vector<decltype(cnt)>(cnt,0);
	for (i = 0; i < cnt; ++i) v1[i] = rd();
	std::cout << "Start Select" << std::endl;
	quickselect(begin(v1),end(v1),cmp,k);
	auto med = v1[k];
	std::cout << "Start validating" << std::endl;
	std::sort(begin(v1),end(v1),cmp);
	bool valid = true;
	if (v1[k] != med) valid = false;
	if (valid) std::cout << "Correct" << std::endl;
	else std::cout << "Incorrect" << std::endl;
	return 0;
}
#endif
