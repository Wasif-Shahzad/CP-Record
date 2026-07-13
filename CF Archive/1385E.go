package main

import (
	"fmt"
	"slices"
)

func solve() {
	var n, m int
	fmt.Scan(&n, &m)
	g := make([][]int, n)
	dg := make([][]int, n)
	input := make([][]int, m)
	for i := 0; i < m; i++ {
		var t, u, v int
		fmt.Scan(&t, &u, &v)
		u--
		v--
		tmp := []int{t, u, v}
		input[i] = tmp
		g[u] = append(g[u], v)
		if t == 1 {
			dg[u] = append(dg[u], v)
		}
		if t == 0 {
			g[v] = append(g[v], u)
		}
	}
	// for i := 0; i < n; i++ {
	// 	fmt.Printf("%d: ", i)
	// 	for _, j := range g[i] {
	// 		fmt.Printf("%d ", j)
	// 	}
	// 	fmt.Println()
	// }
	vis := make([]int, n)
	par := make([]int, n)
	for i := 0; i < n; i++ {
		par[i] = -1
	}
	var find_cycle func(v int) bool
	find_cycle = func(v int) bool {
		vis[v] = 1
		for _, c := range dg[v] {
			if vis[c] == 0 {
				par[c] = v
				if find_cycle(c) {
					// fmt.Println(v, c)
					return true
				}
			} else if vis[c] == 1 {
				return true
			}
		}
		vis[v] = 2
		return false
	}
	for i := 0; i < n; i++ {
		if vis[i] == 0 && find_cycle(i) {
			fmt.Println("NO")
			return
		}
	}
	var order []int
	for i := 0; i < n; i++ {
		par[i] = -1
		vis[i] = 0
	}
	var dfs func(v int)
	dfs = func(v int) {
		vis[v] = 1
		for _, c := range dg[v] {
			if vis[c] == 1 {
				continue
			}
			par[c] = v
			dfs(c)
		}
		order = append(order, v)
	}
	for i := 0; i < n; i++ {
		if vis[i] == 0 {
			dfs(i)
		}
	}
	for i := 0; i < n; i++ {
		vis[i] = 0
	}
	slices.Reverse(order)
	pos := make([]int, n)
	for i, v := range order {
		// fmt.Printf("%d ", v)
		pos[v] = i
	}
	fmt.Println("YES")
	for _, tmp := range input {
		_, u, v := tmp[0], tmp[1], tmp[2]
		if pos[u] > pos[v] {
			fmt.Println(v+1, u+1)
		} else {
			fmt.Println(u+1, v+1)
		}
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solve()
	}
}
