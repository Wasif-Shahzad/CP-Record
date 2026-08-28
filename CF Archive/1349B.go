package main

import "fmt"

func solve() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	var found bool
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		if a[i] == k {
			found = true
		}
	}
	if !found {
		fmt.Println("No")
		return
	}
	if n == 1 {
		fmt.Println("Yes")
		return
	}
	for i := 0; i < n; i++ {
		for j := i + 1; j <= min(i+2, n-1); j++ {
			if a[i] >= k && a[j] >= k {
				fmt.Println("Yes")
				return
			}
		}
	}
	fmt.Println("No")
}

func main() {
	// we want a subarray where median is k
	// exactly k! checking for a subarray with median >= k is easy
	// this means there has to be an intersection of elements >= k and elements <= k
	// and that intersections needs to fall in the median spot
	// let x be elems >= k and y elems <= k
	// z be elems == k
	// x >= len / 2 + 1, y >= (len + 1) / 2
	// pref1[r] - pref1[l - 1] >=(r - l + 1) / 2 + 1 => 2 * pref[r] - r >= 2 * pref[l - 1] - l + 2
	// pref2[r] - pref2[l - 1] >= (r - l + 2) / 2
	// pref2[r] - pref2[l - 1] >= (r - l + 1) / 2
	// 2 * pref2[r] - r - 1 >= 2 * pref2[l - 1] - l
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}
}
