/*
 * Sort.h
 *
 *  Created on: 8 Aug 2022
 *      Author: aedas
 */
#include <vector>

#ifndef SORT_H_
#define SORT_H_

template <class T>
class Sort {
public:
	Sort<T>() {};
	virtual ~Sort<T>() {};
	static std::vector<T> MergeSort(std::vector<T> input, int (*comparer) (T, T)) {
		if (input.size() < 2) {
			return input;
		}
		std::vector<T> lst1, lst2, sort1, sort2, ans;
		lst1 = {};
		lst2 = {};
		for (int i = 0; i < input.size()/2; i++) {
			lst1.push_back(input[i]);
		}
		for (int i = input.size()/2; i < input.size(); i++) {
				lst2.push_back(input[i]);
		}
		sort1 = Sort<T>::MergeSort(lst1, comparer);
		sort2 = Sort<T>::MergeSort(lst2, comparer);
		ans = Sort<T>::Merge(sort1, sort2, comparer);
		//lst1.clear();
		//lst2.clear();
		//lst1.shrink_to_fit();
		//lst2.shrink_to_fit();
		return ans;
	}
private:
	static std::vector<T> Merge(std::vector<T> lst1, std::vector<T> lst2, int (*comparer) (T, T))  {
		std::vector<T> ans = {};
		int i1 = 0;
		int i2 = 0;
		while (i1 < lst1.size() && i2 < lst2.size()) {
			T elem1 = lst1[i1];
			T elem2 = lst2[i2];
			if (comparer(elem1, elem2) >= 0) {
				ans.push_back(elem1);
				i1++;
			}
			if (comparer(elem1, elem2) <= 0){
				ans.push_back(elem2);
				i2++;
			}
		}
		while (i1 < lst1.size()) {
			ans.push_back(lst1[i1]);
			i1++;
		}
		while (i2 < lst2.size()) {
			ans.push_back(lst2[i2]);
			i2++;
		}
		//lst1.clear();
		//lst2.clear();
		//lst1.shrink_to_fit();
		//lst2.shrink_to_fit();
		return ans;
	}
};

#endif /* SORT_H_ */
