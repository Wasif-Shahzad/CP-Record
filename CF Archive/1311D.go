package main

import "fmt"

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func solve() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	var x, y, z int
	ans := int(1e8)
	for i := 1; i < 2*a; i++ {
		for j := i; j < 2*b; j += i {
			cost := abs(i-a) + abs(j-b)
			better := min(c-c/j*j, (c/j+1)*j-c)
			var k int
			if c-c/j*j == better {
				k = c / j * j
			} else {
				k = (c/j + 1) * j
			}
			cost += better
			if cost < ans {
				ans = cost
				x, y, z = i, j, k
			}
		}
	}
	fmt.Println(ans)
	fmt.Printf("%d %d %d\n", x, y, z)
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}
}
