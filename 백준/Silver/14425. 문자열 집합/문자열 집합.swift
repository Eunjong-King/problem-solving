import Foundation

let input = readLine()!.split(separator: " ").map({
    Int(String($0))!
})

let N = input[0], M = input[1]

var m: Set<String> = []

for _ in 0..<N {
    m.insert(readLine()!)
}

var count = 0

for _ in 0..<M {
    if m.contains(readLine()!) {
        count += 1
    }
}

print(count)
