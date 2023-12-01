import Foundation

var input = Array(readLine()!).sorted(by: >)

let sum = input.reduce(0) { $0 + Int(String($1))! }

if input.last != "0" || sum % 3 != 0 {
    print(-1)
} else {
    input.sort()
    input.reverse()
    
    print(String(input))
}
