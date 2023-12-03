import Foundation

func isOkay(a: [Int]) -> Bool {
    var okay = true
    
    for i in 0...3 {
        if a[i] > 0 {
            okay = false
            
            break
        }
    }
    
    return okay
}

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0], M = input[1]

let originStr: [Character] = Array(readLine()!)
var ACGT = readLine()!.split(separator: " ").map{ Int($0)! }
let dict: [Character:Int] = ["A": 0, "C": 1, "G": 2, "T": 3]

for i in 0..<M {
    ACGT[dict[originStr[i]]!] -= 1
}

var result = 0

if isOkay(a: ACGT) {
    result += 1
}

for i in M..<N {
    ACGT[dict[originStr[i]]!] -= 1
    ACGT[dict[originStr[i-M]]!] += 1
    
    if isOkay(a: ACGT) {
        result += 1
    }
}

print(result)
