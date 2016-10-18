#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <queue>
/*online quick selection algorithm implementation*/
template <typename It, typename Cmp, typename Order>
auto quickselect(It b, It e, Cmp cmp, Order k) {
	using ValT = std::remove_reference_t<decltype(*b)>;
	std::priority_queue<ValT, std::vector<ValT>, Cmp> heap(b,b+k+1,cmp);
	for (auto i = b+k+1; i < e; ++i) {
		if (cmp(*i,heap.top())) {
			heap.pop();
			heap.push(*i);
		}
	}
	return heap.top();
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
	auto med = quickselect(begin(v1),end(v1),cmp,k);
	std::cout << "Start validating" << std::endl;
	std::nth_element(begin(v1),begin(v1)+k,end(v1),cmp);
	bool valid = true;
	if (v1[k] != med) valid = false;
	if (valid) std::cout << "Correct" << std::endl;
	else std::cout << "Incorrect" << std::endl;
	return 0;
}
#endif
