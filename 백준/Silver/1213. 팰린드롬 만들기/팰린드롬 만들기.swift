import Foundation

let input = readLine()!.map{ $0 }
var charCount = Array(repeating: 0, count: 26)

for c in input {
    charCount[Int(c.asciiValue!)-65] += 1
}

var oddCount = 0
var oddAscii: Int = 0

for i in 0..<26 {
    if charCount[i] % 2 == 1 {
        oddCount += 1
        oddAscii = i + 65
    }
}

if oddCount >= 2 {
    print("I'm Sorry Hansoo")
} else {
    var temp: String = ""
    var result: String = ""
    
    for i in 0...25 {
        temp += String(repeating: String(UnicodeScalar(i+65)!), count: charCount[i]/2)
    }
    
    result += temp + (oddAscii != 0 ? String(UnicodeScalar(oddAscii)!) : "") + temp.reversed()
    
    print(result)
}

