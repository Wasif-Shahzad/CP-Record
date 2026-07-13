package main

import (
	"fmt"
	"math/rand/v2"
)

var m1 int = int(1e9 + 7)
var m2 int = int(1e9 + 9)
var base int = rand.IntN(10000) + 90

type Pair[T1 any, T2 any] struct {
	First  T1
	Second T2
}

var pow = make([]Pair[int, int], 1e6+1)

type Hash struct {
	pref []Pair[int, int]
}

func (h *Hash) init(s string) {
	n := len(s)
	h.pref = make([]Pair[int, int], len(s)+1)

	h.pref[0] = Pair[int, int]{0, 0}
	for i := 0; i < n; i++ {
		h1 := ((h.pref[i].First*base)%m1 + int(s[i]-'0')) % m1
		h2 := ((h.pref[i].Second*base)%m2 + int(s[i]-'0')) % m2
		h.pref[i+1] = Pair[int, int]{h1, h2}
	}
}

func (h *Hash) getHash(l int, r int) Pair[int, int] {
	v1 := (h.pref[r+1].First - (h.pref[l].First * pow[r-l+1].First))
	v2 := (h.pref[r+1].Second - (h.pref[l].Second * pow[r-l+1].Second))
	return Pair[int, int]{(v1%m1 + m1) % m1, (v2%m2 + m2) % m2}
}

func (h *Hash) addChar(prevLen int, newChar byte) {
	h1 := ((h.pref[prevLen].First*base)%m1 + int(newChar-'0')) % m1
	h2 := ((h.pref[prevLen].Second*base)%m2 + int(newChar-'0')) % m2
	h.pref = append(h.pref, Pair[int, int]{h1, h2})
}

func main() {
	cur1 := 1
	cur2 := 1
	for i := 0; i < 1e6; i++ {
		thisPair := Pair[int, int]{First: cur1, Second: cur2}
		pow[i] = thisPair
		cur1 = (cur1 * base) % m1
		cur2 = (cur2 * base) % m2
	}
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	hashes := make([]Hash, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		hashes[i].init(a[i])
	}
	ans := []byte(a[0])
	var hash Hash
	hash.init(string(ans))
	for i := 1; i < n; i++ {
		if string(ans) == a[i] {
			continue
		} else {
			l := 0
			for j := 1; j <= min(len(a[i]), len(ans)); j++ {
				ourHash := hash.getHash(len(ans)-j, len(ans)-1)
				theirHash := hashes[i].getHash(0, j-1)
				if ourHash == theirHash {
					l = j
				}
			}
			// if i == 1 {
			// 	fmt.Println(l)
			// }
			for j := l; j < len(a[i]); j++ {
				hash.addChar(len(ans), a[i][j])
				ans = append(ans, a[i][j])
			}
		}
	}
	fmt.Println(string(ans))
}
