package main

import (
	"fmt"
)

// Simple ASCII-only (not Unicode-safe)
func reverseASCII(str *string) {
	rs := []byte(*str)
	fmt.Printf("this is initall rs: %s\n", rs)

	for i, j := 0, len(*str)-1; i < j; i, j = i+1, j-1 {
		rs[i], rs[j] = rs[j], rs[i]
	}

	*str = string(rs)
}

// Proper Unicode-safe reversal (recommended)
func reverseUnicode(str *string) {
	runes := []rune(*str) // convert to runes (Unicode code points)
	fmt.Printf("this is initall runes: %s\n", runes)

	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	*str = string(runes)
}

func main() {
	str1 := "this is a demo string value"
	// reverseASCII(&str1)
	reverseUnicode(&str1)

	fmt.Println(str1)
}
