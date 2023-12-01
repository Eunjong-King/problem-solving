import Foundation

let S = readLine()!

var arr: [String] = []

for i in 0..<S.count {
    arr.append(String(S[S.index(S.startIndex, offsetBy: i)...]))
}

arr.sort()

for a in arr {
    print(a)
}
