func isPalindrom(str: [Character]) -> Bool {
    var result = true
    
    for i in 0..<(str.count/2) {
        if str[i] != str[str.count-1-i] {
            result = false
            
            break
        }
    }
    
    return result
}

let input: [Character] = Array(readLine()!)
var l = 0

for i in 0..<input.count {
    if isPalindrom(str: Array(input[i...])) {
        l = i
        break
    }
}

print(2*l + input.count-l)
