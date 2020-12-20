func countConsistentStrings(allowed string, words []string) int {
    good := make(map[string]bool)
    for _, ch := range allowed {
        good[string(ch)] = true
    }
    
    ok := func(word string) bool {
        for _, ch := range word {
            if _, ok := good[string(ch)]; !ok {
                return false
            }
        }
        return true
    }
    
    ans := 0
    for _, word := range words {
        if ok(word) {
            ans ++
        }
    }
    
    return ans
}
