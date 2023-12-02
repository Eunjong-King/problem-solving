import Foundation

let input = readLine()!.map{ $0 }

var s: Set<String> = []

for i in 0..<input.count {
    var temp: String = ""
    for j in i..<input.count {
        temp += String(input[j])
        s.insert(temp)
    }
}

print(s.count)
