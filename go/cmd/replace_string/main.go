package main

import (
	"fmt"
	"strings"
)

func replaceString(str, oldWord, replaceWith *string, num int) {
	newStr := strings.Replace(*str, *oldWord, *replaceWith, num)
	// fmt.Println("new string: ", newStr)
	*str = newStr
}

func main() {
	str1 := "thisthiscardogwaterfooboonotatallbigbitthischcommonnotespenpencilhoteltimeluckhardworketcnotatallthis"
	oldWord := "this"
	replaceWith := ""
	replaceString(&str1, &oldWord, &replaceWith, -1)

	fmt.Println(str1)
}
