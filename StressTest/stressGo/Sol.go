package main

import "fmt"

type SegTree struct {
	n    int
	tree []int
}

func (self *SegTree) init(n int) {
	size := 1
	for size <= n {
		size *= 2
	}
	self.n = size
	self.tree = make([]int, 2*self.n)

	for i := 0; i < 2*self.n; i++ {
		self.tree[i] = 1e14
	}
}

func (self *SegTree) update(i int, v int) {
	var f func(l int, r int, x int)
	f = func(l int, r int, x int) {
		if r-l == 1 {
			self.tree[x] = v
			return
		}
		m := (l + r) / 2
		if i < m {
			f(l, m, 2*x)
		} else {
			f(m, r, 2*x+1)
		}
		self.tree[x] = min(self.tree[2*x], self.tree[2*x+1])
	}
	f(0, self.n, 1)
}

func (self *SegTree) query(l int, r int) int {
	var f func(lx int, rx int, x int) int
	f = func(lx int, rx int, x int) int {
		if lx >= l && rx <= r {
			return self.tree[x]
		}
		if lx >= r || rx <= l {
			return 1e14
		}
		m := (lx + rx) / 2
		left := f(lx, m, 2*x)
		right := f(m, rx, 2*x+1)
		return min(left, right)
	}
	return f(0, self.n, 1)
}

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
	if n == 1 && a[0] == k {
		fmt.Println("Yes")
		return
	}
	var seggy SegTree
	seggy.init(8*n + 5)
	K := 3 * n
	pref1 := make([]int, n+1)
	pref2 := make([]int, n+1)
	pref1[0] = K
	pref2[0] = K
	found = false
	for i := 1; i <= n; i++ {
		pref1[i] = pref1[i-1]
		if a[i-1] >= k {
			pref1[i]++
		}
		pref2[i] = pref2[i-1]
		if a[i-1] <= k {
			pref2[i]++
		}
		if i > 1 {
			j := 2*pref1[i-2] - (i - 1) + 2
			v := min(seggy.query(j, j+1), 2*pref2[i-2]-(i-1))
			seggy.update(j, v)
		}
		bst := seggy.query(0, 2*pref1[i]-i+1)
		if bst <= 2*pref2[i]-i-1 {
			found = true
			break
		}
	}
	if found {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
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
