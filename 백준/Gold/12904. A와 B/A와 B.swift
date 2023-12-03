import Foundation

var S: [Character] = Array(readLine()!)
var T: [Character] = Array(readLine()!)

while T.count > S.count {
    if T.last == "A" {
        T.removeLast()
    } else {
        T.removeLast()
        T.reverse()
    }
}

if T == S {
    print(1)
} else {
    print(0)
}
