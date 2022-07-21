type pair struct {
    value int
    idx int
}

func twoSum(nums []int, target int) []int {
    items := []pair{}
    for i := 0; i < len(nums); i++ {
        items = append(items, pair{value: nums[i], idx: i})
    }
    
    sort.Slice(items, func(i, j int) bool {
        return items[i].value < items[j].value
    })
    
    l, r := 0, len(items) - 1
    for l < r {
        if items[l].value + items[r].value == target {
            return []int{items[l].idx, items[r].idx}
        }
        
        if items[l].value + items[r].value > target {
            r -= 1
        } else {
            l += 1
        }
    }
    
    return []int{-1, -1}
}
